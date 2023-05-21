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
