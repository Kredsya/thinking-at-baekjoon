#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> vec;
    vec.resize(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int m, num;
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> num;
        cout << upper_bound(vec.begin(), vec.end(), num) - lower_bound(vec.begin(), vec.end(), num) << '\n';
    }

    return 0;
}
