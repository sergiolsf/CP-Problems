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
    vvi grid(n+1, vi (m+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    int sum;
    int ant;

    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= m; j++) {
            if (sum == 0) {
                sum++;
            } else {
                if (abs(ant - grid[i][j]) < 2) sum++;
                else sum = 1;
            }
            ant = grid[i][j];
            ans = max(ans, sum);
        }
    }

    for (int j = 1; j <= m; j++) {
        sum = 0;
        for (int i = 1; i <= n; i++) {
            if (sum == 0) {
                sum++;
            } else {
                if (abs(ant - grid[i][j]) < 2) sum++;
                else sum = 1;
            }
            ant = grid[i][j];
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
  
    return 0;
}