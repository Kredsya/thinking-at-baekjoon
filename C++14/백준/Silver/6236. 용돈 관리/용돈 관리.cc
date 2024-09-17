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

int n, m;
vector<int> v;

bool check(int k) {
    int cnt = 0, won = 0;
    for(int i=0; i<n; i++) {
        if(v[i] > k) return false;
        if(won < v[i]) {
            cnt++;
            won = k;
        }
        won -= v[i];
    }
    if(cnt > m) return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    cin >> n >> m;
    v = vector<int>(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    int l = 1, h = 100'000*10'000, k, ans = h;
    while(l <= h) {
        k = (l + h) /  2;
        if(check(k)) {
            h = k - 1;
            ans = k;
        }
        else {
            l = k + 1;
        }
    }
    
    cout << ans;
    
    return 0;
}



















