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
    int n, l, r;
    cin >> n >> l >> r;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int cont1 = 0;
    int i = 0, j = n-1;
    while (i < j) {
        if (a[i] + a[j] > r) j--;
        else {
            cont1 += j-i;
            i++;
        }
    }

    i = 0; j = n-1;
    int cont2 = 0;
    while (i < j) {
        if (a[i] + a[j] > l-1) j--;
        else {
            cont2 += j-i;
            i++;
        }
    }

    cout << cont1 - cont2 << endl;
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