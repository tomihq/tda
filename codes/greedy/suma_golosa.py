def suma_golosa(c):
    c = sorted(c);
    bestCost = 0; 

    while len(c) > 1:
        a = c.pop(0)
        b = c.pop(0)
        cost = a + b
        bestCost += cost
        c.append(cost)
        c.sort() 

    return bestCost

print(suma_golosa([5, 1, 2])) #11
print(suma_golosa([100, 900, 90, 4, 2, 50, 1])) # 1 + 2 = 3 + 4 = 7 + 50 = 57 + 90 = 147 + 100 = 247 + 900 = 1147
