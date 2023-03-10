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
    
    int n, k;
    cin >> n >> k;
    
    vector<int> w(n+1), v(n+1);
    for(int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(w[i] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    
    cout << dp[n][k];
    
    return 0;
}



















