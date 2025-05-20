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

void init(vector<ll> &v, vector<ll> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = v[start];
    }
    else {
        init(v, tree, node*2,   start, (start+end)/2);
        init(v, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

ll query(vector<ll> &tree, int node, int start, int end, int a, int b) {
    if(end < a || b < start) {
        return 0;
    }
    if(a <= start && end <= b) {
        return tree[node];
    }
    ll l = query(tree, node*2,   start, (start+end)/2, a, b);
    ll r = query(tree, node*2+1, (start+end)/2+1, end, a, b);
    return max(l, r);
}

/*
    vector<ll> v(n);
    ll s = 1;
    while(s < n) s *= 2;
    vector<ll> tree(s * 2);
    init(v, tree, 1, 0, n-1);
    update(v, tree, n, idx-1, value);
    cout << query(tree, 1, 0, n-1, idx1-1, idx2-1);
*/

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int1(t)
    while(t--) {
        int1(n)
        vector<ll> v(n);
        map<ll, vector<int>> index;
        for(int i=0; i<n; i++) {
            cin >> v[i];
            if(index.count(v[i]) == 0) {
                index[v[i]] = vector<int>();
            }
            index[v[i]].push_back(i);
        }
        
        ll s = 1;
        while(s < n) s *= 2;
        vector<ll> tree(s * 2);
        init(v, tree, 1, 0, n-1);
        
        bool isYes = true;
        for(auto it = index.begin(); it != index.end(); it++) {
            int last = it->second[0];
            if(query(tree, 1, 0, n-1, last, it->second.back()) > it->first) {
                isYes = false;
                break;
            }
        }
        
        if(isYes) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}



















