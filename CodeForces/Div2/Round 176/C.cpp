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
    int n, m; cin >> n >> m;
    vi a(m); int sum = 0, q = 0;
    for (auto &i: a) {
        cin >> i;
        sum += i;
        if (i == n) q++;
    }

    sort(all(a));

    int j = 0;
    int cont = m;

    int ans = 0;

    for (int i = m-1; i >= 0; i--) {
        int l = max(n-a[i], 1LL);
        if (l > a[i]) continue;
        sum -= a[i];
        cont--;
        while(a[j] < l) {
            sum -= a[j];
            cont--;
            j++;
        }
        ans += sum-cont*l+cont;
        if (a[i] == n) {
            q--;
            ans -= q;
           // cout << a[i] << " " << sum-cont*l+cont-q << endl;
        }
        
    }

    cout << 2*ans << endl;
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

/*
1
17 10
8 4 11 4 14 8 16 14 17 13
*/