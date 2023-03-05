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
    
    int n;
    cin >> n;
    
    vector<int> d(n+1);
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    for(int i=3; i<=n; i++) {
        d[i] = d[i-1] + d[i-2];
        d[i] %= 15746;
    }
    
    cout << d[n];
    
    return 0;
}



















