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

void init(vector<pair<int, int>> &a, vector<pair<int, int>> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    }
    else {
        init(a, tree, node*2,   start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = make_pair(min(tree[node*2].first, tree[node*2+1].first), max(tree[node*2].second, tree[node*2+1].second));
    }
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int start, int end, int left, int right) {
    if(end < left || right < start) {
        return make_pair(1'000'000'001, 0);
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    pair<int, int> lminmax = query(tree, node*2,   start, (start+end)/2, left, right);
    pair<int, int> rminmax = query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return make_pair(min(lminmax.first, rminmax.first), max(lminmax.second, rminmax.second));
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int2(n, m);
    vector<pair<int, int>> a(n);
    for(int i=0, k; i<n; i++) {
        cin >> k;
        a[i].first = a[i].second = k;
    }
    int s = 1;
    while(s < n) s <<= 1;
    vector<pair<int, int>> tree(s * 2);
    init(a, tree, 1, 0, n-1);
    
    while(m--) {
        int2(left, right);
        pair<int, int> minmax = query(tree, 1, 0, n-1, left-1, right-1);
        cout << minmax.first << ' ' << minmax.second << '\n';
    }
    
    return 0;
}



















