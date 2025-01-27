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

vector<vvi> memo;
const int MOD = 1e8;
int k1, k2;

int dp (int n1, int n2, int ult) {
    if (n1 == 0 && n2 == 0) {
        return memo[n1][n2][ult] = 1;
    }

    if (memo[n1][n2][ult] != -1) {
        return memo[n1][n2][ult];
    }

    if (n1 == 0 && n2 > k2) return memo[n1][n2][ult] = 0;
    if (n2 == 0 && n1 > k1) return memo[n1][n2][ult] = 0;
    if (n2 == 0 && n1 <= k1) return memo[n1][n2][ult] = 1;
    if (n1 == 0 && n2 <= k2) return memo[n1][n2][ult] = 1;

    int ans = 0;

    if (ult == 2) {
        int menor = min(n1, k1);
        for (int i = 1; i <= menor; i++) {
            ans = (ans + dp(n1-i, n2, 1))%MOD;
        }
    } else {
        int menor = min(n2, k2);
        for (int i = 1; i <= menor; i++) {
            ans = (ans + dp(n1, n2-i, 2))%MOD;
        }
    }

    memo[n1][n2][ult] = ans;

    return memo[n1][n2][ult];
}

signed main() {
    fastio();

    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;

    memo.resize(103, vvi (103, vi (3, -1)));

    cout << (dp(n1, n2, 1) + dp(n1, n2, 2))%MOD << endl;
    
    return 0;
}