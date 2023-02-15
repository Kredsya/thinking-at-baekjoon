#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

const int N = 60;

#define ONLINE_JUDGE
int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int n;
    cin >> n;
    
    // input and calculate ans
    vector<vector<int>> str(n, vector<int>(N));   // vector of numberse with Base 36
    vector<int> ans(N);
    vector<int> len(n);
    string in;
    for(int i=0; i<n; i++) {
        cin >> in;
        reverse(in.begin(), in.end());
        for(int j=0; j<(int)in.length(); j++) {
            str[i][j] = in[j] - ((in[j] <= '9') ? '0' : 'A' - 10);
            ans[j] += str[i][j];
        }
        len[i] = in.length();
    }
    
    // calculate d and sort
    vector<vector<int>> d(36, vector<int>(N));
    for(int i=0; i<n; i++) {
        for(int j=0; j<len[i]; j++) {
            d[str[i][j]][j] += 35 - str[i][j];
        }
    }
    for(int i=0; i<36; i++) {
        for(int j=0; j<N; j++) {
            if(d[i][j] >= 36) {
                d[i][j+1] += d[i][j] / 36;
                d[i][j] %= 36;
            }
        }
        reverse(d[i].begin(), d[i].end());
    }
    sort(d.begin(), d.end(), greater<vector<int>>());
    
    #ifndef ONLINE_JUDGE
    // print ans
    for(auto it : ans) {
        cout << it << ' ';
    }
    cin.ignore();
    cin.get();
    system("cls");
    #endif
    
    #ifndef ONLINE_JUDGE
    // print d
    for(auto vec : d) {
        for(auto it : vec) {
            cout << it << ' ';
        }
        cout << '\n';
    }
    cin.ignore();
    cin.get();
    system("cls");
    #endif
    
    // add d number of k to ans
    int k;
    cin >> k;
    for(int i=0; i<k; i++) {
        reverse(d[i].begin(), d[i].end());
        for(int j=0; j<N; j++) {
            ans[j] += d[i][j];
        }
    }
    
    // clean ans
    for(int i=0; i<N; i++) {
        ans[i+1] += ans[i] / 36;
        ans[i] %= 36;
    }
    
    #ifndef ONLINE_JUDGE
    // print ans
    for(auto it : ans) {
        cout << it << ' ';
    }
    cin.ignore();
    cin.get();
    system("cls");
    #endif
    
    // convert to string
    reverse(ans.begin(), ans.end());
    int i;
    for(i=0; i<N; i++) {
        if(ans[i] != 0) break;
    }
    string out;
    for(; i<N; i++) {
        out += ans[i] + (ans[i] <= 9 ? '0' : 'A' - 10);
    }
    cout << out;
    if(out == "") cout << "0";
    
    return 0;
}



















