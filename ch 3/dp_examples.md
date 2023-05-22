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

### Knapsack (Subset Sum)
Given n items, each with its own value Vi and weight Wi, and a maximum knapsack size S, compute the maximum value of the items that we can carry, if we can either ignore or take a particular item.

Solution:
  1. If the remaining weight is 0, we cannot take anything else
  2. If the index is n, we have considered all items
  3. If W[index] > remaining weight, we must ignore this item
  4. If W[index] <= remaining weight, we can either ignore or take the item; we take the maximum of this; max(val(id+1, remW), V[id] + val(id+1, remW-W[id]))
 
 
### Coin Change
Given a target amount V cents and a list of denominations for n coins, we have coinValue[i] (in cents) for coin types i, what is the minimum number of coins that we must use to represent V ?

Solution:
  1. If the remaining amount of cents is 0, we need 0 coins to produce 0 cents
  2. If the remaining amount of cents is less than zero, we can return a dummy value
  3. If the value is valid, return the minimum of all possibilities; change(value - coinValue[i])

### How do you add?
Given an integer n, how many ways can K non-negative integers less than or equal to n add up to n?

Solution:
  1. Base case: when K = 1. No matter what, there is one way to add exactly one number less than equal or n to get n: use n itself. 
  2. The subproblem is (n - X, K-1). n-X is the remaining sum to be achieved, and K-1 is the amount of non-negative integers remaining to be added.
