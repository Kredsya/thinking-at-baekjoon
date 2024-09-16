#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
#define vsort(v) sort(v.begin(),v.end());
#define csort(v,f) sort(v.begin(),v.end(),f);
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int2(n, c);
    ints(x, n);
    vsort(x);
    
    int low = 1, high = x[n-1] - x[0], mid, ans = 0, cnt, last;
    while(low <= high) {
        mid = (low + high) / 2;
        cnt = 1;
        last = x[0];
        for(int i=1; i<n; i++) {
            if(x[i] - last >= mid) {
                cnt++;
                last = x[i];
            }
        }
        if(cnt >= c) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}



















