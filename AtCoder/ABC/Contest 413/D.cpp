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
    vi v(n);
    for (auto &i: v) cin >> i;

    sort(all(v));

    bool flag = true;
    for (int i = 1; i < n-1; i++) {
        if (v[i-1]*v[i+1] != v[i]*v[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes\n";
        return;
    }


    vector<pii> vp;
    for (int i = 0; i < n; i++) {
        int c = 1;
        if (v[i] < 0) c = -1;
        vp.push_back({abs(v[i]), c});
    }

    sort(all(vp));

    flag = true;
    for (int i = 1; i < n-1; i++) {
        if (vp[i-1].first*vp[i+1].first != vp[i].first*vp[i].first) {
            flag = false;
            break;
        }
    }

    if (!flag) {
        cout << "No\n";
        return;
    }

    if (vp[0].first == vp[1].first) {
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (vp[i].second == 1) a++;
            else b++;
        }

        if (abs(a-b) < 2) {
            cout << "Yes\n";
            return;
        }

        cout << "No\n";
        return;
    }

    bool f = true;
    int sinal = vp[0].second;
    for (int i = 1; i < n; i++) {
        if (sinal == vp[i].second) {
            f = false;
            break;
        }
        sinal = -sinal;
    }

    if (f && flag) {
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}