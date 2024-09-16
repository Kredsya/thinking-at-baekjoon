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

int N, M;
vector<int> v;

bool check(int len) {
    int stock = 0, cnt = 0;
    for(int i=0; i<N; i++) {
        if(stock + v[i] <= len) {
            stock += v[i];
        }
        else {
            if(v[i] > len) return false;
            stock = v[i];
            cnt++;
        }
    }
    cnt++;
    if(cnt > M) return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    cin >> N >> M;
    v = vector<int>(N);
    for(int i=0; i<N; i++) cin >> v[i];
    
    int l = 1, h = 1'000'000'000, m, ans = 1'000'000'000;
    while(l <= h) {
        m = (l + h) / 2;
        if(check(m)) {
            h = m - 1;
            ans = min(ans, m);
        }
        else {
            l = m + 1;
        }
    }
    
    cout << ans;
    
    return 0;
}



















