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

const int INF = 1'000'000'000'000'000'000;
const int MAX_N = 500'005;

vi menor(MAX_N), maior(MAX_N);
vector<bool> visited(MAX_N);
vi ans(MAX_N);
vi a(MAX_N);

int dp (int i, bool f) {
    if (visited[i]) return ans[i];
    if (maior[menor[i]] == i || menor[maior[i]] == i) {
        ans[i] = ans[maior[i]] = ans[menor[i]] = a[maior[i]];
        visited[i] = true;
        visited[maior[i]] = true;
        visited[menor[i]] = true;
        return ans[i];
    }

    if (f) ans[i] = dp(menor[i], false);
    else ans[i] = dp(maior[i], true);
    visited[i] = true;

    return ans[i];
}


void init(int n) {
    for (int i = 0; i < n; i++) {
        menor[i] = 0;
        maior[i] = 0;
        visited[i] = false;
    }
}

void solve() {
    int n; cin >> n;
    init(n);
    
    vector<pii> vp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vp.push_back({a[i], i});
    }
    
    sort(all(vp));

    int ind = 0, me = 0;
    for (int i = 0; i < n; i++) {
        int f = vp[i].first, s = vp[i].second;
        if (f > me) {
            menor[s] = max(ind, s);
            me = f;
        } else if (f == me) {
            menor[s] = s;
        }
        ind = max(ind, s);
    }

    int ma = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > ma) {
            ma = a[i];
            ind = i;
        } else if (a[i] == ma) {

        }
        maior[i] = ind;
    }

    for (int i = 0; i < n; i++) dp(i, true);

   for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n-1 ? "\n" : " ");
   }
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}