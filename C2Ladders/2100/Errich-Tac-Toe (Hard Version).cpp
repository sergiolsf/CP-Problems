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

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<vector<char>> grid (n+1, vector<char> (n+1));
    vi countO(3, 0);
    vi countX(3, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'X') countX[(i+j)%3]++;
            if (grid[i][j] == 'O') countO[(i+j)%3]++;
        }
    }

    int xi, oj;
    int menor = INF;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            int a = countX[i]+countO[j];
            if (a < menor) {
                menor = a;
                xi = i; oj = j;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int k = (i+j)%3;
            if (k == xi && grid[i][j] == 'X') grid[i][j] = 'O';
            else if (k == oj && grid[i][j] == 'O') grid[i][j] = 'X';
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