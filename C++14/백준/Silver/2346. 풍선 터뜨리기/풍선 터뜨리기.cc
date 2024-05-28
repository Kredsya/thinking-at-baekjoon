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
    deque<array<int, 2>> d(n);
    for(int i=0; i<n; i++) {
        cin >> d[i][0];
        d[i][1] = i + 1;
    }
    
    int move;
    while(true) {
        cout << d.front()[1] << ' ';
        move = d.front()[0];
        d.pop_front();
        if(d.size() == 0)
            break;
        
        if(0 < move) {
            move--;
            for(int i=0; i<move; i++) {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else {
            move = abs(move);
            for(int i=0; i<move; i++) {
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }
    
    return 0;
}



















