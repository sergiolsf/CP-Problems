#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define f first
#define s second
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
    int n, x; cin >> n >> x;
    vector<pii> a;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        a.push_back({p, i});
    }

    sort(all(a));
  
    for (int ini = 0; ini < n-2; ini++) {
        int l = ini+1, r = n-1;
        int t = x - a[ini].f;
        if (t <= 0) break;

        while (l < r) {
            int sum = a[l].f + a[r].f;
            if (sum == t) {
                cout << a[l].s << " " << a[r].s << " " << a[ini].s << endl;
                return 0;
            }
            if (sum < t) l++;
            else r--;
        }

    }

    cout << "IMPOSSIBLE\n";
    return 0;
}