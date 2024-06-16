import math

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    
    for l in range(n, m + 1):  
        if l > 1:
            flag = True
            for ii in range(2, int(math.sqrt(l)) + 1):  
                if l % ii == 0:
                    flag = False
                    break
            if flag:
                print(l, end=" ")
    print()  