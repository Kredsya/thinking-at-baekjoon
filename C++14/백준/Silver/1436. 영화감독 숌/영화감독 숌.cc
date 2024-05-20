#include <bits/stdc++.h>
using namespace std;

using LL = long long int;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL), cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int cnt = 0, len, i;
    char str[20] = {0};
    for(i=666; cnt<n; i++) {
        sprintf(str, "%d", i);
        len = strlen(str);
        for(int j=0; j<len-2; j++) {
            if(str[j] == '6' && str[j+1] == '6' && str[j+2] == '6') {
                cnt++;
                break;
            }
        }
    }

    cout << i-1;

    return 0;
}
