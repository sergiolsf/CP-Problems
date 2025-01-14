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

    int n, x;
    cin >> n >> x;
    vi p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(all(p));

    int i = 0, j = n-1, ans = 0;

    while (j >= i) {
        if (p[i] + p[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}