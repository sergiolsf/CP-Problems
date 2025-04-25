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

int den[12];

void solve() {
    int a, b; cin >> a >> b;
    string s1, s2; cin >> s1 >> s2;

    int n1 = 0, n2 = 0;
    for (int i = 0; i < a; i++) {
        n1 += ((int) (s1[i]-'0'))*den[a-i-1];
    }
    n2 = n1*den[b];
    for (int i = 0; i < b; i++) {
        n2 += ((int) (s2[i]-'0'))*den[b-i-1];
    }

    int n = n2-n1, d = den[a+b]-den[a];
    int div = __gcd(n, d);
    cout << n/div << " " << d/div << endl;
}

void init() {
    den[0] = 1;
    for (int i = 1; i <= 10; i++) {
        den[i] = den[i-1]*10;
    }
}

signed main() {
    fastio();
    init();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}