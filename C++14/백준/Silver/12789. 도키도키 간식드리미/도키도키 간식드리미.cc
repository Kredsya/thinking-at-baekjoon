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
    ints(v,n)
    
    int now = 1;
    stack<int> s;
    for(int i=0; i<n; i++) {
        if(v[i] == now) {
            now++;
        }
        else if(!s.empty() && s.top() == now) {
            now++;
            i--;
            s.pop();
        }
        else {
            s.push(v[i]);
        }
    }
    
    while(!s.empty()) {
        if(s.top() != now) {
            cout << "Sad";
            return 0;
        }
        s.pop();
        now++;
    }
    
    cout << "Nice";
    return 0;
}



















