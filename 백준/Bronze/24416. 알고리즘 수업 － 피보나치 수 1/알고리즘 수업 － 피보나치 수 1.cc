#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int ans1, ans2;
int fib(int n) {
    if (n == 1 || n == 2) {
        ans1++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

vector<int> f;
int fibonacci(int n) {
    f[1] = f[2] = 1;
    for(int i=3; i<=n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        ans2++;
    }
    return f[n];
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int n;
    cin >> n;
    f = vector<int>(n+1);
    fib(n);
    fibonacci(n);
    cout << ans1 << ' ' << ans2;
    
    return 0;
}



















