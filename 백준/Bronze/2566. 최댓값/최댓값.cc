#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int a;
    int max=-1, I=0, J=0;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> a;
            if(a > max) {
                max = a;
                I = i+1;
                J = j+1;
            }
        }
    }
    
    cout << max << '\n' << I << ' ' << J;
    
    return 0;
}



















