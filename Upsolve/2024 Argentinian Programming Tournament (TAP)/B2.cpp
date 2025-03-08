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

vi factors(int n) {
    vi fac;
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            fac.push_back(i);
            while (n%i == 0) n/=i;
        }
    }
    if (n > 1) fac.push_back(n);
    return fac;
}

signed main() {
    fastio();

    int n; cin >> n;

    vi fac = factors(n);

    vi ans;
    for (int i = 0; i < fac.size(); i++) {
        ans.push_back(n/fac[i]);
    }

    cout << ans.size() << endl;
    for (auto e: ans) cout << 1 << " " << e << endl;
  
    return 0;
}