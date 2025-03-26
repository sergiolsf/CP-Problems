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

void solve() {
    int n, k; cin >> n >> k;
    vi d(n+1);
    for (int i = 1; i <= n; i++) cin >> d[i];

    priority_queue<int> pq;
    int ans = 0;
    int j = 1;
    int m = n/(k+1);
    for (int i = m; i > 0; i--) {
        int p = n-i*(k+1)+1;
        for (; j <= p; j++) {
            pq.push(d[j]);
        }
        ans += pq.top();
        pq.pop();
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