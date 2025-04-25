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

void solve(int z) {
    int n, m; cin >> n >> m;
    char d1, d2; cin >> d1 >> d2;
    vector<vector<char>> grid(n+1, vector<char> (m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i =  1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'V') {
                if (i+1 <= n && grid[i+1][j] != 'V') grid[i+1][j] = d1;
                if (i-1 >= 1 && grid[i-1][j] != 'V') grid[i-1][j] = d1;
                if (j+1 <= m && grid[i][j+1] != 'V') grid[i][j+1] = d1;
                if (j-1 >= 1 && grid[i][j-1] != 'V') grid[i][j-1] = d1;

                if (i+1 <= n) {
                    if (j+1 <= m && grid[i+1][j+1] == '.') grid[i+1][j+1] = d2;
                    if (j-1 >= 1 && grid[i+1][j-1] == '.') grid[i+1][j-1] = d2;
                }

                if (i-1 >= 1) {
                    if (j+1 <= m && grid[i-1][j+1] == '.') grid[i-1][j+1] = d2;
                    if (j-1 >= 1 && grid[i-1][j-1] == '.') grid[i-1][j-1] = d2;
                }
            }
        }
    }

    cout << "Airplane #" << z << ":\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '.') cout << '0';
            else cout << grid[i][j];
        }
        cout << endl;
    }
}

signed main() {
    fastio();
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
  
    return 0;
}