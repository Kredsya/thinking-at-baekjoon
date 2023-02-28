from fractions import Fraction

n = int(input())
x = list(map(int, input().split()))

turn = Fraction(1, 1)
for i in range(1, n):
    gap = Fraction(x[i-1], x[i])
    turn *= gap
    print(f"{turn.numerator}/{turn.denominator}")