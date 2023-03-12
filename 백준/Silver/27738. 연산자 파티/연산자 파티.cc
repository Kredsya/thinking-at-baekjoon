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
    
    ll n;
    cin >> n;
    
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    ll x = 0;
    for(int i=n/f*f+1; i<=n; i++) {
        if(i%a == 0) x += i;
        if(i%b == 0) x %= i;
        if(i%c == 0) x &= i;
        if(i%d == 0) x ^= i;
        if(i%e == 0) x |= i;
        if(i%f == 0) x >>= i;
    }
    
    cout << x;
    
    return 0;
}



















