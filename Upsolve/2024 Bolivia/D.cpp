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
    for (int i = 2; i < ss; i++) if (bs[i]) {
        for (int j = i*i; j < ss; j+=i) bs[j] = 0;
        p.push_back(i);
    }
}

int sumDiv(int n) {
    int ans = 1;
    for (int i = 0; (i < p.size()) && (p[i]*p[i] <= n); ++i) {
        int mult = p[i], tot = 1;
        while (n%p[i] == 0) {
            n /= p[i];
            tot += mult;
            mult *= p[i];
        }
        ans *= tot;
    }
    if (n != 1) ans *= (n+1);
    return ans;
}

signed main() {
    fastio();
    sieve(100000);
    int n; cin >> n;
    while (n--) {
        int a; cin >> a;
        cout << a;
        if (a == 1) {
            cout << " complicado\n";
            continue;
        }
        int sd = sumDiv(a) - a;
        if (sd == a) {
            cout << " perfecto";
        } else {
            int ssd = sumDiv(sd) - sd;
            if (ssd == a) cout << " romantico";
            if (sd > a) cout << " abundante";
            else if (ssd != a) cout << " complicado";
        }
        cout << endl;
    }
  
    return 0;
}