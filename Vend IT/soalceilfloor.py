import math as m

n = input()
n = int(n)
num = [0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]

for i in num:
    if (i == m.log2(n)):
        print("Ya")
        break


if (i != m.log2(n)):
        print("Bukan")
         
