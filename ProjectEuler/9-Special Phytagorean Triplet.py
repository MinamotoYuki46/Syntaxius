def is_pythagorean_triplet(a: int, b: int, c: int) -> bool:
    return a ** 2 + b ** 2 == c ** 2

if __name__ == "__main__":
    for a in range(1, 1000):
        for b in range(a + 1, 1000 - a):
            c = 1000 - a - b
            if c > b and is_pythagorean_triplet(a, b, c):
                print(a * b * c)
                exit()