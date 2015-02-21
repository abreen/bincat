for i in range(2**8):
    s = bin(i)[2:]

    print((8 - len(s)) * '0' + s)
