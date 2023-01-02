def is_good_array(a, x, y):
    if sum(a) != x:
        return False
    result = a[0]
    for i in range(1, len(a)):
        result |= a[i]
    if result != y:
        return False
    return True


def find_good_arrays(n, x, y, total_xor=0):
    # Base case: if n is 0, return the total XOR
    if n == 0:
        return total_xor
    
    # Generate all possible arrays of length n
    for i in range(n + 1):
        # Recursively find good arrays of length n - 1
        a = [i] + [0] * (n - 1)
        if is_good_array(a, x, y):
            # If the array is a good array, add its score to the total XOR
            total_xor ^= i
        total_xor = find_good_arrays(n - 1, x - i, y, total_xor)
    
    return total_xor

n,x,y = [int(i) for i in input().split()]
print(find_good_arrays(n,x,y))