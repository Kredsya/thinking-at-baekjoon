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
    
    int n, s;
    cin >> n >> s;
    
    vector<int> x(n+1), sum(n+1);
    for(int i=1; i<=n; i++) {
        cin >> x[i];
    }
    for(int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + x[i];
    }
    
    auto l = sum.begin(), r = sum.begin() + 1;
    int ans = 2e9;
    while(r != sum.end()) {
        if(*r - *l < s) r++;
        else {
            ans = min(ans, (int)distance(l, r));
            l++;
        }
    }
    
    if(ans == 2e9) {
        cout << 0;
    }
    else {
        cout << ans;
    }
    
    return 0;
}



















