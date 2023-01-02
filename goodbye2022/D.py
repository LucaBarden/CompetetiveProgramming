from typing import List, Tuple

def count_winning_arrays(test_cases: List[Tuple[int, List[int], List[int]]]) -> int:
    MOD = 998244353

    def is_winning_array(n: int, a: List[int], b: List[int]) -> int:
        dp = [[0] * n for _ in range(n)]
        dp[0][a[0]-1] = 1
        for i in range(1, n):
            for j in range(n):
                dp[i][j] = sum(dp[i-1][k] for k in range(j+1, n) if k != a[i-1] and k != b[i-1]) % MOD
        return sum(dp[n-1]) % MOD

    # Iterate through all test cases and return the number of winning arrays
    count = 0
    print(test_cases)
    n, a, b = test_cases
    print(n,a,b)
    count = (count + is_winning_array(n, a, b)) % MOD
    return count

t = int(input())

while t:
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    print(count_winning_arrays(list((n, a, b))))