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

const int MAX_N = 200'005;

vvi col(MAX_N), lin(MAX_N);
vi contCol(MAX_N), contLin(MAX_N);

signed main() {
    fastio();
    int h, w, n; cin >> h >> w >> n;
    for (int  i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        contCol[y]++;
        contLin[x]++;
        col[y].push_back(x);
        lin[x].push_back(y);
    }

    int q; cin >> q;
    while (q--) {
        int t, p; cin >> t >> p;
        if (t == 2) {
            cout << max(0LL, contCol[p]) << endl;
            if (contCol[p] > 0) {
                for (auto e: col[p]) {
                    contLin[e]--;
                }
            }

            contCol[p] = 0;
        } else {
            cout << max(0LL, contLin[p]) << endl;
            if (contLin[p] > 0) {
                for (auto e: lin[p]) {
                    contCol[e]--;
                }
            }

            contLin[p] = 0;
        }
    }
  
    return 0;
}