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
    priority_queue<int> pq;
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    int tot = 0;
    for (int i = s.size()-1; i > 0; i--) {
        if (s[i] == '1') tot++;
        else tot--;
        pq.push(tot);
    }

    int carry = 0;
    int ans = 0;
    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();

        if (u < 0) break;
        carry += u;
        ans++;

        if (carry >= k) {
            cout << ans+1 << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
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
