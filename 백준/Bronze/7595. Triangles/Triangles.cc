#include <bits/stdc++.h>
#define LOAD_TXT freopen("input.txt", "r", stdin);
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT
#else
    FAST_IO
#endif
    
    int n;
    while(true) {
        cin >> n;
        if(n == 0) break;
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                cout << "*";
            }
            cout << '\n';
        }
    }
    
    return 0;
}



























