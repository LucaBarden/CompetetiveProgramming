def gcd(a,b):
	while b:
		a,b = b, a%b
	return a

def possible(a):
	for i in range(len(a)):
		for j in range(i+1)