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
    vector<ll> a(n);
    ll s = 1;
    while(s < n) s *= 2;
    vector<ll> tree(s * 2);
    init(a, tree, 1, 0, n-1);
    update(a, tree, n, idx-1, value);
    cout << query(tree, 1, 0, n-1, idx1-1, idx2-1);
*/

void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if(start == end) {
        tree[node] = start;
    }
    else {
        init(a, tree, node*2,   start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = (a[tree[node*2]] <= a[tree[node*2+1]] ? tree[node*2] : tree[node*2+1]);
    }
}

ll query(vector<ll> &a, vector<ll> &tree, int node, int start, int end, int left, int right) {
    if(end < left || right < start) {
        return -1;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    ll l = query(a, tree, node*2,   start, (start+end)/2, left, right);
    ll r = query(a, tree, node*2+1, (start+end)/2+1, end, left, right);
    if(l == -1) return r;
    if(r == -1) return l;
    return (a[l] <= a[r]) ? l : r;
}

ll area(vector<ll> &a, vector<ll> &tree, int left, int right, ll n) {
    int minIdx = query(a, tree, 1, 0, n-1, left, right);
    ll maxArea = a[minIdx] * (right - left + 1);
    if(left < minIdx) {
        maxArea = max(maxArea, area(a, tree, left, minIdx - 1, n));
    }
    if(minIdx < right) {
        maxArea = max(maxArea, area(a, tree, minIdx + 1, right, n));
    }
    return maxArea;
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    while(1) {
        int1(n);
        if(n == 0) break;
        vector<ll> a(n+1);
        a[n] = -1;
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        int s = 1;
        while(s < n) s <<= 1;
        vector<ll> tree(s * 2);
        init(a, tree, 1, 0, n-1);
        cout << area(a, tree, 0, n-1, n) << '\n';
    }
    
    return 0;
}