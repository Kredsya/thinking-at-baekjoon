#include <iostream>
#include <stdio.h>
using namespace std;

/**
 *  1. 기본 입출력, iostream
 *  2. namespace? std?
 *  3. 파일 입출력, fstream
 *  4. fast io
 *  5. 테스트 케이스 쉽게 넣기, freopen
 *  6. C 함수도 쓸만한건 쓴다, sprintf, sscanf
 */

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << a + b << '\n';
    }
    
    return 0;
}