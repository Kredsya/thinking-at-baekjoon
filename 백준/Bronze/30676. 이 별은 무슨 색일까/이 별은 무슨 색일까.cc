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
    
    int1(l)
    int wave[7] = {425, 450, 495, 570, 590, 620, 781};
    string color[7] = {"Violet", "Indigo", "Blue", "Green", "Yellow", "Orange", "Red"};
    
    for(int i=0; i<7; i++) {
        if(l < wave[i]) {
            cout << color[i];
            break;
        }
    }
    
    return 0;
}



















