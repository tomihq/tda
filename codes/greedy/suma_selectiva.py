import heapq

def suma_selectiva(c, k):
    h = []  
    i = 0   

    while i < len(c):
        if len(h) < k:
            heapq.heappush(h, c[i])  
        elif c[i] > h[0]:  
            heapq.heappop(h) 
            heapq.heappush(h, c[i])  
        i += 1  

    bestSum = sum(h)  
    return bestSum, list(h)  

print(suma_selectiva([5, 4, 3, 1, 2], 3))  # (12, [3, 4, 5])
print(suma_selectiva([100, 5, 4, 150, 3000], 2))  # (3150, [150, 3000])
print(suma_selectiva([1000, 5000, 1500, 3000], 3))  # (9500, [1500, 3000, 5000])


