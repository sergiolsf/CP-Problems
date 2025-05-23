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

const int MAX_N = 1e6+1;
const int MAX_ALF = 26+1;
const int MOD = 1e9 + 7;

int memo[MAX_N][MAX_ALF];

int dp(int n, int k) {
    if (k > 26) return 0;
    if (n == 0) return 1;

    int &ans = memo[n][k];
    if (ans != -1) return ans;

    int d1 = (k*dp(n-1, k))%MOD;
    int d2 = dp(n-1, k+1);

    return ans = (d1+d2)%MOD;
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_ALF; j++) {
            memo[i][j] = -1;
        }
    }
}

signed main() {
    fastio();
    init();
    int N; cin >> N;

    cout << dp(N, 0) << endl;
  
    return 0;
}