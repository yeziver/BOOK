### Max 1D Range Sum
Given an integer array A containing n <= 20K non-zero integers, determine the maximum 1D range sum of A. In other words, find the maximum Range Sum Query between the two indices i and j in [0...n-1]. 
```
int main(void) {
  int n = 9, A[] = {4, -5, 4, -3, 4, 4, -4, 4, -5};
  int sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
     sum += A[i];
     ans = max(ans, sum);
     if (sum < 0) sum = 0;
  }
```

### Max 2D Range Sum
Given an nxn square matrix of integers A where each integer ranges from [-127...127], find a sub-matrix of A with the maximum sum.
We can turn the n × n input matrix into an n × n cumulative sum matrix where A[i][j] no longer contains its own value, but the sum of all items within sub-matrix (0, 0) to (i, j).
```
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i > 0) A[i][j] += A[i - 1][j]; 
      if (j > 0) A[i][j] += A[i][j - 1]; 
      if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1]; // avoid double count
    }
  }
```
