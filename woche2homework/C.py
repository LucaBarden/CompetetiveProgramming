# Amity Assessment
a = []
for _ in range(2):
    a.append(input())
b = []
for _ in range(2):
    b.append(input())
x = (a[0]+a[1][::-1]).replace("X","")
y = (b[0]+b[1][::-1]).replace("X","")

friends = False
for i in range(3):
    if(y in x):
        friends = True
        break
    x = x[1:] + x[:1]
if(friends):
    print("YES")
else:
    print("NO")