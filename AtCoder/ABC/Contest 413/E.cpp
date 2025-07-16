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
    int n; cin >> n;
    list<vi> ls;
    for (int i = 1; i <= (1<<n); i++) {
        int val; cin >> val;
        vi v; v.push_back(val);
        ls.push_back(v);
    }

    while (ls.size() > 1) {
        for (auto it = ls.begin(); it != ls.end(); it++) {
            vi ve = *it;
            it = ls.erase(it);
            vi vd =  *it;
            bool f = true;
            for (int i = 0; i < vd.size(); i++) {
                if (ve[i] < vd[i]) break;
                if (vd[i] < ve[i]) {
                    f = false;
                    break;
                }
            }

            if (f) {
                for (auto e: vd) ve.push_back(e);
                *it = ve;
            } else {
                for (auto e: ve) vd.push_back(e);
                *it = vd;
            }
        }
    }

    auto it = ls.begin();
    vi v = *it;
    for (int i = 0; i < (1<<n); i++) {
        cout << v[i] << (i == (1<<n)-1 ? "\n" : " ");
    }

    
}


signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}