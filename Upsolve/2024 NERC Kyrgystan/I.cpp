#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() {
    fastio();
    int n, D; cin >> n >> D;
    vi c(n+1, 0);
    int M = 0;
    for (int i = 0; i < D; i++) {
        int f, s; cin >> f >> s;
        c[f]++; c[s]++;
        M = max({M, c[f], c[s]});
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(M-c[i]);
    }

    while (true) {
        int u = pq.top(); pq.pop();
        int v = pq.top(); pq.pop();
        if (u == 0) break;
        if (v == 0) {
            M++;
            priority_queue<int> aux;
            while (!pq.empty()) {
                int w = pq.top(); pq.pop();
                aux.push(w+1);
            }
            pq = aux;
            pq.push(u+1);
            pq.push(v+1);
        } else {
            pq.push(u-1);
            pq.push(v-1);
        }
    }

    cout << M << endl;
  
    return 0;
}