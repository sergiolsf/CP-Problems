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

const int INF = 1'000'000'000'000'000;
vvi grid;
vvi memo;
int h, w, x; 

int dp(int a, int b) {
    if (a == 1 && b == 1) {
        int r = grid[a][b] + x;
        if (r < 0) return -INF;
        return r;
    }

    int &ans = memo[a][b];
    if (ans != INF) return ans;

    int c = a-1, d = b;
    int e = -INF;
    if (c >= 1 && d >= 1) {
        e = max(e, dp(c, d));
    }

    c = a; d = b-1;
    if (c >= 1 && d >= 1) {
        e = max(e, dp(c, d));
    }

    int r = e+grid[a][b];
    if (r < 0 || e < 0) return ans = -INF;
    return ans = r;
}

bool good(int g) {
    x = g;
    
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            memo[i][j] = INF;
        }
    }

    return (dp(h, w) >= 0);
}

signed main() {
    fastio();
    cin >> h >> w;

    grid.resize(h+1, vi(w+1));
    memo.resize(h+1, vi(w+1, -1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
        }
    }
    int SP = 0;
    vi P(h+w+1);
    for (int i = 1; i < h+w; i++) {
        cin >> P[i];
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            grid[i][j] -= P[i+j-1];
        }
    }

    int lo = -1, hi = 1;
    while (!good(hi)) hi *= 2;
    while (hi-lo > 1) {
        int m = (hi + lo)/2;
        if (good(m)) hi = m;
        else lo = m;
    }

    cout << hi << endl;
  
    return 0;
}