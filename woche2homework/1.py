import math

n = int(input())
heights = list(map(int, input().split()))

x, y = 0, 0
_min = math.inf
for i in range(n):
    if i == n-1:
        diff = abs(heights[i] - heights[0])
        if diff < _min:
            _min = diff
            x, y = i+1, 1
    else:
        diff = abs(heights[i] - heights[i+1])
        if diff < _min:
            _min = diff
            x, y = i+1, i+2

print(x, y)