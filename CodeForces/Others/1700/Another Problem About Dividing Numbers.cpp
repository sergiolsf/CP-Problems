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

int ss;
bitset<100010> bs;
vi p;

void sieve(int up) {
    ss = up+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < ss; ++i) if (bs[i]) {
        for (int j = i*i; j < ss; j+= i) bs[j] = 0;
        p.pb(i);
    }
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;


    if (k == 1) {
        	if ((a%b == 0 || b%a == 0) && (a != b)) cout << "YES\n";
            else cout << "NO\n";
            return;
    }


    int cA = 0, cB = 0;

    int A = a;
    for (int i = 0; p[i]*p[i] <= a && i < p.size(); i++) {
        while (a%p[i] == 0) {
            cA++;
            a /= p[i];
        }
    }
    if (a > 1) cA++;
    a = A;

    int B = b;
    for (int i = 0; p[i]*p[i] <= b && i < p.size(); i++) {
        while (b%p[i] == 0) {
            cB++;
            b /= p[i];
        }
    }
    if (b > 1) cB++;
    b = B;

    if (k <= cA + cB) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    fastio();
    sieve(100000);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}