#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#ifdef BOJ
#define NDEBUG
#endif
using namespace std;
using ll = long long;

int main() {
#ifndef NDEBUG
    LOAD_TXT;
#else
    FAST_IO;
#endif

    bool flag;
    vector<int> prime;
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

    ll ans;
    int n;
    while(1) {
        cin >> n;
        if(n==0) break;
        if(n==1) {
            cout << 0 << '\n';
            continue;
        }
        ans = n;
        for(int i=0; prime[i]*prime[i]<=n; i++) {
            if(n%prime[i] == 0) {
                while(n%prime[i] == 0) {
                    n /= prime[i];
                }
                ans -= ans/prime[i];
            }
        }
        if(n!=1) {
            ans -= ans/n;
        }
        cout << ans << '\n';
    }

    return 0;
}
