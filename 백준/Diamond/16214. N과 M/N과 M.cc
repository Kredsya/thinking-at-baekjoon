#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#ifdef BOJ
#define NDEBUG
#endif
using namespace std;
using ll = long long;

vector<int> prime;

ll phi(ll n) {
    ll ans = n;
    for(int i=0; prime[i]*prime[i]<=n; i++) {
        if(n%prime[i] == 0) {
            while(n%prime[i] == 0)
                n /= prime[i];
            ans -= ans/prime[i];
        }
    }
    if(n!=1)
        ans -= ans/n;
    return ans;
}

ll power(ll x, ll p, ll m) {
    ll ret = 1;
    while(p) {
        if(p&1) {
            ret *= x;
            ret %= m;
        }
        x *= x;
        x %= m;
        p >>= 1;
    }
    return ret;
}

ll f(ll n, ll m) {
    if(m==1) return 1;
    ll p = f(n, phi(m)) % m;
    if(p < (ll)log2(m)) p += phi(m);
    ll ret = power(n, p, m);
    return ret;
}

int main() {
#ifndef NDEBUG
    LOAD_TXT;
#else
    FAST_IO;
#endif

    bool flag;
    prime.push_back(2);
    for(int i=3; i<=100000; i++) {
        flag = true;
        for(int j=0; prime[j]*prime[j]<=i; j++) {
            if(i%prime[j]==0) {
                flag = false;
                break;
            }
        }
        if(flag) prime.push_back(i);
    }

    int t;
    cin >> t;

    ll n, m;
    while(t--) {
        cin >> n >> m;
        if(m==1) {
            cout << 0 << '\n';
            continue;
        }
        ll p = f(n, phi(m)) % m;
        if(p < (ll)log2(m)) p += phi(m);
        cout << power(n%m, p, m) << '\n';
    }

    return 0;
}