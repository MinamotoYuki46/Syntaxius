from collections import Counter

def triangle_num(num: int) -> int:
    return num * (num + 1) // 2

def primeFactor(num: int) -> list[int]:
    factors = []
    i = 2
    while i * i <= num:
        while num % i == 0:
            factors.append(i)
            num //= i
        i += 1
    if num > 1:
        factors.append(num)
    return factors

def divisor(num: int) -> int:
    div = Counter(primeFactor(num))
    res = 1
    for exp in div.values():
        res *= exp + 1
    return res

if __name__ == '__main__':
    i = 1
    while True:
        tri = triangle_num(i)
        div_count = divisor(tri)
        if div_count >= 500:
            print(f"Triangle number {tri} has {div_count} divisors.")
            break
        i += 1
