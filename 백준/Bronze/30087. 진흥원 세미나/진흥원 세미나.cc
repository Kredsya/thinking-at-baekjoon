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
    
    map<string, string> m;
    m["Al"] = "204";
    m["Da"] = "207";
    m["Ar"] = "302";
    m["Cy"] = "B101";
    m["Ne"] = "303";
    m["St"] = "501";
    m["Te"] = "105";
    
    int1(n)
    string in;
    while(n--) {
        cin >> in;
        cout << m[in.substr(0, 2)] << '\n';
    }
    
    return 0;
}



















