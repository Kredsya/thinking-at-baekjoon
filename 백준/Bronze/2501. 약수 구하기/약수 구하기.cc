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
    
    int n, k;
    cin >> n >> k;
    
    int ans = 0, cnt = 0;
    for(int i=1; i<=n; i++) {
        if(n%i==0) {
            if(++cnt == k) {
                ans = i;
                break;
            }
        }
    }
    cout << ans;
    
    return 0;
}



















