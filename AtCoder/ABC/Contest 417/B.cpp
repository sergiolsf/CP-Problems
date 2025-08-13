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

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;

    sort(all(b));
    int j = 0;
    bool first = true;
    for (int i = 0; i < n; i++) {
        while (j < m && a[i] > b[j]) j++;
        if (j < m && a[i] == b[j]) {
            j++; continue;
        } else {
            if (!first) cout << " ";
            cout << a[i];
            first = false;
        }
    }
    cout << endl;
  
    return 0;
}