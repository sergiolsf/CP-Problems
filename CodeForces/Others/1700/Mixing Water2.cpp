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
    int h, c, t;
    cin >> h >> c >> t;
    int x = floor((double) (c-t)/ (double) (c+h-2*t));

    if ((double) t <= (double) (h+c)/2.0) {
        cout << 2 << endl;
        return;
    }

    int r = x, l = x+1;

    double a1 = fabs( (double) t - (double) (r*h+(r-1)*c)/ (double) (2*r-1));
    double a2 = fabs( (double) t - (double) (l*h+(l-1)*c)/ (double) (2*l-1));

    if (a1 == a2) {
        cout << min(2*r-1, 2*l-1) << endl;;
    } else if (a1 < a2) {
        cout << 2*r-1 << endl;
    } else {
        cout << 2*l-1 << endl;
    }
    
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