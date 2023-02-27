def merge_sort(p, r):
    #print(f"[Debug : p={p} r={r} start]")
    if p < r:
        q = (p + r) // 2
        merge_sort(p, q)
        #print(f"[Debug : p={p} r={r} left over]")
        merge_sort(q+1, r)
        #print(f"[Debug : p={p} r={r} right over]")
        merge(p, q, r)
        #print(f"[Debug : p={p} r={r} merge over]")
    #print(f"[Debug : p={p} r={r} finish]")

def merge(p, q, r):
    tmp = [0 for _ in range(r-p+1)]
    i = p
    j = q + 1
    t = 0
    while i<=q and j<=r:
        if A[i] <= A[j]:
            tmp[t] = A[i]
            i = i + 1
        else:
            tmp[t] = A[j]
            j = j + 1
        t += 1
    while i<=q:
        tmp[t] = A[i]
        t += 1
        i += 1
    while j<=r:
        tmp[t] = A[j]
        t += 1
        j += 1
    i = p
    t = 0
    global cnt, ans
    while i<=r:
        A[i] = tmp[t]
        t += 1
        i += 1
        cnt += 1
        if cnt == k:
            ans = A[i-1]

n, k = map(int, input().split())
A = list(map(int, input().split()))
cnt = 0
ans = 0
merge_sort(0, n-1)
if ans == 0:
    print(-1)
else:
    print(ans)
