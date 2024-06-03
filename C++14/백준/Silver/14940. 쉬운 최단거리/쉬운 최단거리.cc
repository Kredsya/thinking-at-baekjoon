#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
#define vsort(v) sort(v.begin(),v.end());
#define csort(v,f) sort(v.begin(),v.end(),f);
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int2(n,m)
    int a[n][m];
    int sx, sy;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) {
                sx = i;
                sy = j;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    int x, y, nx, ny;
    int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans[i][j] = 10000000;
        }
    }
    ans[sx][sy] = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            nx = x + mv[i][0];
            ny = y + mv[i][1];
            if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if(ans[nx][ny] <= ans[x][y] + 1) continue;
            if(!a[nx][ny]) continue;
            q.push({nx, ny});
            ans[nx][ny] = ans[x][y] + 1;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j] == 0) cout << 0 << ' ';
            else cout << (ans[i][j] == 10000000 ? -1 : ans[i][j]) << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}



















