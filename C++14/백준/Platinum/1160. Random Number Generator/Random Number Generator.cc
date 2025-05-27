#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
#define vsort(v) sort(v.begin(),v.end());
#define csort(v,f) sort(v.begin(),v.end(),f);
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    auto print_int128 = [](unsigned __int128 v) {
        string s;
        if (v == 0) { cout << 0; return; }
        while (v) { s.push_back('0' + v % 10); v /= 10; }
        reverse(s.begin(), s.end());
        cout << s;
    };
    
    ll m, a, c, x, n, g;
    cin >> m >> a >> c >> x >> n >> g;
    
    // __int128 A[2] = {x, 1};
    __int128 B2[2][2] = {{a, 0}, {c, 1}};
    __int128 Bn[2][2] = {{1, 0}, {0, 1}};
    __int128 tmp[2][2];
    
    bitset<128> b(n);
    for(int i=0; i<128; i++) {
        if(b[i]) {
            tmp[0][0] = Bn[0][0];
            tmp[0][1] = Bn[0][1];
            tmp[1][0] = Bn[1][0];
            tmp[1][1] = Bn[1][1];
            
            Bn[0][0] = (tmp[0][0]*B2[0][0] % m + tmp[0][1]*B2[1][0] % m) % m;
            Bn[0][1] = (tmp[0][0]*B2[0][1] % m + tmp[0][1]*B2[1][1] % m) % m;
            Bn[1][0] = (tmp[1][0]*B2[0][0] % m + tmp[1][1]*B2[1][0] % m) % m;
            Bn[1][1] = (tmp[1][0]*B2[0][1] % m + tmp[1][1]*B2[1][1] % m) % m;
        }
        
        tmp[0][0] = (B2[0][0]*B2[0][0] % m + B2[0][1]*B2[1][0] % m) % m;
        tmp[0][1] = (B2[0][0]*B2[0][1] % m + B2[0][1]*B2[1][1] % m) % m;
        tmp[1][0] = (B2[1][0]*B2[0][0] % m + B2[1][1]*B2[1][0] % m) % m;
        tmp[1][1] = (B2[1][0]*B2[0][1] % m + B2[1][1]*B2[1][1] % m) % m;
        
        B2[0][0] = tmp[0][0];
        B2[0][1] = tmp[0][1];
        B2[1][0] = tmp[1][0];
        B2[1][1] = tmp[1][1];
    }
    
    x = (x*Bn[0][0] % m + Bn[1][0]) % m % g;
    print_int128(x);
    
    return 0;
}



















