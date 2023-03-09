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
    
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    
    int ans = 0;
    ans += a6;
    
    ans += a5;
    a1 -= a5*11;
    if(a1 < 0) a1 = 0;
    
    ans += a4;
    a2 -= 5*a4;
    if(a2 < 0) {
        a2 *= -1;
        a1 -= 4*a2;
        a2 = 0;
    }
    if(a1 < 0) a1 = 0;
    
    ans += a3/4;
    a3 %= 4;
    if(a3 > 0) {
        ans++;
        switch(a3) {
        case 3:
            a2 -= 1;
            a1 -= 5;
            break;
        case 2:
            a2 -= 3;
            a1 -= 6;
            break;
        case 1:
            a2 -= 5;
            a1 -= 7;
            break;
        }
    }
    if(a2 < 0) {
        a2 *= -1;
        a1 -= 4*a2;
        a2 = 0;
    }
    if(a1 < 0) a1 = 0;
    
    ans += a2/9;
    a2 %= 9;
    if(a2 > 0) {
        ans++;
        a2 = 9 - a2;
        a1 -= 4*a2;
    }
    if(a1 < 0) a1 = 0;
    
    ans += a1 / 36;
    a1 %= 36;
    if(a1 > 0) ans++;
    
    cout << ans;
    
    return 0;
}



















