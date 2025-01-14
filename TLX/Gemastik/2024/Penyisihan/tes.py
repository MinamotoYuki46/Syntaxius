import math

def ncr(n, r):
    return math.comb(n, r)
ans = 0

for i in range(0, 13):
    ans += ncr(30, i)
    print(f"{i} : {ans}")

# print(1000000000)

# print(math.floor(math.log10(ans)))