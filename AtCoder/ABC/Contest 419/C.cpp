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

int r[MAX_N];
int c[MAX_N];

signed main() {
    fastio();
    int n; cin >> n;
    int rmin = 1'000'000'001, rmax = 0;
    int cmin = 1'000'000'001, cmax = 0;
    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> c[i];
        rmin = min(rmin, r[i]);
        cmin = min(cmin, c[i]);
        rmax = max(rmax, r[i]);
        cmax = max(cmax, c[i]);
    }

    int rf = (rmin+rmax)/2;
    int cf = (cmin+cmax)/2;

    int t = 0;
    for (int i = 1; i <= n; i++) {
        int d;
        d = max(abs(c[i]-cf), abs(r[i]-rf));
        t = max(t, d);
    }

    cout << t << endl;  
    return 0;
}