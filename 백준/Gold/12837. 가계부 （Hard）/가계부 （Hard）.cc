#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

void init(vector<ll> &v, vector<ll> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = v[start];
    }
    else {
        init(v, tree, node*2,   start, (start+end)/2);
        init(v, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
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
    return l + r;
}

void update(vector<ll> &v, vector<ll> &tree, int node, int start, int end, int index, ll diff) {
    if(!(start <= index && index <= end)) return;
    tree[node] += diff;
    if(start != end) {
        update(v, tree, node*2,   start, (start+end)/2, index, diff);
        update(v, tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int2(n, q)
    vector<ll> v(n);
    
    vector<ll> tree(4 * n);
    
    ll a, b, c;
    while(q--) {
        cin >> a >> b >> c;
        if(a == 1) {
            v[b-1] += c;
            update(v, tree, 1, 0, n-1, b-1, c);
        }
        else {
            cout << query(tree, 1, 0, n-1, b-1, c-1) << '\n';
        }
    }
    
    return 0;
}



















