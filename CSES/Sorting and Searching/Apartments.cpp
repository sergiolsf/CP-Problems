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

signed main() {
    fastio();

    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    int i = 0, j = 0, ans = 0;

    while (i < n && j < m) {
        if (abs (a[i] - b[j]) <= k) {
            i++;
            j++;
            ans++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << ans << endl;
    
    return 0;
}