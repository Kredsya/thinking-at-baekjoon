#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    }
    else {
        init(a, tree, node*2,   start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if(end < left || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    ll lsum = query(tree, node*2,   start, (start+end)/2, left, right);
    ll rsum = query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff) {
    if(end < index || index < start) return;
    tree[node] = tree[node] + diff;
    if(start != end) {
        update(tree, node*2,   start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

void update(vector<ll> &a, vector<ll> &tree, int n, int index, ll val) {
    ll diff = val - a[index];
    a[index] = val;
    update(tree, 1, 0, n-1, index, diff);
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    ll s = 1;
    while(s < n) s *= 2;
    vector<ll> tree(s * 2);
    
    init(a, tree, 1, 0, n-1);
    
    m += k;
    ll mode, left, right;
    while(m--) {
        cin >> mode >> left >> right;
        if(mode == 1) {
            update(a, tree, n, left-1, right);
        }
        else {
            cout << query(tree, 1, 0, n-1, left-1, right-1) << '\n';
        }
    }
    
    return 0;
}



















