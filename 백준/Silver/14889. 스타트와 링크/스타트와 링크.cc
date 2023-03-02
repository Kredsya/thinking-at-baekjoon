#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int n;
vector<vector<int>> x;
vector<bool> A;
int ans = 2e9;

void solve(int depth, int start) {
    if(depth == n/2) {
        int a = 0, b = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(i == j) continue;
                if(A[i] && A[j]) {
                    a += x[i][j] + x[j][i];
                }
                else if(!A[i] && !A[j]) {
                    b += x[i][j] + x[j][i];
                }
            }
        }
        ans = min(ans, abs(a-b));
    }
    
    for(int i=start; i<n; i++) {
        if(!A[i]) {
            A[i] = true;
            solve(depth+1, i+1);
            A[i] = false;
        }
    }
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    cin >> n;
    
    x = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> x[i][j];
        }
    }
    
    A = vector<bool>(n);
    solve(0, 0);
    cout << ans;
    
    return 0;
}



















