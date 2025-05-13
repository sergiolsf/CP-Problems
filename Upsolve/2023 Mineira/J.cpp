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

int T;
int N;

vector<vector<pii>> v;
vvi memo(50005, vi(505, -1));

int dp(int qnt, int ind) {
    if (ind == N) return 0;
    if (qnt == 0) return 0;
    int k = v[T][ind].first;
    int m = v[T][ind].second;

    int &ans = memo[qnt][ind];
    if (ans != -1) return ans;

    int d = dp(qnt, ind+1);
    if (k > qnt) return ans = d;
    int d1 = dp(qnt-k, ind+1)+m;
    return ans = max(d, d1);

}

void init(int a, int b) {
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            memo[i][j] = -1;
        }
    }
}

signed main() {
    fastio();
    int n, t; cin >> n >> t;

    v.resize(t+1);
    
    for (int i = 0; i < n; i++) {
        int k, t, m; cin >> k >> t >> m;
        v[t].push_back({k/2, m});
    }
    int ans = 0;
    for (int i = 1; i <= t; i++) {
        int e, d; cin >> e >> d;
        int Q = min(e, d);
        T = i;
        if (v[i].empty()) continue;
        N = v[i].size();
        init(Q, N);
        ans += dp(Q, 0);
    }

    cout << ans << endl;

  
    return 0;
}