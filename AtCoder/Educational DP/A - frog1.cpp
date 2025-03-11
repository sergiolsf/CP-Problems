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
int n; 
vi memo(MAXN, -1);

int dp(int i) {
    if (i == n-1) return 0;

    int &ans = memo[i];
            if (ans != -1) return ans;

    int d1 = dp(i+1) + abs(h[i]-h[i+1]);
    int d2 = INF;
    if (i <= n-3) d2 = dp(i+2) + abs(h[i]-h[i+2]);
    return ans = min(d1, d2);
}

signed main() {
    fastio();
    cin >> n;
    h.resize(n);
    for (auto &i: h) cin >> i;

    cout << dp(0) << endl;
  
    return 0;
}