#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int n;
    cin >> n;
    
    int t = 1, ans = 0;
    for(int i=2; i<=n; i++) {
        t *= i;
        while(t % 10 == 0) {
            t /= 10;
            ans++;
        }
        t %= 100000;
    }
    cout << ans;
    
    return 0;
}



















