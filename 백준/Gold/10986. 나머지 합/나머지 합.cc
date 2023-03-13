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
    
    ll n, m;
    cin >> n >> m;
    
    vector<ll> x(n+1);
    vector<ll> cnt(1000);
    for(int i=1; i<=n; i++) {
        cin >> x[i];
        x[i] += x[i-1];
        x[i] %= m;
        cnt[x[i]]++;
    }
    
    ll ans = cnt[0];
    for(int i=0; i<m; i++) {
        ans += cnt[i] * (cnt[i] - 1) / 2;   // nCr, n = cnt[i], r = 2
    }
    
    cout << ans;
    
    return 0;
}



















