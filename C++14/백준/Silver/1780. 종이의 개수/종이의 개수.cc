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

int image[2187][2187];

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

array<int, 3> re(int a, int b, int l) {
    array<int, 3> ret = {}, tmp = {};
    
    if(isSolid(a, b, l)) {
        ret[image[a][b] + 1]++;
        return ret;
    }
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            tmp = re(a + (l / 3) * i, b + (l / 3) * j, l / 3);
            for(int idx=0; idx<3; idx++) {
                ret[idx] += tmp[idx];
            }
        }
    }
    
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int1(n)
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> image[i][j];
        }
    }
    
    array<int, 3> ans = re(0, 0, n);
    for(int a : ans) {
        cout << a << '\n';
    }
    
    return 0;
}



















