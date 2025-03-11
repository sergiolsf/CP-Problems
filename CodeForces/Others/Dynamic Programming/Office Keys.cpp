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

const int INF = 1e18;
const int MAXN = 1'010;
const int MAXK = 2'010;

vi a, b;
int n, k, p;
vvi memo(MAXN, vi (MAXK, -1));

int catchKey(int i, int key) {
    return abs(a[i]-b[key]) + abs(p-b[key]);
}

int dp(int pos, int last) {
    if (pos == n) return -INF;
    if (last == k) return INF;

    int &ans = memo[pos][last];
    if (ans != -1) return ans;

    int d = min(dp(pos, last+1), max(dp(pos+1, last+1), catchKey(pos, last)));
    return ans = d;
}

signed main() {
    fastio();
    cin >> n >> k >> p;
    a.resize(n);
    b.resize(k);    
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;

    sort(all(a));
    sort(all(b));

    cout << dp(0, 0) << endl;
  
    return 0;
}