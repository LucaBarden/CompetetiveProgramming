n = int(input())
arr = list(map(int, input().split()))

one_count = [0]
i = 0
total_one = 0
while i < n:
    if arr[i] == 1:
        total_one += 1
    one_count.append(total_one)
    i += 1

mx_one = 0
i = 1

while i <= n:
    j = i
    
    while j <= n:
        zero_count = j - (i - 1) - (one_count[j] - one_count[i-1])
        mx_one = max([mx_one, zero_count + one_count[n]-one_count[j] + one_count[i-1] - one_count[0]])
        j += 1
    
    i += 1
    
print(mx_one)