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
    
    int a, b;
    vector<int> ans(n+1);
    for(int i=1; i<=n; i++) {
        ans[i] = i;
    }
    while(m--) {
        cin >> a >> b;
        for(int i=a; i<=(a+b)/2; i++) {
            swap(ans[i], ans[a+b-i]);
        }
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    
    return 0;
}



















