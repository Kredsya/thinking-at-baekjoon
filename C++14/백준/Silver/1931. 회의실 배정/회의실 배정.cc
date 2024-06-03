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

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int1(n)
    vector<pair<int, int>> v(n);
    int a, b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }
    csort(v,comp)
    
    int ans = 1, recent = v[0].y;
    for(int i=1; i<n; i++) {
        if(v[i].x < recent) {
            if(v[i].y < recent) {
                recent = v[i].y;
            }
        }
        else {
            ans++;
            recent = v[i].y;
        }
    }
    
    cout << ans;
    
    return 0;
}



















