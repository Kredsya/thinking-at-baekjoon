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
    
    ints(a, 3);
    ints(b, 3);
    int t[3] = {3, 20, 120};
    int A = 0, B = 0;
    for(int i=0; i<3; i++) {
        A += t[i]*a[i];
        B += t[i]*b[i];
    }
    
    if(A > B) cout << "Max";
    else if(A == B) cout << "Draw";
    else cout << "Mel";
    
    return 0;
}



















