def max_sum(a,b):
	sum = 0
	for i in range(len(b)):
		min_index = a.index(min(a))
		a[min_index] = b[i]
	for i in a:
		sum += i
	return sum

def solve():
	(n,m) = [int(item) for item in input().split()]

	a = []
	b = []

	aInput = input().split()

	for item in aInput:
		a.append(int(item))

	bInput = input().split()

	for item in bInput:
		b.append(int(item))

	print(max_sum(a,b))

t = int(input())
while(t):
	solve()
	t -= 1


