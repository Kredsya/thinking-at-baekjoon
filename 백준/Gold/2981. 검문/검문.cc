#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int n;
    cin >> n;
    
    vector<int> in(n);
    for(int i=0; i<n; i++) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    
    vector<int> sub(n-1);
    for(int i=0; i<n-1; i++) {
        sub[i] = in[i+1] - in[i];
    }
    sort(sub.begin(), sub.end());
    auto it = unique(sub.begin(), sub.end());
    sub.resize(distance(sub.begin(), it));
    
    int g = sub[0];
    for(int i=1; i<sub.size(); i++) {
        g = gcd(g, sub[i]);
    }
    
    vector<int> ans;
    for(int i=1; i*i<=g; i++) {
        if(g%i==0) {
            ans.push_back(i);
            ans.push_back(g/i);
        }
    }
    sort(ans.begin(), ans.end());
    auto itt = unique(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), itt));
    for(int i=1; i<ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    
    return 0;
}



















