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

int n, m;
vvi matriz;
const int MAX_BIT = 31;

vector<pii> passos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int minDist(int x, int y) {
    int ans = (1LL<<32)-1;
    for (int bit = 31; bit >= 0; bit--) {
        vector<vector<bool>> visited(n+1, vector<bool> (m+1, false));
        visited[x][y] = true;
        queue<pii> q; q.push({x, y});
        bool flag = false;
        int A = ans - (1LL<<bit);
        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            if (a == n && b == m) {
                flag = true;
                break;
            }
            for (auto [u, v]: passos) {
                if (a+u < 1 || a+u > n || b+v < 1 || b+v > m) continue;
                if (visited[a+u][b+v]) continue;
                if ((matriz[a+u][b+v]|A) > A) continue;
                visited[a+u][b+v] = true;
                q.push({a+u, b+v});
            }
        }
        if (flag) ans -= (1LL<<bit);
    }
    return ans;
}

signed main() {
    fastio();
    cin >> n >> m;
    int X, Y; cin >> X >> Y;
    matriz.resize(n+1, vi (m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << minDist(1, 1) << " " << minDist(X, Y) << endl;

  
    return 0;
}