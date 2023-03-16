#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int n;
    cin >> n;
    
    deque<int> q;
    map<string, int> m;
    m["push"] = 0;
    m["pop"] = 1;
    m["size"] = 2;
    m["empty"] = 3;
    m["front"] = 4;
    m["back"] = 5;
    string str;
    int in;
    while(n--) {
        cin >> str;
        switch(m[str]) {
        case 0:
            cin >> in;
            q.push_back(in);
            break;
        case 1:
            if(!q.size()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
                q.pop_front();
            }
            break;
        case 2:
            cout << q.size() << '\n';
            break;
        case 3:
            cout << q.empty() << '\n';
            break;
        case 4:
            if(!q.size()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
            }
            break;
        case 5:
            if(!q.size()) {
                cout << "-1\n";
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }
    
    return 0;
}



















