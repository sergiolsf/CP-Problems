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

const int INF = 1e11;

void solve() {
    int n;
    cin >> n;
    vi k(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vi ent;
    for (int i = 0; i < n; i++) {
        ent.pb(k[i]-h[i]+1);
    }

    sort(all(ent));

    int ans = 0;

    int i = 0, j = 0;
    int cont = 0;
    int ini = INF, fim;

    while (i < n) {
        if (j < n && ent[j] < k[i]) {
            ini = min(ini, ent[j]);
            j++;
            cont++;
        } else if (j < n && ent[j] == k[i]) {
            ini = min(ini, ent[j]);
            bool first = true;
            while (j < n && ent[j] == k[i]) {
                j++;
                if (!first) cont++;
                first = false;
            }
            i++;
        } else {
            i++;
            cont--;
        }

        if (cont == 0) {
            i--;
            fim = k[i];
            i++;

            int g = fim-ini+1;
            ans += (g*(g+1))/2;

            ini = INF;
        }
    }

    cout << ans << endl;
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