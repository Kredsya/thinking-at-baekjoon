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
    
    int n;
    cin >> n;
    vector<int> a(n);
    double sum = 0;
    unordered_map<int, int> s;
    int max=-10000, min=100000;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
        if(s.count(a[i]) > 0) {
            s[a[i]]++;
        }
        else {
            s.insert({a[i], 0});
        }
        max = ::max(a[i], max);
        min = ::min(a[i], min);
    }
    
    
    vector<pair<int, int>> pairs;
    for (const auto& elem : s) {
        pairs.emplace_back(elem.first, elem.second);
    }
    std::sort(pairs.begin(), pairs.end(),
        [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
    });
    int often = pairs[0].second;
    vector<int> v;
    for(auto it = pairs.begin(); it!=pairs.end(); it++) {
        if((*it).second == often) {
            v.push_back((*it).first);
        }
        else break;
    }
    sort(v.begin(), v.end());
    
    sort(a.begin(), a.end());
    
    cout << (int)round(sum/n) << '\n' << a[n/2] << '\n' << (v.size() < 2 ? v[0] : v[1]) << '\n' << max-min;
    
    //첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
    //둘째 줄에는 중앙값을 출력한다.
    //셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
    //넷째 줄에는 범위를 출력한다.
    
    return 0;
}



















