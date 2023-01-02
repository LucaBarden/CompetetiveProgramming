def perms(t, test_cases):
  results = []
  for i in range(t):
    n, k = test_cases[i]
    permutation = []
    for j in range(n, 0, -1):
      permutation.append(j)
    results.append(permutation)
  return results

while(t):
	(n,k) = [int(item) for item in input().split()]
	print(perms(n,k))
	t-=1
