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
    vector<pair<char, int>> L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i].first >> L[i].second;
        cin >> R[i].first >> R[i].second;
    }

    int l = 1, r = 1, extra = 0;
    auto [cL1, aL1] = L[0];
    auto [cR1, aR1] = R[0];

    if (cL1 == '+') extra += aL1;
    else extra += aL1-1;

    if (cR1 == '+') extra += aR1;
    else extra += aR1-1;

    for (int i = 1; i < n; i++) {
        auto &[cL, aL] = L[i];
        auto &[cR, aR] = R[i];
        if (cL == '+' && cR == '+') extra += aL+aR;
        else if (cL == '+' && cR == 'x') {
            r += extra;
            extra = r*(aR-1)+aL;
        } else if (cL == 'x' && cR == '+') {
            l += extra;
            extra = l*(aL-1)+aR;
        } else {
            if (aL > aR) {
                l += extra;
                extra = l*(aL-1)+r*(aR-1);
            } else if (aR > aL) {
                r += extra;
                extra = l*(aL-1)+r*(aR-1);
            } else {
                extra += (l+r+extra)*(aL-1);
            }
        }
    }

    cout << l+r+extra << endl;
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