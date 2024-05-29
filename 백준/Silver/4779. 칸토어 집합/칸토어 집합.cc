#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

void p(int f, int r) {
    if(r-f == 1) {
        cout << "-";
        return;
    }

    int div3 = (r-f)/3;

    p(f, f + div3);
    for(int i=0; i<div3; i++) {
        cout << ' ';
    }
    p(f + div3 * 2, r);
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif

    int n, e;

    cin >> n;
    while(!cin.eof()) {
        e = 1;
        for(int i=0; i<n; i++) {
            e *= 3;
        }
        p(0, e);
        cout << '\n';
        cin >> n;
    }

    return 0;
}



















