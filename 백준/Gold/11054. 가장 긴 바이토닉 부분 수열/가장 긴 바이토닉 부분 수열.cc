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
    
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    vector<int> up(n), down(n);
    for(int i=0; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(a[i] > a[j]) {
                up[i] = max(up[i], up[j] + 1);
                ans = max(ans, up[i]);
            }
            else if(a[i] < a[j]) {
                down[i] = max(down[i], max(up[j], down[j]) + 1);
                ans = max(ans, down[i]);
            }
        }
    }
    
    cout << ans + 1;
    
    return 0;
}



















