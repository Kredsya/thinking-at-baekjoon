#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, ans;
    string in;
    map<string, int> m;
    while(t--) {
        cin >> n;
        m = map<string, int>();
        for(int i=0; i<n; i++) {
            cin >> in >> in;
            m[in]++;
        }
        ans = 1;
        for(auto &it : m) {
            ans *= (it.second + 1);
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}
