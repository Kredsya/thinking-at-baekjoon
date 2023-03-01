#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int n;
vector<int> x;
vector<int> num(4);
vector<int> opt;
int Max = -2e9, Min = 2e9;

void solve(int depth) {
    if(depth == n) {
        int ret = x[0];
        for(int i=1; i<n; i++) {
            switch(opt[i]) {
            case 0:
                ret += x[i];
                break;
            case 1:
                ret -= x[i];
                break;
            case 2:
                ret *= x[i];
                break;
            case 3:
                ret /= x[i];
            }
        }
        Max = max(Max, ret);
        Min = min(Min, ret);
        return;
    }
    
    for(int i=0; i<4; i++) {
        if(num[i]) {
            num[i]--;
            opt[depth] = i;
            
            solve(depth+1);
            
            num[i]++;
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
    
    x = vector<int>(n);
    for(int i=0; i<n; i++) {
        cin >> x[i];
    }
    
    for(int i=0; i<4; i++) {
        cin >> num[i];
    }
    
    opt = vector<int>(n);
    solve(1);
    
    cout << Max << '\n' << Min;
    
    return 0;
}



















