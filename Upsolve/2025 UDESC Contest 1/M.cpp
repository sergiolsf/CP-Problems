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
    int n, a, b; cin >> n >> a >> b;
    vector<pii> vp;
    vi alt(n+1);
    int h = 0;

    for (int i = 1; i <= n; i++) {
        int aa; cin >> aa;
        h += aa;
        alt[i] = h;
        vp.push_back({h, i});
    }

    sort(all(vp));

    int k; cin >> k;

    int H;
    int andar;

    if (vp[n-1].second != k) {
        H = vp[n-1].first;
        andar = vp[n-1].second;
    } else {
        H = vp[n-2].first;
        andar = vp[n-2].second;
    }

    if (H+a >= b+alt[k]) {
        cout << "SIM\n" << andar << endl;
    } else {
        cout << "NAO\n";
    }
  
    return 0;
}