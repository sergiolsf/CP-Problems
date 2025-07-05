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

const int MAX_N = 200'005;

int n;
int vd[MAX_N];
int ve[MAX_N];

bool poss(string a, string b) {
    int d = 0;
    for (int i = 0; i < 2*n; i++) {
        if (a[i] == b[d]) d++;
        vd[i] = d;
    }

    int e = 0;
    for (int i = 2*n-1; i >= 0; i--) {
        if (a[i] == b[2*n-1-e]) e++;
        ve[i] = e;
    }

    for (int i = 0; i < 2*n; i++) {
        int vald = (i == 0 ? 0 : vd[i-1]);
        int vale = ve[i];
        if (vald+vale >= n) {
            for (int j = 0; j < i; j++) cout << a[j];
            for (int j = vald; j <= 2*n-1-vale; j++) cout << b[j];
            for (int j = i; j < 2*n; j++) cout << a[j];
            cout << endl;
            return true;
        }
    }

    int vald = vd[2*n-1];
    int vale = 0;
    if (vald+vale >= n) {
        for (int j = 0; j < 2*n; j++) cout << a[j];
        for (int j = vald; j < 2*n; j++) cout << b[j];
        cout << endl;
        return true;
    }

    return false;
}

void solve() {
    cin >> n;
    string a, b, c; cin >> a >> b >> c;

    if (poss(a, b)) return;
    if (poss(a, c)) return;
    if (poss(b, c)) return;
    if (poss(b, a)) return;
    if (poss(c, a)) return;
    if (poss(c, b)) return;
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