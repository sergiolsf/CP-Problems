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

const int MAXN = 20;
const int MAXS = (1LL<<16)+5;

int n;
vector<pii> idmusics(MAXN);
vvi memo(MAXS, vi(MAXN));

bool conecta(int a, int b) {
    if (a == -1) return true;
    if (idmusics[a].first == idmusics[b].first) return true;
    if (idmusics[a].second == idmusics[b].second) return true;
    return false;
}

int dp(int m, int ult) {
    int ans = -1;
    if (ult != -1) {
        ans = memo[m][ult];
    }

    if (ans != -1) return ans;

    if (m == (1LL<<n)-1) return memo[m][ult] = 0;

    int d = 0;
    for (int i = 0; i < n; i++) {
        if (!((1LL<<i)&m) && conecta(ult, i)) d = max(d, dp((m|(1LL<<i)), i)+1);
    }
    //cout << ult << " " << m << " " << d << endl;
    if (ult != -1) memo[m][ult] = d;
    return d;
}

void limpa() {
    for (int i = 0; i < MAXS; i++) {
        for (int j = 0; j < MAXN; j++) {
            memo[i][j] = -1;
        }
    }
}

void solve() {
    limpa();
    cin >> n;
    vector<pair<string,string>> musics;
    set<string> st;
    for (int i = 0; i < n; i++) {
        string g, w; cin >> g >> w;
        st.insert(g);
        st.insert(w);
        musics.push_back({g, w});
    }
    int i = 1;
    map<string, int> mp;
    for (auto e: st) {
        mp[e] = i;
        i++;
    }
    i = 0;
    for (auto e: musics) {
        idmusics[i] = {mp[e.first], mp[e.second]};
        i++;
    }

    cout << n-dp(0, -1) << endl;
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