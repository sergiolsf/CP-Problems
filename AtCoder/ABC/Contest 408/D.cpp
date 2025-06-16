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

const int MAX_N = 200'005;

int n; 
string s; 
int memo[MAX_N][2][2];

int dp(int ind, bool teve, bool ant) {
    if (ind == n) return 0;

    int &ans = memo[ind][teve][ant];
    if (ans != -1) return ans;

    if (s[ind] == '0') {
        if (teve) {
            if (ant) return ans = min(dp(ind+1, true, true)+1, dp(ind+1, true, false));
            else return ans = dp(ind+1, true, false);
        } else {
            return ans = dp(ind+1, false, false);
        }
    } else {
        if (teve) {
            if (ant) {
                return ans = dp(ind+1, true, true);
            } else return ans = dp(ind+1, true, false)+1;
        } else {
            return ans = min(dp(ind+1, true, true), dp(ind+1, false, false)+1);
        }
    }
}

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
}

void solve() {
    cin >> n;
    init();
    cin >> s;
    cout << dp(0, false, false) << endl;
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) solve();
  
    return 0;
}