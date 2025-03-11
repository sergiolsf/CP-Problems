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

const int MAXN = 100'010;
const int INF = 1'000'000'000'000'000'000;

vi h;
int n, k; 
vi memo(MAXN, -1);

int dp(int i) {
    if (i == n-1) return 0;

    int &ans = memo[i];
    if (ans != -1) return ans;

    int res = INF;
    for (int j = 1; j <= min(k, (n-1)-i); j++) {
        res = min(res, dp(i+j) + abs(h[i]-h[i+j]));
    }

    return ans = res;
}

signed main() {
    fastio();
    cin >> n >> k;
    h.resize(n);
    for (auto &i: h) cin >> i;

    cout << dp(0) << endl;
  
    return 0;
}