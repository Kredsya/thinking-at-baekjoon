#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    // time
    long long l = 0, r = (long long)*max_element(times.begin(), times.end()) * (long long)n, m;
    long long challenge, k = times.size(), answer = 0;
    while(l <= r) {
        m = (l + r) / 2;
        challenge = 0;
        for(int i=0; i<k; i++) {
            challenge += m / (long long)times[i];
        }
        
        if(challenge >= n) {
            r = m - 1;
            answer = m;
        }
        else l = m + 1;
    }
    return answer;
}