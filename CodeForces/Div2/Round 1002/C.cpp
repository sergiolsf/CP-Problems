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
    int n;
    cin >> n;
    vvi a(n, vi (n));
    vvi sum(n, vi(n+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    //vector<set<int>> st (n);
    for (int i = 0; i < n; i++) {
        sum[i][0] = 0;
        int k = 1;
       // st[i].insert(0);
        for (int j = n-1; j >= 0; j--) {
            sum[i][k] += sum[i][k-1] + a[i][j];
            //st[i].insert(sum[i][k]);
            k++;
        }
    }

    sort (all(sum));

    int u = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (sum[i][j] == u) {
                u++;
                break;
            }
        }
    }

    cout << u << endl;
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