import sys
input = sys.stdin.readline
 
 
def find(x): # Helper Funktion für Kruskal. Findet Parent von einem gegebenem Knoten
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]
 
 
for _ in range(int(input())):
    _ = input()
    n, m = map(int, input().split())
    g = [tuple(map(int, input().split())) for _ in range(m)]
    mask = 0
    for x in range(29, -1, -1): # Iterieren durch all bits der Edge Weights. Ganz vorne dabei anfangenden
        bit = (1 << x) | mask # Unser aktuelles Bit speichern
        parent = [i for i in range(n+1)] # Parent Array für Kruskal
        cnt = n # Anzahl der verbundenen Komponenten im Graphen
        for u, v, w in g: # Iterieren durch alle Kanten
            if (w & bit) == 0: # Schauen ob das aktuelle Bit des Gewichts 0 ist: Falls ja
                u = find(u) # Eltern finden von u und v
                v = find(v) 
                if u != v: # Prüfen ob u und v in verschiedenen verbundenen Komponenten sind: Falls ja
                    cnt -= 1 # Verbundene Komponenten mergen und anzahl der komponenten um eins verringern
                    parent[u] = v
        if cnt == 1: # Schauen ob es am ende nur noch eine komponente gibt
            mask = bit # Maximum Bitwise AND setzen
    print(((1 << 30) - 1) - mask)