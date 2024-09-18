#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
#define vsort(v) sort(v.begin(),v.end());
#define csort(v,f) sort(v.begin(),v.end(),f);
#define x first
#define y second
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    // (k - (small^2 + 1)) / 2 = answer
    ll n, k;
    cin >> n >> k;
    ll l = 1, h = min((ll)1e9, n*n), m, ans, cnt;
    while(l <= h) {
        m = (l + h) / 2;
        cnt = 0;
        for(int i=1; i<=n; i++) {
            cnt += min(m / i, n);
        }
        if(k <= cnt) {
            h = m - 1;
            ans = m;
        }
        else {
            l = m + 1;
        }
    }
    
    cout << ans;
    
    return 0;
}



















