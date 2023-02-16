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
    cin >> n;
    int ans[4];
    if(n&1) {
        ans[0] = 2;
        ans[1] = 3;
        n -= 5;
    }
    else {
        ans[0] = 2;
        ans[1] = 2;
        n -= 4;
    }
    
    bool a[1'000'005] = {0, 0, 1};
    bool flag;
    for(int i=3; i<=n; i++) {
        flag = true;
        for(int j=0; j*j<=i; j++) {
            if(a[j] && (i % j == 0)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            a[i] = true;
        }
    }
    
    flag = true;
    for(int i=2; i<n; i++) {
        if(a[i] && a[n-i]) {
            cout << i << ' ' << n-i << ' ';
            flag = false;
            break;
        }
    }
    
    if(flag) {
        cout << -1;
    }
    else {
        cout << ans[0] << ' ' << ans[1];
    }
    
    return 0;
}



















