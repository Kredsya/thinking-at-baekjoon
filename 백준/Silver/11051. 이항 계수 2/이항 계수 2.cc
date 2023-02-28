#include <bits/stdc++.h>
#define debug(x) cout << #x << " is " << x << '\n';
using namespace std;
using ll = long long;

int main() {
    ll N, k, p=10007;
    cin >> N >> k;

    ll n = 1;
    for(int i=2; i<=N; i++) {
        n *= i;
        n %= p;
    }
    //debug(n);

    ll a = 1;
    for(int i=2; i<=k; i++) {
        a *= i;
        a %= p;
    }
    for(int i=2; i<=(N-k); i++) {
        a *= i;
        a %= p;
    }
    //debug(a);

    ll b = 1;

    bitset<30> e(p-2);
    for(int i=0; i<30; i++) {
        if(e[i]==1) {
            b *= a;
            b %= p;
        }
        a *= a;
        a %= p;
    }
    //debug(b);

    ll ans = n;
    ans *= b;
    ans %= p;

    //debug(ans);
    cout << ans;

    return 0;
}
