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
    
    int n, k, m;
    cin >> n >> k >> m;
    
    int ans = 0, kk;
    while(++ans) {
        kk = (k-1)%n+1;
        if(m == kk ) break;
        if(m-kk <= 0) {
            m += n - kk;
        }
        else {
            m -= kk;
        }
        n--;
    }
    
    cout << ans;
    
    return 0;
}



















