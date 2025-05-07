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

const int MAX_N = 100'005;
const int NINF = -1'000'000'000'000'000'000;

vvi grid(3, vi (MAX_N));
int n; 
vvi memo(MAX_N, vi(5));

int dp(int i, int d) {
    if (i > n) {
        if (i == n+1 && d == 0) return 0;
        else return NINF;
    }

    int &ans = memo[i][d];
    if(ans != -1) return ans;

    if (d == 0) {
        int k;
        k = (grid[1][i] + grid[1][i+1] + grid[1][i+2] >= 2) + (grid[2][i] + grid[2][i+1] + grid[2][i+2] >= 2);
        int d1 = dp(i+3, 0) + k;
        k = (grid[1][i] + grid[2][i] + grid[2][i+1] >= 2);
        int d2 = dp(i+1, 2) + k;
        k = (grid[1][i] + grid[1][i+1] + grid[2][i] >= 2);
        int d3 = dp(i+1, 1) + k;

        return ans = max({d1, d2, d3});
    } else if (d == 1) {
        int k;
        k = (grid[1][i+1] + grid[1][i+2] + grid[1][i+3] >= 2) + (grid[2][i] + grid[2][i+1] + grid[2][i+2] >= 2);
        int d1 = dp(i+3, 1) + k;
        k = (grid[2][i] + grid[2][i+1] + grid[1][i+1] >= 2);
        int d2 = dp(i+2, 0) + k;
        
        return ans = max(d1, d2);
    } else {
        int k;
        k = (grid[1][i] + grid[1][i+1] + grid[1][i+2] >= 2) + (grid[2][i+1] + grid[2][i+2] + grid[2][i+3] >= 2);
        int d1 = dp(i+3, 2) + k;
        k = (grid[1][i] + grid[1][i+1] + grid[2][i+1] >= 2);
        int d2 = dp(i+2, 0) + k;

        return ans = max(d1, d2);
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            memo[i][j] = -1;
        }
    }
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == 'A') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    cout << dp(1, 0) << endl;


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