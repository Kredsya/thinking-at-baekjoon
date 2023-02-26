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
    
    vector<int> a(5);
    int s = 0;
    for(int i=0; i<5; i++) {
        cin >> a[i];
        s += a[i];
    }
    
    sort(a.begin(), a.end());
    
    cout << s/5 << '\n' << a[2];
    
    return 0;
}



















