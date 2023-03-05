#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

bool flag[21][21][21];
int ret[21][21][21];

int w(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) {
        return 1;
    }
    
    if(a>20 || b>20 || c>20) {
        return w(20, 20, 20);
    }
    
    if(flag[a][b][c]) {
        return ret[a][b][c];
    }
    flag[a][b][c] = true;
    
    if(a<b && b<c) {
        ret[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return ret[a][b][c];
    }
    
    ret[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return ret[a][b][c];
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int a, b, c;
    cin >> a >> b >> c;
    while(a!=-1 || b!=-1 || c!=-1) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
        cin >> a >> b >> c;
    }
    
    return 0;
}



















