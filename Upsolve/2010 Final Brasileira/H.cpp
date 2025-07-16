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

const int MAX_N = 105;
const int MOD = 100'000'000;

int m, n; 
int memo[MAX_N][MAX_N][MAX_N];
vector<pii> vp;

int dp(int ind, int ult, int pen) {
    if (ind > n+1) {
        auto [ulti, ultf] = vp[ult];
        if (ultf == m) {
            return 1;
        }
        return 0;
    }

    int &ans = memo[ind][ult][pen];
    if (ans != -1) return ans;    

    auto [indi, indf] = vp[ind];
    auto [ulti, ultf] = vp[ult];
    auto [peni, penf] = vp[pen];

    if (indi > ultf) return ans = 0;
    if (indf <= ultf) return ans = dp(ind+1, ult, pen)%MOD;
    if (indi <= penf) return ans = dp(ind+1, ult, pen)%MOD;
    return ans = (dp(ind+1, ind, ult)%MOD + dp(ind+1, ult, pen)%MOD)%MOD;
}

void init() {
    vp.clear();
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            for (int k = 0; k < MAX_N; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
}

void solve() {
    init();

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        vp.push_back({x,y});
    }

    vp.push_back({-1,0});
    vp.push_back({-2,-1});
    sort(all(vp));

    cout << dp(2, 1, 0) << endl;
}

signed main() {
    fastio();
    cin >> m >> n;
    while (m != 0 || n != 0) {
        solve();
        cin >> m >> n;
    }
  
    return 0;
}