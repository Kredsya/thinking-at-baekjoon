#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
#define vsort(v) sort(v.begin(),v.end());
#define csort(v,f) sort(v.begin(),v.end(),f);
#define x first
#define y second
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int1(n)
    
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    bool flag;
    for(int i=4; i<=n; i++) {
        flag = true;
        for(auto p : primes) {
            if(p*p > i) break;
            if(i % p == 0) {
                flag = false;
                break;
            }
        }
        if(flag) primes.push_back(i);
    }
    
    vector<int> dp(n+1);
    dp[0] = 1;
    for(auto p : primes) {
        for(int i=p; i<=n; i++) {
            dp[i] += dp[i-p];
            dp[i] %= 123456789;
        }
    }
    
    cout << dp[n];
    
    return 0;
}



















