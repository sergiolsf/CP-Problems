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
    int n, k;
    cin >> n >> k;
    vi a;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        int l = -1, r = n;
        while (r-l != 1) {
            int m = (r+l)/2;
            if (a[m] < x) l = m;
            else r = m;
        }
        cout << r+1 << endl;
    }

    
    return 0;
}