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

const int MAX_N = 21;

int pao, sal, n, m, p, s;
bitset<MAX_N> nulo;
vector<vector<bool>> comb (MAX_N, vector<bool>(MAX_N, true));

int dp(int i, bitset<MAX_N> bs) {
    if (i > n) return 1;
    int d = dp(i+1, bs);

    if (!comb[i][pao] || !comb[i][sal]) return d;
    for (int j = p+s+1; j <= n; j++) {
        if (!bs[j]) continue;
        if (!comb[j][i]) return d;
    }
    bs[i] = true;
    return dp(i+1, bs) + d;
}

signed main() {
    fastio();
    cin >> n >> m >> p >> s;
    while (m--) {
        int a, b; cin >> a >> b;
        comb[a][b] = false;
        comb[b][a] = false;
    }

    int ans = 0;
    for (pao = 1; pao <= p; pao++) {
        for (sal = p+1; sal <= p+s; sal++) {
            if (!comb[pao][sal]) continue;
            bitset<MAX_N> b = nulo;
            ans += dp(p+s+1, b);
        }
    }

    cout << ans << endl;
    return 0;
}