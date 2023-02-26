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
    
    int n, m;
    cin >> n >> m;
    
    int a, b, k;
    vector<int> ans(n+1);
    while(m--) {
        cin >> a >> b >> k;
        for(int i=a; i<=b; i++) {
            ans[i] = k;
        }
    }
    
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    
    return 0;
}



















