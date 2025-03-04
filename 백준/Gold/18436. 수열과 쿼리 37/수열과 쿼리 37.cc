#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

void init(vector<ll> &v, vector<pair<ll, ll>> &tree, int node, int start, int end) {
    if(start == end) {
        if(v[start] & 1) tree[node] = {0, 1};
        else tree[node] = {1, 0};
    }
    else {
        init(v, tree, node*2,   start, (start+end)/2);
        init(v, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = {tree[node*2].first + tree[node*2+1].first, tree[node*2].second + tree[node*2+1].second};
    }
}

pair<ll, ll> query(vector<pair<ll, ll>> &tree, int node, int start, int end, int a, int b) {
    if(end < a || b < start) {
        return {0, 0};
    }
    if(a <= start && end <= b) {
        return tree[node];
    }
    pair<ll, ll> l = query(tree, node*2,   start, (start+end)/2, a, b);
    pair<ll, ll> r = query(tree, node*2+1, (start+end)/2+1, end, a, b);
    return {l.first + r.first, l.second + r.second};
}

void update(vector<ll> &v, vector<pair<ll, ll>> &tree, int node, int start, int end, int index, pair<ll, ll> diff) {
    if(!(start <= index && index <= end)) return;
    tree[node].first += diff.first;
    tree[node].second += diff.second;
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
    
    int1(n)
    vector<ll> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<pair<ll, ll>> tree(4*n);
    init(v, tree, 1, 0, n-1);
    
    int1(m)
    ll a, b, c;
    while(m--) {
        cin >> a >> b >> c;
        if(a == 1) {
            if(v[b-1] % 2 != c % 2) {
                v[b-1] = c;
                if(c & 1) {
                    update(v, tree, 1, 0, n-1, b-1, {-1, 1});
                }
                else {
                    update(v, tree, 1, 0, n-1, b-1, {1, -1});
                }
            }
        }
        else if(a == 2) {
            cout << query(tree, 1, 0, n-1, b-1, c-1).first << '\n';
        }
        else {
            cout << query(tree, 1, 0, n-1, b-1, c-1).second << '\n';
        }
    }
    
    return 0;
}



















