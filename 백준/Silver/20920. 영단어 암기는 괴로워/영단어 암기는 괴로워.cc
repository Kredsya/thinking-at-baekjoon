#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

bool sortfunc(pair<string, int> a, pair<string, int> b) {
    if(a.second == b.second) {
        if(a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        else {
            return a.first.length() > b.first.length();
        }
    }
    else {
        return a.second > b.second;
    }
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif

    int1(n)
    int1(m)

    string in;
    map<string, int> tmp;
    for(int i=0; i<n; i++) {
        cin >> in;
        if(in.length() < m) continue;
        tmp[in]++;
    }

    vector<pair<string, int>> dict;
    for(auto it = tmp.begin(); it != tmp.end(); it++) {
        dict.push_back({it->first, it->second});
    }

    sort(dict.begin(), dict.end(), sortfunc);

    for(auto it : dict) {
        cout << it.first << '\n';
    }

    return 0;
}



















