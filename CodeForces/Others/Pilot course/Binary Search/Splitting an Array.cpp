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

int n, k;
vi a;

bool good (int s) {
    int groups = 0;
    int sum = s+1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > s) return false;
        if (a[i] + sum <= s) sum += a[i];
        else {
            sum = a[i];
            groups++;
        }
    }
    return groups <= k;
}

signed main() {
    fastio();
    cin >> n >> k;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 0; // nao da para formar k grupos com soma menor que l
    int r = 1; // da para formar k grupos com soma maior que ou igual a r

    while (!good(r)) r *= 2;

    while (r-l != 1) {
        int m = (r+l)/2;
        if (good(m)) r = m;
        else l = m;
    }

    cout << r << endl;
  
    return 0;
}