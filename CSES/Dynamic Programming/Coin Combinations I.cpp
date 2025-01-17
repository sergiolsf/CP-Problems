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

const int MOD = 1e9+7;

signed main() {
    fastio();

    int n, x;
    cin >> n >> x;

    vi c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vi count(x+1, 0);

    count[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (auto coin: c) {
            if (i-coin >= 0) {
                count[i] = (count[i-coin]+count[i])%MOD;
            }
        }
    }

    cout << count[x] << endl;
    
    return 0;
}