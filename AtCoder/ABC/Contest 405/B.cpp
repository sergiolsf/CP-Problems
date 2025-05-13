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
    vi v(m+1, 0);

    vi a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
        v[x]++;
    }

    for (int i = 1; i <= m; i++) {
        if (!v[i]) {
            cout << 0 << endl;
            return 0;
        }
    }

    int cont = 0;
    for (int i = n-1; i >= 0; i--) {
        v[a[i]]--;
        cont++;
        if (!v[a[i]]) {
            cout << cont << endl;
            return 0;
        }
    }
  
    return 0;
}