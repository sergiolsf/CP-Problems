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
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    map<int,int> mp;
    set<int> A;
    set<int> B;
    int ans = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (mp.count(x)) {
            mp[x]++;
        } else {
            mp[x] = 1;
        }
    }

    for (auto e: mp) {
        pq.push({e.second, e.first});
    }

    int vez = 0;
    while (!pq.empty()) {
        pii u = pq.top();
        pq.pop();

        if (A.count(u.second) && B.count(u.second)) {
            continue;
        }

        if (vez == 0) {
            A.insert(u.second);
        } else {
            B.insert(u.second);
        }

        if (u.first > 1) {
            pq.push({u.first-1, u.second});
        }

        vez = (vez+1)%2;
    }

    for (auto e: A) {
        if (B.count(e)) {
            ans++;
        } else {
            ans += 2;
        }
    }

    cout << ans << endl;
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