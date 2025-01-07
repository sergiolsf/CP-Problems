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
    int n, k, ans = 0;
    cin >> n >> k;
    vi v;
    vi cont;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        v.push_back(x);
    }

    sort(all(v));

    int ini = v[0];
    int c = 1;
    ans = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] != ini) {
            cont.push_back(c);
            c = 1;
            ini = v[i];
            ans++;
        } else {
            c++;
        }
    }

    cont.push_back(c);

    sort(all(cont));

    int sz = cont.size();

    for (int i = 0; i < sz; i++) {
        if (k >= cont[i]) {
            k -= cont[i];
            ans--;
        } else {
            break;
        }
    }
    
    cout << max(ans, 1LL) << endl;
    
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