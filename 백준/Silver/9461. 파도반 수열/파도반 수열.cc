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
    
    int t;
    cin >> t;
    
    
    ll x[101] = {0, 1, 1, 1, 2, 2};
    for(int i=6; i<101; i++) {
        x[i] = x[i-1] + x[i-5];
    }
    int n;
    while(t--) {
        cin >> n;
        cout << x[n] << '\n';;
    }
    
    return 0;
}



















