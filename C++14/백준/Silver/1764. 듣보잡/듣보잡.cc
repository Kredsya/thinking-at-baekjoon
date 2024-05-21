#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<string> vec;
    vec.resize(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    vector<string> ans;
    string tmp;
    for(int i=0; i<m; i++) {
        cin >> tmp;
        if(binary_search(vec.begin(), vec.end(), tmp)) {
            ans.push_back(tmp);
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(auto it : ans) {
        cout << it << '\n';
    }

    return 0;
}
