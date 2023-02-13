#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    freopen("input.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    int N = 0;
    vector<vector<int>> ans(r2-r1+1, vector<int>(c2-c1+1));
    int square, pos, x, y, d, num, dif;
    for(int i=0; i<r2-r1+1; i++) {
        for(int j=0; j<c2-c1+1; j++) {
            x = r1+i;
            y = c1+j;
            pos = max(abs(x), abs(y));
            square = pos * 2 + 1;
            square *= square;
            
            if(x == 0 && y == 0) {
                ans[i][j] = 1;
                continue;
            }
            
            if(x == pos && y != -pos) { d = 0; dif = pos - y; }
            else if(y == -pos && x != -pos) { d = 1; dif = pos - x; }
            else if(x == -pos && y != pos) { d = 2; dif = pos + y; }
            else if(y == pos && x != pos) { d = 3; dif = pos + x; }
            
            num = square - d * pos * 2 - dif;
            ans[i][j] = num;
            N = max(N, (int)to_string(num).length());
        }
    }
    
    //int N = to_string(M).length();
    int digit;
    for(auto vec : ans) {
        for(int it : vec) {
            digit = to_string(it).length();
            for(int i=0; i<N-digit; i++) cout << ' ';
            cout << it << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}



















