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

/*
    vector<ll> v(n);
    ll s = 1;
    while(s < n) s *= 2;
    vector<ll> tree(s * 2);
    init(v, tree, 1, 0, n-1);
    update(v, tree, n, idx-1, value);
    cout << query(tree, 1, 0, n-1, idx1-1, idx2-1);
*/

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

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff) {
    if(index < start || end < index) return;
    tree[node] = tree[node] + diff;
    if(start != end) {
        update(tree, node*2,   start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

void update(vector<ll> &v, vector<ll> &tree, int n, int index, ll val) {
    ll diff = val - v[index];
    v[index] = val;
    update(tree, 1, 0, n-1, index, diff);
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int2(n, q);
    vector<ll> v(n);
    int s = 1;
    while(s < n) s <<= 1;
    vector<ll> tree(s * 2);
    init(v, tree, 1, 0, n-1);
    
    int m, a, b;
    while(q--) {
        cin >> m >> a >> b;
        if(m == 0) {
            if(a > b) swap(a, b);
            cout << query(tree, 1, 0, n-1, a-1, b-1) << '\n';
        }
        else {
            update(v, tree, n, a-1, b);
        }
    }
    
    return 0;
}



















