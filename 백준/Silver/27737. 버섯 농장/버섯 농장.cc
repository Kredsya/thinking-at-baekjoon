#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
LOAD_TXT;
#else
FAST_IO;
#endif

int n, m, k;
cin >> n >> m >> k;

vector<vector<int>> board(n, vector<int>(n));
for(int i=0; i<n; i++) {
for(int j=0; j<n; j++) {
cin >> board[i][j];
}
}

queue<pair<int, int>> q;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int x, y, xx, yy, cnt, ans = 0;
for(int i=0; i<n; i++) {
for(int j=0; j<n; j++) {
if(board[i][j] == 0) {
cnt = 0;
q.push({i, j});
board[i][j] = 1;
while(!q.empty()) {
cnt++;
x = q.front().first;
y = q.front().second;
q.pop();
for(int d=0; d<4; d++) {
xx = x + dir[d][0];
yy = y + dir[d][1];
if(xx<0 || xx>=n) continue;
if(yy<0 || yy>=n) continue;
if(board[xx][yy] == 0) {
q.push({xx, yy});
board[xx][yy] = 1;
}
}
}

if(cnt % k == 0) {
ans += cnt / k;
}
else {
ans += cnt / k + 1;
}
}
}
}

if(ans == 0) {
cout << "IMPOSSIBLE";
}
else if(ans > m) {
cout << "IMPOSSIBLE";
}
else {
cout << "POSSIBLE\n";
cout << m-ans;
}

return 0;
}