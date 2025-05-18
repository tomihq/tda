def suma_golosa(c):
    c = sorted(c);
    i = 1; 
    bestCost = 0; 

    while(i < len(c)):
        if(i == 1):
            bestCost = c[i] + c[i-1];
        else: 
            bestCost += bestCost + c[i];
        
        i+=1;

    return bestCost

print(suma_golosa([5, 1, 2])) #11

