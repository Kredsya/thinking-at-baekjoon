#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define LOAD_TXT freopen("input.txt", "r", stdin);
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

ll power(ll a, ll e, ll m) {
    ll ret = 1;
    while(e) {
        if(e&1) {
            ret *= a;
            ret %= m;
        }
        a *= a;
        a %= m;
        e >>= 1;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT
#else
    FAST_IO
#endif
    
    int1(n)
    vector<ll> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    vsort(a)
    
    ll m = 1e9+7;
    vector<ll> power(n);
    power[0] = 1;
    for(int i=1; i<n; i++) {
        power[i] = 2 * power[i-1] % m;
    }
    
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ans = (ans + a[i] * power[i]) % m;
        ans = (ans - a[i] * power[n-i-1]) % m;
    }
    
    cout << (ans + m) % m;
    
    return 0;
}



















