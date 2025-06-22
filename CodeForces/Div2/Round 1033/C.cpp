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

int n;

int f(int r) {
    return (r-1)*r/2 + r*(n-r+1);
}

void solve() {
    int m; cin >> n >> m;
    if (m < n || m > n*(n+1)/2) {
        cout << "-1\n";
        return;
    }
    int raiz = 1;

    while (f(raiz+1) < m) raiz++;

    int c = m-f(raiz); c = raiz+c;
    if (c < raiz) c = raiz;
    cout << c << endl;
    if (c != raiz) cout << c << " " << raiz << endl;
    for (int i = 1; i <= n; i++) {
        if (i == c || i == raiz) continue;
        cout << raiz << " " << i << endl;
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