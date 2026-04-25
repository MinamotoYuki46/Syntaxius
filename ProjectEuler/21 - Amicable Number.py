def d(n: int):
    return sum(x for x in range(1, n // 2 + 1) if not (n % x))




if __name__ == "__main__":
    sets = set()
    for i in range(1, 10_000):
        m = d(i)
        n = d(m)

        if (i == n) and (m != n):
            sets.add(m)

    print(sum(sets))
