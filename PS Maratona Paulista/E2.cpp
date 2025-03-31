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

signed main() {
    fastio();
    int n, q; cin >> n >> q;
    vi a(n);
    for (auto &i: a) cin >> i;

    deque<int> acum;
    acum.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        acum.push_back(__gcd(a[i], acum.back()));
    }

    while (q--) {
        int i, x; cin >> i >> x;
        if (i == 1) {
            acum.push_back(__gcd(x, acum.back()));
        } else if (i == 2) {
            while (x--) acum.pop_back();
        } else {
            if (acum.back()%x) cout << "NAO\n";
            else cout << "SIM\n";
        }
    }

  
    return 0;
}