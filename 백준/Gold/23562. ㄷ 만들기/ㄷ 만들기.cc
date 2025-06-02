#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

int n, m, a, b;
vector<vector<int>> v;

int white(int x, int y, int k) {
    int ret = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(x <= i && i < x+3*k && y <= j && j < y+3*k) continue;
            if(v[i][j] == 1) ret += b;
        }
    }
    
    for(int i=x+k; i<x+2*k; i++) {
        for(int j=y+k; j<y+3*k; j++) {
            if(v[i][j] == 1) ret += b;
        }
    }
    
    return ret;
}

int black(int x, int y, int k) {
    int ret = 0;
    
    for(int i=x; i<x+3*k; i++) {
        for(int j=y; j<y+3*k; j++) {
            if(x+k <= i && i < x+2*k && y+k <= j) continue;
            if(v[i][j] == 0) ret += a;
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
    
    cin >> n >> m >> a >> b;
    
    char ch;
    v = vector<vector<int>>(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ch;
            v[i][j] = (ch == '#' ? 1 : 0);
        }
    }
    
    int ans = 2e9;
    for(int k=1; 3*k <= min(n, m); k++) {
        for(int i=0; i<=n-3*k; i++) {
            for(int j=0; j<=m-3*k; j++) {
                ans = min(ans, white(i, j, k) + black(i, j, k));
                // if(ans == 80) cout << i << ' ' << j << ' ' << k << '\n';
            }
        }
    }
    
    cout << ans;
    
    return 0;
}



















