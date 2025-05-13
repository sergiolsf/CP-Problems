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

const int MAX_N = 100'005;
const int MOD = 998'244'353;
vi lp(MAX_N, 0);

vi pri(int a) {
    vi ans;
    while (a > 1) {
        int p = lp[a];
        ans.push_back(p);
        while (a%p == 0) a /= p;
    }
    return ans;
}

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (lp[i] != 0) continue;
        for (int j = i; j < MAX_N; j+=i) {
            if (lp[j] != 0) continue;
            lp[j] = i;
        }
    }
}

signed main() {
    fastio(); 
    init();
    
    int n; cin >> n;
    set<int> primos;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        int g = __gcd(a,b);
        int d = b/g;
        if (d == 1) continue;
        vi v = pri(d);
        for (auto e: v) primos.insert(e);
    }

    int ans = 1;

    if (primos.empty()) {
        cout << 2 << endl;
        return 0;
    }

    for (auto e: primos) ans = (ans*e)%MOD;

    cout << ans << endl;

    return 0;
}