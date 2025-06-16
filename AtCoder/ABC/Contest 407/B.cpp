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
    int x, y; cin >> x >> y;
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i+j >= x || abs(i-j) >= y) {
                ans ++;
            }
        }
    }

    double res = (double) ans / 36.0;

    cout << fixed << setprecision(20) << res << endl;
  
    return 0;
}