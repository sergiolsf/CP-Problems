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
    int n, m, d; cin >> n >> m >> d;
    int tAtual = 0, T, onibusAt = 1, ans = 0;

    vi a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= d;
        if (i == n-1) T = a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int i = 0, j = 0;
    while (i < n || j < m) {
        if (onibusAt == 0) {
            while (i < n && a[i] < tAtual) i++;
            if (i >= n || a[i]+d >= T) break;
            ans++;
            tAtual = a[i]+d+1;
            onibusAt = 1;
        } else {
            while (j < m && b[j] < tAtual) j++;
            if (j >= m || b[j]+d >= T) break;
            ans++;
            tAtual = b[j]+d+1;
            onibusAt = 0;
        }
    }

    if (onibusAt) cout << "B ";
    else cout << "A ";
    cout << ans << endl;
  
    return 0;
}