def prime_generator(n:int):
    primes = []
    for num in range(2, n + 1):
        is_prime = True
        for p in primes:
            if p * p > num:
                break
            if num % p == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(num)
    return primes

if __name__ == "__main__":
    print(sum(prime_generator(2_000_000)))