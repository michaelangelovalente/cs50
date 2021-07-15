
while True:
    print("Height: ", end="")
    n = input()
    try:
       x = int(n)
    except ValueError:
        continue

    if int(n) >= 1 and int(n) <= 8:
        break



for i in range(int(n)):
    print(" " * (int(n)-i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#"*( i + 1))
