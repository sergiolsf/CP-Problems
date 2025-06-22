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

const int MAX_N = 505;
const int INF = 1e18;

int n, m, k; 
vector<vector<char>> grid (MAX_N, vector<char> (MAX_N));
vector<vector<int>> sum (MAX_N, vector<int> (MAX_N));

int dp (int i, int j) {
    int ans = 0;
    int iniL = max(1LL, i-k), fimL = min(n, i+k);
    int iniC = max(1LL, j-k), fimC = min(m, j+k);
    ans = sum[fimL][fimC] - sum[fimL][iniC-1] - sum[iniL-1][fimC] + sum[iniL-1][iniC-1];
    return ans;
}

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            sum[i][j] = 0;
        }
    }
}

void atualiza() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    init();
    vector<pii> vazios;
    int ouros = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') vazios.push_back({i, j});
            else if (grid[i][j] == 'g') {
                ouros++;
                sum[i][j]++;
            }
        }
    }
    atualiza();
    int menor = INF;
    k--;
    for (auto [a, b]: vazios) {
        menor = min(menor, dp(a, b));
        if (menor == 0) break;
    }
    cout << max(0LL, ouros-menor) << endl;
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