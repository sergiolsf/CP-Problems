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
    int n, sum = 0, sumP = 0, sumI = 0, numI = 0, numP = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if (i%2 == 0) {
            sumP += x;
            numP++;
        }
        else {
            sumI += x;
            numI++;
        }
    }

    if (sum%n == 0 && (sumP%numP == 0) && (sumI%numI == 0) && (sumP/numP == sumI/numI)) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
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