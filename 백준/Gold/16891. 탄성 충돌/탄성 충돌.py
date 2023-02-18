from fractions import Fraction

n = int(input())

m1 = 1
m2 = n**2
v1 = 0
v2 = -1

ans = 0

while abs(v1) > v2:
    #print("v1={}, v2={}".format(v1, v2))
    #n = input()
    tv1 = abs(v1)
    tv2 = v2

    v1 = Fraction(m1-m2, m1+m2) * tv1 + Fraction(2*m2, m1+m2) * tv2
    v2 = Fraction(2*m1, m1+m2) * tv1 - Fraction(m1-m2, m1+m2) * tv2
    ans += 2

if v1 >= 0:
    ans -= 1

print(ans)