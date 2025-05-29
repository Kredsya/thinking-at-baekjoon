#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) std::vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    cout.precision(10);
    
    double x, y;
    int d, t;
    cin >> x >> y >> d >> t;
    
    double dist = sqrt(x*x + y*y);
    double time = 0;
    
    if(d <= t) {
        cout << fixed << dist;
        return 0;
    }
    
    double jump = -1;
    if(dist <= 2.0 * d) {
        jump = time + 2.0 * t;
    }
    
    while(dist - d >= 0) {
        if(jump == -1 && dist <= 2.0 * d) {
            jump = time + 2.0 * t;
        }
        dist -= d;
        time += t;
    }
    
    if(dist < t + (d - dist)) {
        time += dist;
    }
    else {
        time += t + (d - dist);
    }
    
    if(jump != -1) {
        time = min(time, jump);
    }
    
    cout << fixed << time;
    
    return 0;
}



















