#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    //LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            cout << ' ';
        }
        for(int j=0; j<2*i+1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<n-i-1; j++) {
            cout << ' ';
        }
        for(int j=0; j<2*i+1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    
    return 0;
}



















