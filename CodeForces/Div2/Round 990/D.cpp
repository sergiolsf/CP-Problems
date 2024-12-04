#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, maxInd = 0, minVal = 1e17;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pq.push({x,i});
    }

    vi last;

    while (!pq.empty()) {
        pii u = pq.top();
        pq.pop();

        if (maxInd > u.second) {
            last.push_back(u.first);
            minVal = min(minVal, u.first);
        } else if (minVal + 1 < u.first) {
            last.push_back(u.first);
        } else {
            cout << u.first << " ";
            maxInd = max(maxInd, u.second);
        }
    }

    sort(all(last));

    for (auto e: last) {
        cout << e+1 << " ";
    }
    cout << endl;

}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}