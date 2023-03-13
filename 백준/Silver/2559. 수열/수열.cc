#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n+1);
    
    cin >> x[1];
    for(int i=2; i<=n; i++) {
        cin >> x[i];
        x[i] += x[i-1];
    }
    
    int ans = -1e9;
    for(int i=k; i<=n; i++) {
        ans = max(ans, x[i] - x[i-k]);
    }
    
    cout << ans;
    
    return 0;
}



















