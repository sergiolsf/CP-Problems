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
    int n, m, q; cin >> n >> m >> q;
    vector<bool> L(n+1, false);
    vector<bool> C(m+1, false);
    while (q--) {
        int i; cin >> i;
        if (i == 1) {
            int x, y; cin >> x >> y;
            L[x] = true;
            C[y] = true;
        } else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            if ((C[y1] || L[x1]) && (C[y2] || L[x2])) cout << "SIM\n";
            else cout << "NAO\n";
        }
    }
  
    return 0;
}