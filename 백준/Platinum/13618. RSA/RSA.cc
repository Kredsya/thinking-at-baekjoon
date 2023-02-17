#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);

    const int MAX_PRIME = 5600;
    int prime[MAX_PRIME] = {2};
    bool flag;
    int lm, np = 1;
    for(int i=3; np<MAX_PRIME; i++) {
        flag = true;
        lm = (int)sqrt(i);
        for(int j=0; prime[j]<=lm; j++) {
            if(i%prime[j] == 0) {
                flag = false;
                break;
            }
        }
        if(flag)
            prime[np++] = i;
    }

    ll n, e, c;
    cin >> n >> e >> c;
    ll p, Q;

    for(int i=0; i<MAX_PRIME; i++) {
        if(n%prime[i] == 0) {
            p = prime[i];
            Q = n/prime[i];
        }
    }

    ll phiN = (p-1)*(Q-1);

    ll t1=0, t2=1, r1=phiN, r2=e, q;
    while(1) {
        if(r1%r2==0) break;
        q = r1/r2;
        swap(t1, t2);
        t2 -= q*t1;
        swap(r1, r2);
        r2 %= r1;
    }
    while(t2<0) t2+=phiN;

    bitset<64> E(t2);
    ll ans = 1;
    for(int i=0; i<64; i++) {
        if(E[i]) {
            ans *= c;
            ans %= n;
        }
        c *= c;
        c %= n;
    }

    cout << ans;

    return 0;
}
