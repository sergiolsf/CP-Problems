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

const int MAX_N = 1005;

int grid[MAX_N][MAX_N];
int res[MAX_N][MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            grid[i][j] = res[i][j] = 0;
        }
    }
}

signed main() {
    fastio();
    init();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= n; j++) {
            char c = s[j-1];
            if (c == '*') grid[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res[i][j] = grid[i][j] + res[i-1][j] + res[i][j-1] - res[i-1][j-1];
        }
    }

    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        int ans = res[y2][x2] - res[y2][x1-1] - res[y1-1][x2] + res[y1-1][x1-1];
        cout << ans << endl;
    }
  
    return 0;
}