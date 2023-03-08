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
    
    vector<int> in(n+1);
    for(int i=0; i<n; i++) {
        cin >> in[i+1];
    }
    
    vector<int> two(n+1);
    vector<int> dp(n+1);
    two[1] = dp[1] = in[1];
    int ans = in[1];
    for(int i=2; i<=n; i++) {
        two[i] = dp[i-1] + in[i];
        ans = max(ans, two[i]);
        for(int j=0; j<i-1; j++) {
            dp[i] = max(dp[i], max(dp[j], two[j]) + in[i]);
            ans = max(ans, dp[i]);
        }
    }
    
    cout << ans;
    
    return 0;
}



















