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

vvi grid(MAX_N, vi (MAX_N));
vector<vector<bool>> visited(MAX_N, vector<bool> (MAX_N, false));
int n; 

bool possible(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return false;
    return !visited[x][y];
}

void preenche (int dir, int num, int x, int y) {
    if (num >= n*n || x < 1 || x > n || y < 1 || y > n) return;

    grid[x][y] = num;
    visited[x][y] = true;

    if (dir == 3) {
        if (possible(x-1,y)) {
            preenche (0, num+1, x-1, y);
        } else {
            preenche (3, num+1, x, y-1);
        }
    } else if (dir == 0) {
        if (possible(x, y+1)) {
            preenche (1, num+1, x, y+1);
        } else {
            preenche (0, num+1, x-1, y);
        }
    } else if (dir == 1) {
        if (possible(x+1, y)) {
            preenche (2, num+1, x+1, y);
        } else {
            preenche (1, num+1, x, y+1);
        }
    } else {
        if (possible (x, y-1)) {
            preenche (3, num+1, x, y-1);
        } else {
            preenche (2, num+1, x+1, y);
        }
    }
}

// zera tudo o visited
void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
}

void solve() {
    cin >> n;
    init();
    int x = n/2+1;
    int y = n/2;
    if (n%2 == 1) y++;

    preenche(3, 0, x, y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << (j == n ? "\n" : " ");
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