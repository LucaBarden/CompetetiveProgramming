from itertools import permutations
 
I = lambda row: map(int, row.split())
p1 = tuple(I(input()))
p2 = tuple(I(input()))
p3 = tuple(I(input()))
 
def ss(p1, p2, p3):
    return (0, [p1, p2, p3])[p1 <= p2 <= p3]
 
Yias = []
for xxx in permutations([p1[1], p2[1], p3[1]]):
    tmp = ss(*xxx)
    if tmp:
        Yias = tmp
 
Pias = [p1, p2, p3]
Pias.sort()
 
r1 = ''
r2 = ''
r3 = ''
 
if Pias[0][1] == Pias[1][1] == Pias[2][1]:
    print(1)
    print(Pias[0][0], Pias[0][1], Pias[2][0], Pias[2][1])
else:
    l1 = [[Pias[1][0], Yias[0]], [Pias[1][0], Yias[2]]]
    l2 = [[Pias[0][0], Pias[0][1]], [Pias[1][0], Pias[0][1]]]
    l3 = [[Pias[1][0], Pias[2][1]], [Pias[2][0], Pias[2][1]]]
 
    q = 0
    if l1[0] != l1[1]:
        q += 1
        r1 = '{} {} {} {}'.format(*l1[0], *l1[1])
    if l2[0] != l2[1]:
        q += 1
        r2 = '{} {} {} {}'.format(*l2[0], *l2[1])
    if l3[0] != l3[1]:
        q += 1
        r3 = '{} {} {} {}'.format(*l3[0], *l3[1])
    if l2[1] == l3[0] and l2[0] != l2[1] and l3[0] != l3[1]:
        q -= 1
        r3 = ''
        
    print(q)
    if r1:
        print(r1)
    if r2:
        print(r2)
    if r3:
        print(r3)