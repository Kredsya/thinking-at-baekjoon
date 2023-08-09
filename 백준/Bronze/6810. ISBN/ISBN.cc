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
    
    string in = "9780921418";
    int sum = 0;
    for(int i=0; i<10; i++) {
        sum += (i&1?3:1)*(in[i]-'0');
    }
    int a;
    cin >> a;
    sum += a;
    cin >> a;
    sum += a*3;
    cin >> a;
    sum += a;
    cout << "The 1-3-sum is " << sum;
    
    return 0;
}



























