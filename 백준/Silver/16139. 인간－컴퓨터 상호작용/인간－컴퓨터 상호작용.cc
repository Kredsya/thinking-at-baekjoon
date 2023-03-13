#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    string s;
    cin >> s;
    
    vector<vector<int>> alpha(26, vector<int>(s.length() + 1));     // [l, r] = r - (l-1)
    for(int i=0; i<s.length(); i++) {
        for(int j=0; j<26; j++) {
            alpha[j][i+1] = alpha[j][i];
        }
        alpha[s[i]-'a'][i+1]++;
    }
    
    #ifndef ONLINE_JUDGE
    for(int i=0; i<26; i++) {
        for(int j=0; j<s.length()+1; j++) {
            cout << alpha[i][j] << ' ';
        }
        cout << '\n';
    }
    #endif
    
    int q;
    cin >> q;
    
    char a;
    int l, r;
    while(q--) {
        cin >> a >> l >> r;
        cout << alpha[a-'a'][r+1] - alpha[a-'a'][l] << '\n';
    }
    
    return 0;
}



















