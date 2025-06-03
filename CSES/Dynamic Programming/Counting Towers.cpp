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
 
const int MAX_N = 1000005;
const int MOD = 1e9 + 7;
const int MAX_D = 3;
 
int memo[MAX_N][MAX_D][MAX_D][MAX_D];
 
int mod(int a) {
    return (a%MOD + MOD)%MOD;
}
 
int dp(int pos, int a, int b, int c) {
    if (pos == 0) {
        if (a == 0 && b == 0 && c == 0) return 1;
        return 0;
    }
 
    int &ans = memo[pos][a][b][c];
    if (ans != -1) return ans;
 
    if (a == 0 && b == 0) {
        int d1 = dp(pos-1, 0, 0, 0);
        int d2 = dp(pos-1, 1, 0, 0);
        int d3 = dp(pos-1, 1, 1, 0);
        int d4 = dp(pos-1, 0, 0, 0);
        int d5 = dp(pos-1, 1, 1, 1);
        int d6 = dp(pos-1, 0, 1, 0);
        return ans = mod(d1+d2+d3+d4+d5+d6);
    }
 
    if (a == 1 && b == 0 && c == 0) {
        int d1 = dp(pos-1, 0, 0, 0);
        int d2 = dp(pos-1, 1, 0, 0);
        int d3 = dp(pos-1, 1, 1, 0);
        int d4 = dp(pos-1, 0, 1, 0);
        return ans = mod(d1+d2+d3+d4);
    }
 
    if (a == 0 && b == 1 && c == 0) {
        int d1 = dp(pos-1, 0, 0, 0);
        int d2 = dp(pos-1, 0, 1, 0);
        int d3 = dp(pos-1, 1, 1, 0);
        int d4 = dp(pos-1, 1, 0, 0);
        return ans = mod(d1+d2+d3+d4);
    }
 
    if (a == 1 && b == 1 && c == 0) {
        int d1 = dp(pos-1, 0, 0, 0);
        int d2 = dp(pos-1, 1, 0, 0);
        int d3 = dp(pos-1, 0, 1, 0);
        int d4 = dp(pos-1, 1, 1, 0);
        return ans = mod(d1+d2+d3+d4);
    }
 
    if (a == 1 && b == 1 && c == 1) {
        int d1 = dp(pos-1, 0, 0, 0);
        int d2 = dp(pos-1, 1, 1, 1);
        return ans = mod(d1+d2);
    }
    return 0;
}
 
void solve() {
    int n; cin >> n;
    int d = dp(n, 0, 0, 0);
    cout << d << endl;
}
 
void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int a = 0; a < MAX_D; a++) {
            for (int b = 0; b < MAX_D; b++) {
                for (int c = 0; c < MAX_D; c++) {
                    memo[i][a][b][c] = -1;
                }
            }
        }
    }
}
 
signed main() {
    fastio();
    init();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}