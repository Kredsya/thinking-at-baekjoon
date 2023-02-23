
def phi(n):
    ret = n
    num = n
    i = 0
    while prime[i]*prime[i] <= n:
        if num % prime[i] == 0:
            ret //= prime[i]
            ret *= prime[i] - 1
            while num % prime[i] == 0:
                num //= prime[i]
        i += 1
    if num != 1:
        ret //= num
        ret *= num - 1
    return ret

def e(t, m):
    if t == n: return x[t-1]
    if m == 1: return 1
    p = phi(m)
    ret = e(t+1, p)
    if ret > p: return pow(x[t-1], ret % p + p)
    else: return pow(x[t-1], ret)

prime = [2]
for i in range(3, 1005):
    flag = True
    j = 0
    while prime[j] * prime[j] <= i:
        if i % prime[j] == 0:
            flag = False
            break
        j += 1
    if flag:
        prime.append(i)

t, m = map(int, input().split())

for _ in range(t):
    x = []
    n, *x = map(int, input().split())
    print(e(1, m) % m)