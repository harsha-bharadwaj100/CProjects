for i in range(16):
    print(i, ": ", end="")
    for j in range(16):
        if i ^ j == 2:

            print(f"{i, j} ({i ^ j}) {len(str(bin(i^j))[2:].replace("0",""))}", end=" ")
    print()
