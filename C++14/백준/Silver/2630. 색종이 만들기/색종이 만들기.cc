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

vector<vector<int>> v;

bool check(int a, int b, int e) {
    int c = v[a][b];
    for(int i=a; i<a+e; i++) {
        for(int j=b; j<b+e; j++) {
            if(v[i][j] != c) {
                return false;
            }
        }
    }
    return true;
}

// x = white, y = blue
pair<int, int> dq(int a, int b, int e) {
    if(e == 1 || check(a, b, e)) {
        return v[a][b] ? make_pair(0, 1) : make_pair(1, 0);
    }
    
    pair<int, int> ret, tmp;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            tmp = dq(a + (e / 2) * i, b + (e / 2) * j, e / 2);
            ret.x += tmp.x;
            ret.y += tmp.y;
        }
    }
    return ret;
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int1(n)
    v = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    
    pair<int, int> ans = dq(0, 0, n);
    cout << ans.x << '\n' << ans.y;
    
    return 0;
}



















