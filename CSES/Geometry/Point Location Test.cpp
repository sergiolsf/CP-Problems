#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int dx1 = x2-x1, dy1 = y2-y1;
    int dx2 = x3-x1, dy2 = y3-y1;

    int mult = dx1*dy2 - dy1*dx2;

    if (mult < 0) cout << "RIGHT" << endl;
    else if (mult > 0) cout << "LEFT" << endl;
    else cout << "TOUCH" << endl;
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