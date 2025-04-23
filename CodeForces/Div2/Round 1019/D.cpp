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
    int n; cin >> n;
    int l = 1, r = n;
    vi a(n+1);
    vi ans(n+1);
    int pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) pos = i;
    }
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j < pos; j++) {
            if (a[j] == i) {
                if (i&1) {
                    ans[j] = r;
                    r--;
                } else {
                    ans[j] = l;
                    l++;
                }
            }
        }
        for (int j = n; j > pos; j--) {
            if (a[j] == i) {
                if (i&1) {
                    ans[j] = r;
                    r--;
                } else {
                    ans[j] = l;
                    l++;
                }
            }
        }
    }
    ans[pos] = l;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "\n" : " ");
    }
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