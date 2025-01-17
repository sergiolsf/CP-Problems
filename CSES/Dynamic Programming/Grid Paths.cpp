#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int MOD = 1e9+7;

vector<vector<char>> grid;
int n;
vvi memo;

int paths(int i, int j) {
    if (grid[i][j] == '*') return 0;

    if (i == 1 && j == 1) {
        return 1;
    }

    if (i <= 0 || j <= 0) return 0;

    if (memo[i][j] > -1) return memo[i][j];

    int up = paths(i-1, j);
    int left = paths(i, j-1);

    memo[i][j] = (up+left)%MOD;

    return memo[i][j];    
}

signed main() {
    fastio();
    cin >> n;

    grid.resize(n+1, vector<char> (n+1));
    memo.resize(n+1, vi(n+1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << paths(n, n) << endl;
    
    return 0;
}