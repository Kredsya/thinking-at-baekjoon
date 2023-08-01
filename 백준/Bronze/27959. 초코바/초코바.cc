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
    
    int n, m;
    cin >> n >> m;
    n *= 100;
    if(m <= n)
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
}



























