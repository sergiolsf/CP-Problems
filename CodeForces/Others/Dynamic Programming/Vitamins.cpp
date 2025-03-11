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

const int INF = 1e18;
const int MAXN = 1'010;
const int MAXV = 10;

vi c;
vi v;
int n;

vvi memo (MAXN, vi (MAXV, -1));

int dp(int i, int vitamins) {
    if (vitamins == 7) return 0;
    if (i == n+1) return INF;

    int &ans = memo[i][vitamins];
    if (ans != -1) return ans;

    return ans = min(dp(i+1, vitamins), dp(i+1, vitamins|v[i])+c[i]);
}

signed main() {
    fastio();
    cin >> n;
    c.resize(n+1);
    v.resize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        string s; cin >> s;
        for (auto e: s) {
            v[i] += 1LL << (e-'A');
        }
    }

    int ans = dp(1, 0);
    if (ans >= INF) ans = -1;

    cout << ans << endl;
    return 0;
}