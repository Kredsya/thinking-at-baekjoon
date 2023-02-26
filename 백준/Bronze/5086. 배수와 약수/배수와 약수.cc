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
    
    int a, b;
    cin >> a >> b;
    while(a != 0 || b != 0) {
        if(a%b==0) {
            cout << "multiple\n";
        }
        else if(b%a==0) {
            cout << "factor\n";
        }
        else {
            cout << "neither\n";
        }
        cin >> a >>b;
    }
    
    return 0;
}



















