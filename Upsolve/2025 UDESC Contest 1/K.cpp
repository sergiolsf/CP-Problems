#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_N = 200'005;
const int MOD = 1e9+7; //998'244'353
const int INF = 0x3f3f3f3f3f3f3f3fll; //int: 0x3f3f3f3f
const double PI = acos(-1);

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
int a[MAX_N];
int prox[MAX_N];
int memo[MAX_N][2];

int dp(int ind, bool nested) {
    if (ind == n+1) return 0;

    int &ans = memo[ind][nested];
    if (ans != -1) return ans;

    int d1 = -1;
    if (prox[ind] != 0) d1 = dp(prox[ind], true);
    int d2 = dp(ind+1, false);

    if (!nested) {
        if (d1 != -1) return ans = min(d1+1, d2+1);
        else return ans = d2+1;
    } else {
        if (d1 != -1) return ans = min(d1, d2);
        else return ans = d2;
    }
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        memo[i][0] = memo[i][1] = -1;
    }
}

void solve() {
    init();
    cin >> n;
    map<int,int> mp;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        if (mp.count(a[i])) {
            prox[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }

    int ans = dp(1, false);
    cout <<  ans << endl;
    
}

signed main() {
    fastio();
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}