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
        tree[node] = start;
    }
    else {
        init(v, tree, node*2,   start, (start+end)/2);
        init(v, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = (v[tree[node*2]] <= v[tree[node*2+1]]) ? tree[node*2] : tree[node*2+1];
    }
}

ll query(vector<ll> &v, vector<ll> &tree, int node, int start, int end, int a, int b) {
    if(end < a || b < start) {
        return -1;
    }
    if(a <= start && end <= b) {
        return tree[node];
    }
    ll l = query(v, tree, node*2,   start, (start+end)/2, a, b);
    ll r = query(v, tree, node*2+1, (start+end)/2+1, end, a, b);
    if(l == -1) return r;
    if(r == -1) return l;
    return (v[l] <= v[r]) ? l : r;
}

void update(vector<ll> &v, vector<ll> &tree, int node, int start, int end, ll index, ll val) {
    if(index < start || end < index) return;
    
    if(start != end) {
        update(v, tree, node*2,   start, (start+end)/2, index, val);
        update(v, tree, node*2+1, (start+end)/2+1, end, index, val);
        if(v[tree[node*2]] == v[tree[node*2+1]]) {
            tree[node] = min(tree[node*2], tree[node*2+1]);
        }
        else {
            tree[node] = (v[tree[node*2]] < v[tree[node*2+1]]) ? tree[node*2] : tree[node*2+1];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int1(n);
    vector<ll> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    int s = 1;
    while(s < n) s <<= 1;
    vector<ll> tree(s * 2);
    init(v, tree, 1, 0, n-1);
    int1(m)
    int k, a, b;
    while(m--) {
        cin >> k >> a >> b;
        if(k == 1) {
            v[a-1] = b;
            update(v, tree, 1, 0, n-1, a-1, b);
        }
        else {
            cout << query(v, tree, 1, 0, n-1, a-1, b-1) + 1 << '\n';
        }
    }
    
    return 0;
}



















