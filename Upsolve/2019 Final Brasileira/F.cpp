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

const int MOD = 1'000'000'007;
const int MAX = 5'005;

int memo[MAX][MAX];

int mod(int a) {
    return (a%MOD + MOD)%MOD;
}

int dp(int base, int qnt) {
    if (base == 1 || qnt == 0) {
        return 1;
    }

    int &ans = memo[base][qnt];
    if (ans != -1) return ans;

    int d = 0;
    if (qnt >= base) d = mod(d + dp(base, qnt-base));
    d = mod(d + 2*dp(base-1, qnt));
    if (base > 2) d = mod(d - dp(base-2, qnt));

    return ans = d;
}

void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            memo[i][j] = -1;
        }
    }
}
signed main() {
    fastio();
    init();
    int base, qnt; cin >> base >> qnt;
    cout << dp(base, qnt-base) << endl;  
    return 0;
}