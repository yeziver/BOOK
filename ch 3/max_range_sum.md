## Max 1D Range Sum
This algorithm keeps a running sum of the integers seen so far and greedily rests to 0 if the running sum dips below 0.

```
int sum = 0, ans = 0;
for (int i = 0; i < n; ++i) {
  sum += A[i];
  ans = max(ans, sum);
  if (sum < 0) sum = 0;
}
```

## Max 2D Range Sum
### Method 1; Brute Force
```
int n;
int maxSubRect = -127*100*100;
for (int i = 0; i < n; ++i) { //starting indices
  for (int j = 0; j < n; ++j) { //top left corner
    for (int k = i; k < n; ++k) { //ending indices
      for (int l = j; l < n; ++l) { //bottom right corner
        int subRect = 0;
        for (int a = i; a <= k; ++a) { //iterate through submatrix determined by ijkl
          for (int b = j; b <= l; ++b) {
            subRect += A[a][b];
          }
        }
        maxSubRect = max(maxSubRect, subRect);
      }
    }
  }
}
```

### Method 2; Cumulative Sum Matrix
A[i][j] contains the sum of all items within the sub-matrix (0, 0) to (i, j)

```
int n;
for (int i = 0; i < n; ++i) {
  for (int j = 0; j < n; ++j) {
    //read in input
    if (i > 0) A[i][j] += A[i-1][j]; //adds the cumulative sum of the submatrix above the current element
    if (j > 0) A[i][j] += A[i][j-1]; //adds the cumulative sum of the submatrix to the left of the current element
    if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1]; //subtracts the cumulative sum of the overlapping submatrix (top-left corner)
    //necessary because both the cumulative sums of the submatrix above (i, j) and the submatrix to the left of (i, j) contain the cumulative sum of the submatrix with the top-left corner at (i-1, j-1)
    //a bit like bottom up dp, it builds the cumulative sum matrix with past ones
  }
}

int maxSubRect = -127*100*100;
for (int i = 0; i < n; ++i) { //i & j are top left corner
  for (int j = 0; j < n; ++j) {
    for (int k = i; k < n; ++k) { //k & j are bottom right corner
      for (int l = j; l < n; ++l) {
        int subRect = A[k][l];
        if (i > 0) subRect -= A[i-1][l];
        if (j > 0) subRect -= A[k][j-1];
        if (i > 0 && j > 0) subRect += A[i-1][j-1];
        maxSubRect = max(maxSubRect, subRect);
      }
    }
  }
}
```

### Method 3: Restarting at 0
```
int n;
for (int i = 0; i < n; ++i) {
  for (int j = 0; j < n; ++j) {
    //read input
  if (j > 0) A[i][j] += A[i][j-1];
  }
}

int maxSubRect = -127*100*100;
for (int l = 0; l < n; ++l) { //leftmost column of submatrix
  for (int r = l; r < n; ++r) { //rightmost column of submatrix
    int subRect = 0;
    for (int row = 0; row < n; ++row) { //rows of submatrix
      if (l > 0) subRect += A[row][r] - A[row][l-1]; //no double counting- subtracts everything to the left of l
      else subRect += A[row][r];

      if (subRect < 0) subRect = 0;
      maxSubRect = max(maxSubRect, subRect);
    }
  }
}
