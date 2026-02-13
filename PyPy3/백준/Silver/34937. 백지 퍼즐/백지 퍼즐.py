n, m = [int(i) for i in input().split()]
print(pow(3, (n-1)*m + n*(m-1), 1000000007))