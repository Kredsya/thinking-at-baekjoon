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
    
    deque<int> d;
    int a, x;
    int1(n);
    while(n--) {
        cin >> a;
        if(a == 1) {
            cin >> x;
            d.push_front(x);
        }
        else if(a == 2) {
            cin >> x;
            d.push_back(x);
        }
        else if(a == 3) {
            if(d.empty()) {
                cout << "-1\n";
            }
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if(a == 4) {
            if(d.empty()) {
                cout << "-1\n";
            }
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if(a == 5) {
            cout << d.size() << '\n';
        }
        else if(a == 6) {
            cout << d.empty() << '\n';
        }
        else if(a == 7) {
            if(d.empty()) {
                cout << "-1\n";
            }
            else {
                cout << d.front() << '\n';
            }
        }
        else if(a == 8) {
            if(d.empty()) {
                cout << "-1\n";
            }
            else {
                cout << d.back() << '\n';
            }
        }
    }
    
    return 0;
}



















