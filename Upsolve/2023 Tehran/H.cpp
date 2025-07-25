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

const int MAX_N = 55;

int n, m;
char grid[MAX_N][MAX_N];
int memo[MAX_N][MAX_N];

bool possible(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > m) return false;
    if (grid[i][j] == 'W') return false;
    return true;
}

int dp(int i, int j) {
    if (i == 1) return 0;

    int &ans = memo[i][j];
    if (ans != -1) return ans;

    int d = 0;
    for (int u = -1; u <= 1; u++) {
        if (possible(i-1, j+u)) d = max(d, dp(i-1, j+u) + (grid[i-1][j+u] == 'B' ? 1 : 0));
    }
    
    return ans = d;
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            memo[i][j] = -1;
        }
    }
}

signed main() {
    fastio();
    init();
    cin >> n >> m;
    vector<pii> whites;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'W') whites.push_back({i, j});
        }
    }

    int ans = 0;
    for (auto [i, j]: whites) {
        init();
        ans = max(ans, dp(i, j));
    }
    cout << ans << endl;
  
    return 0;
}