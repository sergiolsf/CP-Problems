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
    int l, r;
    cin >> l >> r;

    int a = l^r;

    int p = -1;

    for (int i = 63; i >= 0; i--) {
        if (a & (1LL << i)) {
            p = i;
            break;
        }
    }

    if (p == -1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    int fat = 1;

    for (int i = 0; i <= p; i++) {
        ans += fat;
        fat *= 2;
    }

    cout << ans << endl;
    
    return 0;
}