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

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<char>> grid(n+1, vector<char> (n+1, '.'));
    int i = 1;
    while (k && i <= n) {
        k--;
        grid[i][i] = 'R';
        i += 2;
    }
    if (k) {
        cout << -1 << endl;
    } else {
        for (int k = 1; k <= n; k++) {
            for (int j = 1; j <= n; j++) {
                cout << grid[k][j];
            }
            cout << endl;
        }
    }
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