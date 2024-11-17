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
    int n, m, L;
    cin >> n >> m >> L;
    priority_queue<int> pq;
    
    vector<pii> hurdles(n+1);
    for (int i = 1; i <= n; i++) {
        int l,r;
        cin >> l >> r;
        hurdles[i].first = l;
        hurdles[i].second = r-l+2;
    }

    vector<pii> power (m+1);
    for (int i = 1; i <= m; i++) {
        cin >> power[i].first >> power[i].second;
    }

    int i = 1;
    int actual_power = 1;
    int j = 1;
    int ans = 0;

    while (i <= n) {
        int pos = hurdles[i].first;
        while (power[j].first < pos && j <= m) {
            pq.push(power[j].second);
            j++;
        }

        while(actual_power < hurdles[i].second) {
            if (pq.empty()) {
                cout << "-1" << endl;
                return;
            }
            actual_power += pq.top();
            pq.pop();
            ans++;
        }

        i++;
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