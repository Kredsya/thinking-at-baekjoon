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
    
    int a, b;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    
    vector<int> x(n);
    for(int i=0; i<n; i++) {
        x[i] = v[i].second;
    }
    
    vector<int> d(n, 1);
    int ans = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(x[i] > x[j])
                d[i] = max(d[i], d[j] + 1);
            ans = max(ans, d[i]);
        }
    }
    
    cout << n - ans;
    
    return 0;
}



















