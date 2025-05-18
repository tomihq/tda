def parejas_baile(c1, c2): 
    c1 = sorted(c1)
    c2 = sorted(c2)
    i = 0; 
    j = 0; 
    counter = 0; 

    while(i < len(c1) and j < len(c2)):
        sub = abs(c1[i] - c2[j]);
        if(sub <= 1):
            counter+=1;
            i+=1;
            j+=1
        elif(c1[i] > c2[j]):
            j+=1;
        else:
            i+=1;
    
    return counter 

print(parejas_baile([5], [1, 4])) #1
print(parejas_baile([1, 4], [5])) #1
print(parejas_baile([1, 2, 3], [2, 3, 4])) #3
print(parejas_baile([1, 2, 3], [2, 5, 3, 4])) #3