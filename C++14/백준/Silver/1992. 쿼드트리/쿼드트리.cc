#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
#define vsort(v) sort(v.begin(),v.end());
#define csort(v,f) sort(v.begin(),v.end(),f);
#define x first
#define y second
using namespace std;
using ll = long long;

int image[64][64];

bool isSolid(int a, int b, int l) {
    int c = image[a][b];
    for(int i=a; i<a + l; i++) {
        for(int j=b; j<b + l; j++) {
            if(image[i][j] != c) {
                return false;
            }
        }
    }
    return true;
}

void re(int a, int b, int l) {
    if(isSolid(a, b, l)) {
        cout << image[a][b];
        return;
    }
    
    cout << "(";
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            re(a + (l / 2) * i, b + (l / 2) * j, l / 2);
        }
    }
    cout << ")";
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int1(n)
    string in;
    for(int i=0; i<n; i++) {
        cin >> in;
        for(int j=0; j<n; j++) {
            image[i][j] = in[j] - '0';
        }
    }
    
    re(0, 0, n);
    
    return 0;
}



















