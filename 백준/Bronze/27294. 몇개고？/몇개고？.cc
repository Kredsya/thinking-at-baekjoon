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
    
    int t, s;
    cin >> t >> s;
    
    if(12<=t && t<=16) {
        if(s==0) {
            cout << 320;
            return 0;
        }
    }
    cout << 280;
    
    return 0;
}



















