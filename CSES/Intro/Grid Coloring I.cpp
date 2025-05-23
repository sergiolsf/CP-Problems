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

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n+1, vector<char> (m+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if ((i+j)%2) {
                if (c == 'C') grid[i][j] = 'D';
                else grid[i][j] = 'C';
            } else {
                if (c == 'A') grid[i][j] = 'B';
                else grid[i][j] = 'A';
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
           cout << grid[i][j];
        }
        cout << endl;
    }
  
    return 0;
}