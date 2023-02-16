#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);

    ll n, a;
    cin >> n >> a;
    cout << n-a << ' ';

    if(gcd(n, a)!=1) {
        cout << -1;
        return 0;
    }

    if(a==1) {
        cout << 1;
        return 0;
    }

    ll t1=0, t2=1, r1=n, r2=a, q;
    while(1) {
        q = r1/r2;
        swap(t1, t2);
        t2 = t2 - t1*q;
        swap(r2, r1);
        r2 %= r1;
        if(r1%r2==0) {
            break;
        }
    }

    while(t2<0) {
        t2 += n;
    }
    cout << t2;

    return 0;
}
