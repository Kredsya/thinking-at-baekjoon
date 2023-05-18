#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LOAD_TXT freopen("input.txt", "r", stdin)
using namespace std;
using ll = long long;

#define inf 2e18

int main() {
#ifndef BOJ
    LOAD_TXT;
#else
    FAST_IO;
#endif
    
    ll n, m;
    cin >> n >> m;
    
    ll a, b, c;
    //vector<vector<ll>> graph(n, vector<ll>(n, inf));
    vector<vector<pair<ll, ll>>> graph(n, vector<pair<ll, ll>>());
    /*
    for(ll i=0; i<m; i++) {
        cin >> a >> b >> c;
        graph[a-1][b-1] = c;
    }
    */
    for(ll i=0; i<m; i++) {
        cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
    }
    
    vector<ll> dist(n, inf);
    dist[0] = 0;
    for(ll _=0; _<n-1; _++) {
        for(ll from=0; from<n; from++) {
            if(dist[from] == inf) continue;
            /*
            for(ll to=0; to<n; to++) {
                if(graph[from][to] == inf) continue;
                if(dist[to] > dist[from] + graph[from][to]) {
                    dist[to] = dist[from] + graph[from][to];
                }
            }
            */
            for(auto to : graph[from]) {
                if(dist[to.first] > dist[from] + to.second) {
                    dist[to.first] = dist[from] + to.second;
                }
            }
        }
    }
    
    /*
    cout << "===dist===\n";
    for(auto it : dist) {
        cout << it << '\n';
    }
    cout << "===dist===\n";
    */
    
    bool negative = false;
    for(ll from=0; from<n; from++) {
        if(dist[from] == inf) continue;
        /*
        for(ll to=0; to<n; to++) {
            if(dist[to] > dist[from] + graph[from][to]) {
                negative = true;
                break;
            }
        }
        */
        for(auto to : graph[from]) {
            if(dist[to.first] > dist[from] + to.second) {
                negative = true;
                break;
            }
        }
        if(negative) break;
    }
    
    if(negative) {
        cout << "-1";
    }
    else {
        for(ll i=1; i<n; i++) {
            if(dist[i] == inf) {
                cout << "-1\n";
            }
            else {
                cout << dist[i] << '\n';
            }
        }
    }
    
    return 0;
}



















