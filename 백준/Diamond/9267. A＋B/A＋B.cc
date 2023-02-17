#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
#define ll __int128
#define YES { cout << "YES"; return; }
#define NO { cout << "NO"; return; }

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void solve(ll a, ll b, ll S) {
    if(a==0) {
        if(b==0) {
            if(S==0) YES
            NO
        }
        else {
            if(S%b==0) YES
            NO
        }
    }
    if(b==0) {
        if(S%a==0) YES
        NO
    }
    if(a==S || b==S) YES

    ll g = gcd(a, b);
    if(g != 1) {
        if(S%g == 0) {
            solve(a/g, b/g, S/g);
            return;
        }
        else NO
    }

    ll x1=1, x2=0, y1=0, y2=1, r1=a, r2=b, q;
    while(r1%r2) {
        q = r1/r2;
        swap(x1, x2); swap(y1, y2); swap(r1, r2);
        x2 -= q*x1;
        y2 -= q*y1;
        r2 %= r1;
    }

    ll x = x2 * S;
    ll y = y2 * S;
    ll d;
    if(x >= b || x <= 0) {
        d = x / b;
        x %= b;
        y += a * d;
    }

    while(1) {
        if(x>0 && y>0) {
            if(gcd(x, y) == 1) {
                YES
            }
        }
        if(y <= 0) NO

        x += b;
        y -= a;
    }
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif

    long long a, b, S;
    cin >> a >> b >> S;
    solve(a, b, S);

    return 0;
}
