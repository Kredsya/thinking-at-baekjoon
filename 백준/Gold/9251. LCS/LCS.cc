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
    
    string a, b;
    cin >> a >> b;
    
    a = " " + a;
    b = " " + b;
    
    vector<vector<int>> dp(a.length(), vector<int>(b.length()));
    for(int i=1; i<a.length(); i++) {
        for(int j=1; j<b.length(); j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[a.length()-1][b.length()-1];
    
    return 0;
}



















