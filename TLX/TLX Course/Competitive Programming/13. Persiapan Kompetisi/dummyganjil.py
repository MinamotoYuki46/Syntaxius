if __name__ == "__main__":
    n = int(input())
    for i in range(1, n + 1):
        x = i
        while x % 2 == 0:
            x >>= 1  
        print(x, end=' ')