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
    int n, m; cin >> n >> m;
    vvi g(n+1);
    vi cnt(m+1);

    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        cnt[i] = k;
        while(k--) {
            int a; cin >> a;
            g[a].push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int b; cin >> b;
        for (auto e: g[b]) {
            cnt[e]--;
            if (!cnt[e]) ans++;
        }
        cout << ans << endl;
    }
  
    return 0;
}