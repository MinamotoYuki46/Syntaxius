import math

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


if __name__ == "__main__":
    print(primeFactor(600851475143))
