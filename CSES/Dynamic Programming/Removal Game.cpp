#include <bits/stdc++.h>
using namespace std;

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

const int MAXN = 5001;

vi x;
int n;
//vector<vi> memo (MAXN, vi (MAXN, -1));

int dp (int ini, int fim, int player) {
    if (fim < 1 || ini > n) return 0;
    int ans = -1;
    //if (player == 1) ans = memo[ini][fim];
    
    //if (ans != -1) return ans;
    if (ini > fim) return ans = 0;
    if (player == 1) return max(x[ini]+dp(ini+1, fim, 2), x[fim]+dp(ini, fim-1, 2));
    return ans = min(dp(ini+1, fim, 1), dp(ini, fim-1, 1));
}

signed main() {
    fastio();
    cin >> n;
    x.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> x[i];

    cout << dp(1, n, 1) << endl;
   
    return 0;
}