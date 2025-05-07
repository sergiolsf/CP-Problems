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

vvi zoo;
vi c;
int n, m; 

const int MAX_N = 11;
const int MAX_A = 70'000;

const int INF = 1'000'000'000'000;

vvi memo(MAX_N, vi(MAX_A, -1));
vi pot(MAX_N);

vi trina(int v) {
    vi ans;
    while (v > 0) {
        ans.push_back(v%3);
        v /= 3;
    }
    //reverse(all(ans));
    return ans;
}

int dp(int i, int v) {
    if (i == n+1) {
        vi a = trina(v);
        vi ani(m+1, 0);
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 0) continue;
            else {
                for (auto e: zoo[i+1]) {
                    ani[e] += a[i];
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            if (ani[i] < 2) return INF;
        }
        return 0;
    }

    int &ans = memo[i][v];
    if (ans != -1) return ans;

    int d1 = dp(i+1, v);
    v += pot[i-1];
    int d2 = dp(i+1, v)+c[i];
    v += pot[i-1];
    int d3 = dp(i+1, v)+2*c[i];

    return ans = min({d1, d2, d3});
}

void init() {
    pot[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        pot[i] = 3*pot[i-1];
    }
}

signed main() {
    fastio();
    init();
    cin >> n >> m;
    zoo.resize(n+1);
    c.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int a; cin >> a;
            zoo[a].push_back(i);
        }
    }

    cout << dp(1, 0) << endl;

    return 0;
}