def prime_generator():
    yield 2
    n = 3
    while True:
        is_prime = True
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                is_prime = False
                break
        if is_prime:
            yield n
        n += 2  

if __name__ == "__main__":
    gen = prime_generator()
    prime = None
    for i in range(10_001):
        prime = next(gen)
    
    print(prime)
