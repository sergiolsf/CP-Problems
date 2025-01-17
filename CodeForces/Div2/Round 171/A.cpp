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
    int x, y, k;
    cin >> x >> y >> k;
    int minimum = min(x,y);

    int a = minimum;

    for (int i = 0; i <= minimum; i++) {
        if (k*k <= minimum*minimum + i*i) {
            a = i;
            break;
        }
    }
    

   if (minimum == y) {
        cout << "0 0 " << a << " " << y << endl;
        cout << x << " 0 " << x-y << " " << x << endl;
   } else {
        cout << "0 0 " << x << " " << a << endl;
        cout << "0 " << y << " " << a << " " << y-x << endl;
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