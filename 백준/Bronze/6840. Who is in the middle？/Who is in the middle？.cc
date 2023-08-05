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
    
    int a, b, c;
    cin >> a >> b >> c;
    int M = max(a, max(b, c));
    int m = min(a, min(b, c));
    
    if(a!=M && a!=m) {
        cout << a;
    }
    if(b!=M && b!=m) {
        cout << b;
    }
    if(c!=M && c!=m) {
        cout << c;
    }
    
    return 0;
}



























