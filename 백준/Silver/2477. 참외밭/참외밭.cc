#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int k;
    cin >> k;
    
    int length[6], direction[6];
    bool directionFlag[4] = {};
    vector<int> small;
    for(int i=0; i<6; i++) {
        cin >> direction[i] >> length[i];
        directionFlag[direction[i]-1] = !directionFlag[direction[i]-1];
    }
    
    int ans;
    for(int i=0; i<6; i++) {
        if(directionFlag[direction[i]-1] && directionFlag[direction[(i+7)%6]-1]) {
            ans = length[i] * length[(i+7)%6] - length[(i+9)%6] * length[(i+10)%6];
            break;
        }
    }
    cout << ans * k;
    
    return 0;
}



















