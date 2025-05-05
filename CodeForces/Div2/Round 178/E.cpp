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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vvi nxt(n+1, vi(k, -1));
    vi pos(k, -1);
    vi ans(n+1, 0);

    for (int i = n; i > 0; --i) {
        for (int j = 0; j < k; j++) {
            nxt[i][j] = pos[j];
        }
        int h = s[i-1]-'a';
        pos[h] = i;
    }
    for (int j = 0; j < k; j++) {
        nxt[0][j] = pos[j];
    }

    for (int i = n; i > 0; i--) {
        int p = 0;
        bool f = false;
        for (int j = 0; j < k; j++) {
            if (nxt[i][j] == -1) {
                ans[i] = 1;
                f = true;
                break;
            }
            p = max(p, nxt[i][j]);
        }
        if (f) continue;
        ans[i] = 1+ans[p];
    }

    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int sz = t.size();

        int pos = 0;
        bool flag = true;
        for (int i = 0; i < sz; i++) {
            int h = t[i]-'a';
            pos = nxt[pos][h];
            if (pos == -1) {
                cout << 0 << endl;
                flag = false;
                break;
            }
        }
        if (!flag) continue;

        cout << ans[pos] << endl;
    }
}

signed main() {
    fastio();
    solve();
    return 0;
}