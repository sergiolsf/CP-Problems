#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const double PI = acos(-1);

signed main() {
    fastio();
    int r; cin >> r;
    ld teta = asin(3.0/5.0);

    ld alfa = PI - 2*teta;

    ld At = (ld) (r*r)*sin(alfa) / 2.0;
    ld A = (ld)(r*r)*alfa/2.0;

    ld ans = (ld) (r*r)*PI/2.0 - (A-At);
    cout << setprecision(20) << ans << endl;
  
    return 0;
}