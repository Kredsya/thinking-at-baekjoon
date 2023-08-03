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
    
    int t;
    cin >> t;
    
    double a, b, c, res;
    while(t--) {
        cin >> a >> b >> c;
        res = a * b * c;
        printf("$%.2lf\n", res);
    }
    
    return 0;
}



























