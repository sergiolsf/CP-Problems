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

const int MAX_N = 5'001;
const int INF = 1e18;

int n;
vi v(MAX_N);
int memo[MAX_N][MAX_N][2];

int dp(int esq, int dir, bool p) {
    if (esq > dir) return 0;
    int &ans = memo[esq][dir][p];
    if (ans != INF) return ans;


    int d1 = dp(esq+1, dir, !p);
    int d2 = dp(esq, dir-1, !p);

    if (p) return ans = max(d1+v[esq], d2+v[dir]);
    return ans = min(d1, d2);
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            memo[i][j][0] = INF;
            memo[i][j][1] = INF;
        }
    }
}

signed main() {
    fastio();
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];

    cout << dp(1, n, true) << endl;
    return 0;
}