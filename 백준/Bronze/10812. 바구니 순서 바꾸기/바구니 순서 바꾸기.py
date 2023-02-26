n, m = map(int, input().split())

ans = [i for i in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    ans = ans[:a] + ans[c:b+1] + ans[a:c] + ans[b+1:]

for i in ans[1:]:
    print(i, end=' ')