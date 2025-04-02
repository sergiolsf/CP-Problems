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

const int MAX_N = 30;

vi g(MAX_N, 0);
vi pai(MAX_N, 0);
vvi gr(MAX_N);
bool escape = false;
int ciclos = 0;
int ans = 0;
vector<bool> visited(MAX_N, false);
vector<bool> ccl(MAX_N, false);

void dfs(int u) {
    visited[u] = true;
    if (u == g[u]) return;
    for (auto e: gr[u]) {
        if (!visited[e]) {
            ans++;
            pai[e] = u;
            dfs(e);
        }
        else if (pai[u] != e && !ccl[e]) {
            ccl[e] = true;
            ccl[u] = true;
            //cout << u << " " << e << endl;
            ans++; ciclos++;
        }
    }
}


signed main() {
    fastio();
    int n; cin >> n;
    string s, t; cin >> s >> t;

    for (int i = 0; i < n; i++) {
        int d1 = s[i]-'a'+1;
        int d2 = t[i]-'a'+1;
        if (g[d1] && g[d1] != d2) {
            cout << -1 << endl;
            return 0;
        }

        if (g[d1] != d2) {
            gr[d1].push_back(d2);
            gr[d2].push_back(d1);
        }

        g[d1] = d2;
    }

    for (int i = 1; i <= 26; i++) {
        if (!g[i]) escape = true;
    }

    int cc = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (g[i] && !visited[i]) {
            dfs(i);
            cc++;
        }
    }

    if (ciclos != cc) escape = true;

    ans += ciclos;

    if (escape) cout << ans << endl;
    else cout << -1 << endl;  
    return 0;
}