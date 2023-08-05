t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    a1 = a*b
    a2 = c*d
    if a1 > a2:
        print("TelecomParisTech")
    elif a1 < a2:
        print("Eurecom")
    else:
        print("Tie")