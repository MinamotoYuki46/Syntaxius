if __name__ == '__main__':
    res = list(str(2 ** 1_000))

    print(sum(int(i) for i in res))
    # print(res)