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
    
    int a, b;
    cin >> a >> b;
    for(int i=a; i<=b; i+=60) {
        cout << "All positions change in year " << i << '\n';
    }
    
    return 0;
}



























