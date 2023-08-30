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
    
    double M, S, G;
    cin >> M >> S >> G;
    double A, B;
    cin >> A >> B;
    double L, R;
    cin >> L >> R;
    
    A = L/A;
    B = R/B;
    
    S = M/S;
    G = M/G;
    
    if(A+G > B+S) {
        cout << "latmask";
    }
    else {
        cout << "friskus";
    }
    
    return 0;
}



















