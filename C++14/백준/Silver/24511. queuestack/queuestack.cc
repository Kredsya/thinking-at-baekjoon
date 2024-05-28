#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int1(n)
    ints(a,n)
    ints(v,n)
    int1(m)
    ints(c,m)
    
    int cnt = 0;
    for(int i=n-1; i>=0; i--) {
        if(a[i] == 0) {
            cout << v[i] << ' ';
            cnt++;
            if(cnt == m) {
                return 0;
            }
        }
    }
    
    for(int i=0; i<m-cnt; i++) {
        cout << c[i] << ' ';
    }
    
    return 0;
}



















