#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

double changer(string s) {
    if(s == "A+") return 4.5;
    if(s == "A0") return 4.0;
    if(s == "B+") return 3.5;
    if(s == "B0") return 3.0;
    if(s == "C+") return 2.5;
    if(s == "C0") return 2.0;
    if(s == "D+") return 1.5;
    if(s == "D0") return 1.0;
    if(s == "F")  return 0.0;
}

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    string str, grade;
    double credit, s_credit = 0, s_grade = 0;
    
    for(int i=0; i<20; i++) {
        cin >> str >> credit >> grade;
        if(grade == "P") continue;
        s_credit += credit;
        s_grade += changer(grade) * credit;
    }
    
    cout << fixed << setprecision(6) << s_grade / s_credit;
    
    return 0;
}



















