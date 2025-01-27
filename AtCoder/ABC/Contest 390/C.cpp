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

const int INF = 1e5;

signed main() {
    fastio();
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H+1, vector<char> (W+1));
    int esq = INF, dir = 0, cim = INF, bai = 0;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                if (j < esq) esq = j;
                if (j > dir) dir = j;
                if (i < cim) cim = i;
                if (i > bai) bai = i;
            }
        }
    }

    for (int i = cim; i <= bai; i++) {
        for (int j = esq; j <= dir; j++) {
            if (grid[i][j] == '.') {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}