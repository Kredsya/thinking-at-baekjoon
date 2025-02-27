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

ll q = 1'000'000'007;

/*
    vector<ll> a(n);
    ll s = 1;
    while(s < n) s *= 2;
    vector<ll> tree(s * 2);
    init(a, tree, 1, 0, n-1);
    update(a, tree, n, idx-1, value);
    cout << query(tree, 1, 0, n-1, idx1-1, idx2-1);
*/

ll inverse(ll a) {
    if(a == 1) return 1;
    ll res = 1;
    ll e = q - 2;
    while(e > 0) {
        if(e & 1 == 1) {
            res = (res * a) % q;
        }
        a = (a * a) % q;
        e >>= 1;
    }
    return res;
}

void init(vector<ll> &a, vector<ll> &tree, vector<bool> &zero, int node, int start, int end) {
    if(start == end) {
        tree[node] = (a[start] ? a[start] : 1);
        zero[node] = (a[start] == 0);
    }
    else {
        init(a, tree, zero, node*2,   start, (start+end)/2);
        init(a, tree, zero, node*2+1, (start+end)/2+1, end);
        tree[node] = ((tree[node*2] ? tree[node*2] : 1) * (tree[node*2+1] ? tree[node*2+1] : 1)) % q;
        zero[node] = zero[node*2] || zero[node*2+1];
    }
}

ll query(vector<ll> &tree, vector<bool> &zero, int node, int start, int end, int left, int right) {
    if(end < left || right < start) {
        return 1;
    }
    if(left <= start && end <= right) {
        if(zero[node]) return 0;
        return tree[node];
    }
    ll lmul = query(tree, zero, node*2,   start, (start+end)/2, left, right);
    ll rmul = query(tree, zero, node*2+1, (start+end)/2+1, end, left, right);
    return lmul * rmul % q;
}

void update(vector<ll> &tree, vector<bool> &zero, int node, int start, int end, int index, pair<ll, ll> diff, bool iszero) {
    if(index < start || end < index) return;
    tree[node] *= diff.first;
    tree[node] %= q;
    tree[node] *= diff.second;
    tree[node] %= q;
    if(start != end) {
        update(tree, zero, node*2,   start, (start+end)/2, index, diff, iszero);
        update(tree, zero, node*2+1, (start+end)/2+1, end, index, diff, iszero);
        zero[node] = zero[node*2] || zero[node*2+1];
    }
    else {
        zero[node] = iszero;
    }
}

void update(vector<ll> &a, vector<ll> &tree, vector<bool> &zero, int n, int index, ll val) {
    pair<ll, ll> diff = {inverse(a[index]), (val ? val : 1)};
    a[index] = (val ? val : 1);
    update(tree, zero, 1, 0, n-1, index, diff, (val == 0));
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int3(n, m, k);
    vector<ll> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int s = 1;
    while(s < n) s <<= 1;
    vector<ll> tree(s * 2);
    vector<bool> zero(s * 2);
    init(a, tree, zero, 1, 0, n-1);
    for(int i=0; i<n; i++) {
        if(a[i] == 0) a[i] = 1;
    }
    
    int b, l, r;
    for(int i=0; i<m + k; i++) {
        cin >> b >> l >> r;
        if(b == 1) {
            update(a, tree, zero, n, l-1, r);
        }
        else {
            cout << query(tree, zero, 1, 0, n-1, l-1, r-1) << '\n';
        }
    }
    
    return 0;
}



















