for _ in range(int(input())):
    a, b = input().split()
    x, b = len(b), ' '+b
    for i in a[::-1]:
        if i == b[x]: x -= 1
        elif i in b[:x]: break
    else:
        if b[x] == ' ': print('YES'); continue
    print('NO')