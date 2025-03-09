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

const int MAXN = 1005;

int MEX(vi a, int fim) {
    vector<bool> v(fim+1, false);
    for (int i = 0; i < fim; i++) {
        v[a[i]] = true;
    }
    for (int i = 0; i <= fim; i++) {
        if (!v[i]) return i;
    }
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;
    int fim = n;
    vi ans;
    for (int i = 0; i < 2*n; i++) {
        if (fim <= 0) break;
        int mex = MEX(a, fim);
        if (mex == fim) {
            ans.pb(fim);
            fim--;
        } else {
            a[mex] = mex;
            ans.pb(mex+1);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ((i == ans.size()-1) ? "" : " ");
    }
    cout << endl;
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