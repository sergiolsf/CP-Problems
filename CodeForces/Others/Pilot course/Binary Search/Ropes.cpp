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

const double EPS = 1e-6;

int n, k;
vi a;

bool f(double x) {
    int d = 0;
    for (int i = 1; i <= n; i++) {
        d += floor(a[i]/x);
    }
    return d >= k;
}

signed main() {
    fastio();
    cin >> n >> k;
    a.resize(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    double l = 0.0, r = 10000005.0;

    for (int i = 1; i <= 100; i++) {
        double m = (l+r)/2.0;
        if (f(m)) l = m;
        else r = m;
    }

    cout << fixed << setprecision(12);
    cout << l << endl;
  
    return 0;
}