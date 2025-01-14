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
    int n;
    cin >> n;

    vi a(n+1);
    set<int> ans;
    ans.insert(0);

    int indx = -1;
    int x;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1)  { 
            indx = i;
            x = a[i];
        }
    }

    if (indx != -1) {
        int maxd = 0, mind = 0;
        int maxe = 0, mine = 0;

        int sum = 0;
        for (int i = indx-1; i >= 0; i--) {
            sum += a[i];
            maxe = max(maxe, sum);
            mine = min(mine, sum);
        }

        sum = 0;
        for (int i = indx+1; i <= n; i++) {
            sum += a[i];
            maxd = max(maxd, sum);
            mind = min(mind, sum);
        }

        for (int i = x+mind+mine; i <= x+maxd+maxe; i++) {
            ans.insert(i);
        }
    }

    int maxe = 0, mine = 0, maxd = 0, mind = 0;

    int sumMax = 0, sumMin = 0;
    for (int i = 0; i < indx; i++) {
        sumMax += a[i];
        maxe = max(maxe, sumMax);
        if (sumMax < 0) sumMax = 0;

        sumMin += a[i];
        mine = min(mine, sumMin);
        if (sumMin > 0) sumMin = 0;
    }

    sumMax = 0;
    sumMin = 0;
    for (int i = indx+1; i <= n; i++) {
        sumMax += a[i];
        maxd = max(maxd, sumMax);
        if (sumMax < 0) sumMax = 0;

        sumMin += a[i];
        mind = min(mind, sumMin);
        if (sumMin > 0) sumMin = 0;
    }

    for (int i = mind; i <= maxd; i++) {
        ans.insert(i);
    }

    for (int i = mine; i <= maxe; i++) {
        ans.insert(i);
    }

    cout << ans.size() << endl;

    for (auto e : ans) cout << e << " ";
    cout << endl;
    
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