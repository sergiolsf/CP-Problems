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
    int n; cin >> n;
    vector<vector<char>> grid (n+1, vector<char> (n+1));
    vi count(3, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'X') count[(i+j)%3]++;
        }
    }

    int k = 0;
    int maior = count[0];
    for (int i = 1; i < 3; i++) {
        if (count[i] < maior) {
            k = i;
            maior = count[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (((i+j)%3 == k) && (grid[i][j] == 'X')) grid[i][j] = 'O';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
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