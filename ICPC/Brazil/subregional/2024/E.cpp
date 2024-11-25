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
}

int N;
vvi grid;
bool row_cresc, col_cresc;

signed main() {
    fastio();
    cin >> N;

    grid.resize(N, vi(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][1] > grid[0][0]) row_cresc = true;
    if (grid[1][0] > grid[0][0]) col_cresc = true;


    if (row_cresc) {
        if (col_cresc) cout << 0 << endl;
        else cout << 3 << endl;
    } else {
        if (col_cresc) cout << 1 << endl;
        else cout << 2 << endl;
    }
    
    return 0;
}