#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int t;
    cin >> t;
    
    int a, b;
    while(t--) {
        cin >> a >> b;
        cout << a / gcd(a, b) * b << '\n';
    }
    
    return 0;
}



















