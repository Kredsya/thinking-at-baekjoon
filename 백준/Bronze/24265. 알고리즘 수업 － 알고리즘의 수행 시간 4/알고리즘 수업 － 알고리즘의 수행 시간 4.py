n=int(input())
if n&1:
    n = n*(n//2)
else:
    n = (n-1)*(n//2)
print(n,2)