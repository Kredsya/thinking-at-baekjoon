#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
#define int1(a) int a;cin>>a;
#define int2(a,b) int a,b;cin>>a>>b;
#define int3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define ints(v,n) vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
#define vsort(v) sort(v.begin(),v.end());
#define csort(v,f) sort(v.begin(),v.end(),f);
#define x first
using namespace std;
using ll = long long;

bool isLunar(int y) {
    return (y%4==0 && y%100!=0) || y%400==0;
}

int main() {
#ifndef ONLINE_JUDGE
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int1(t)
    cin.ignore();
    
    string s;
    int y, m, d, sy, sm, sd;
    int date, sdate;
    while(t--) {
        getline(cin, s);
        
        sscanf(s.c_str(), "%d/%d/%d %d/%d", &m, &d, &y, &sm, &sd);
        if(m == sm && d == sd) {
            cout << "SAME DAY\n";
            continue;
        }
        
        date = d;
        sdate = sd;
        for(int i=1; i<m; i++) date += dayOfMonth[i];
        for(int i=1; i<sm; i++) sdate += dayOfMonth[i];
        sy = y;
        if(abs(date - sdate) > 182) {
            // sy -> y
            if(date < sdate) {
                date += (isLunar(y - 1) ? 366 : 365);
                sy--;
            }
            // y -> sy
            else {
                sdate += (isLunar(y) ? 366 : 365);
                sy++;
            }
        }
        if(m > 2 && isLunar(y)) date++;
        if(sm > 2 && isLunar(sy)) sdate++;
        
        if(abs(date - sdate) > 7) {
            cout << "OUT OF RANGE\n";
            continue;
        }
        int n = sdate - date;
        cout << sm << '/' << sd << '/' << sy << " IS " << abs(n) << (abs(n) == 1 ? " DAY " : " DAYS ") << (n < 0 ? "PRIOR" : "AFTER") << '\n';
    }
    
    return 0;
}



















