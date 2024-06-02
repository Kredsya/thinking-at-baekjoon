#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) unsigned int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<unsigned int>v(n);for(unsigned int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int2(k, n)
    ints(v, k)
    
    unsigned int start = 1, end = 2147483647, mid, cnt, ans = 0;
    while(start <= end) {
        mid = (start + end) / 2;
        
        cnt = 0;
        for(unsigned int stick : v) {
            cnt += stick / mid;
        }
        
        if(cnt < n) {
            end = mid - 1;
        }
        else if(cnt >= n) {
            ans = max(ans, mid);
            start = mid + 1;
        }
    }
    
    cout << ans;
    
    return 0;
}



















