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

const int MAX_N = 505;
const int INF = 1'000'000'000'000;

int n, m, l;
int A[MAX_N];
int memo[MAX_N][MAX_N];

int changeMin (int s, int i) {
    int ans = 0;
    for (int k = i+l; k < n; k += l) {
        if (A[k] <= s) ans += s-A[k];
        else ans += m-A[k]+s;
    }
    return ans;
}

int dp(int i, int sum) {
    if (i == l) {
        if (sum == 0) return 0;
        return INF;
    }

    int &ans = memo[i][sum];
    if (ans != -1) return ans;

    int dmin = INF;
    for (int j = 0; j < m; j++) {
        int ss = (sum + A[i] + j)%m;
        int d = dp(i+1, ss);

        if (d >= INF) continue;
        dmin = min(dmin, changeMin((A[i]+j)%m, i) + d + j);
    }

    return ans = dmin;
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            memo[i][j] = -1;
        }
    }
}

signed main() {
    fastio();
    init();

    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << dp(0, 0) << endl;
  
    return 0;
}