def collatz(num: int) -> int:
    i = 1
    while num != 1:
        if num % 2 == 0:
            num //= 2
        else:
            num = 3 * num + 1
        i += 1
    return i

if __name__ == '__main__':
    longest = 0
    num_with_longest = 0

    for i in range(1, 1_000_000):
        length = collatz(i)
        if length > longest:
            longest = length
            num_with_longest = i

    print(num_with_longest, longest)
