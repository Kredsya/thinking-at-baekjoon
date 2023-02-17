#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using LL = long long;
LL lgcd(LL a, LL b) {return b ? lgcd(b, a%b) : a;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    LL k, c;
    while(t--) {
        cin >> k >> c;

        if(lgcd(k, c) != 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        if(k==1 && c==1) {
            cout << 2 << endl;
            continue;
        }

        if(c==1) {
            if(k+1 > 1e9) {
                cout << "IMPOSSIBLE\n";
                continue;
            }
            cout << k+1 << endl;
            continue;
        }

        if(k==1) {
            cout << 1 << endl;
            continue;
        }

        LL s1=1, s2=0, t1=0, t2=1, r1=k, r2=c, q=k/c;
        while(1) {
            swap(r1, r2);
            r2 %= r1;
            if(!r2) {
                break;
            }

            swap(s1, s2);
            s2 = s2 - s1*q;
            swap(t1, t2);
            t2 = t2 - t1*q;

            q = r1/r2;
        }

        t2 += k;
        t2 %= k;

        while(t2*c <= k) {
            t2 += k;
        }

        if(t2 > 1e9) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << t2 << endl;
    }

    return 0;
}


















