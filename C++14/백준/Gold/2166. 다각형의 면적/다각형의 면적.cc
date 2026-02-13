#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<double>> v = vector<vector<double>>(n, vector<double>(2));
    for(int i=0; i<n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    
    double left = 0, right = 0;
    for(int i=0; i<n; i++) {
        left += v[(i+1)%n][0] * v[i][1];
        right += v[i][0] * v[(i+1)%n][1];
    }
    double sub;
    if(left < right) {
        sub = right - left;
    }
    else {
        sub = left - right;
    }
    printf("%.1lf", sub / 2);
    return 0;
}