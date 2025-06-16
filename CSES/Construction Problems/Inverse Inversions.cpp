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
    int n, k; cin >> n >> k;
    int ult = n;
    int sum = 0;
    int d = 0;
    for (; ult >= 1; ult--) {
        if (sum+ult-1 <= k) {
            cout << ult << " ";
            sum += ult-1;
        }
        else {
            d = k-sum;
            break;
        }
    }

    for (int i = 1; i <= ult-1-d; i++) cout << i << " ";
    if (ult) cout << ult << " ";
    for (int i = ult-d; i < ult; i++) cout << i << " ";
    cout << endl;
}

signed main() {
    fastio();
    int t = 1; //cin >> t;
    while (t--) solve();
  
    return 0;
}