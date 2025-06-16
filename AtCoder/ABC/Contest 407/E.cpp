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

const int MAX_N = 200'005;

int a[2*MAX_N];

void solve() {
    
    int n; cin >> n;
    for (int i = 1; i <= 2*n; i++) cin >> a[i];

    int ans = 0;
    ans += a[1];
    priority_queue<int> pq;
    for (int i = 2; i <= n; i++) {
        pq.push(a[2*i-1]);
        pq.push(a[2*i-2]);
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
}

signed main() {
    fastio();
    int t; cin >> t; 
    while (t--) {
        solve();
    }
  
    return 0;
}