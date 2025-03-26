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

const int MAIOR = 1'000'000'000;
const int MAXB = 1'000'010;
const int MAXN = 10'010;

int n;
vi a(MAXN), b(MAXN);
vi restos(MAXB, 0);

bool check(int k) {
    for (int i = 0; i < n; i++) restos[a[i]%k]++;
    for (int i = 0; i < n; i++) {
        restos[b[i]]--;
        if (restos[b[i]] < 0) {
            restos[b[i]] = 0;
            for (int i = 0; i < n; i++) restos[a[i]%k] = 0;
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;

    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        m -= b[i];
    }
   
    if (m < 0) {
        cout << -1 << endl;
        return;
    } else if (m == 0) {
        if (check(MAIOR)) cout << MAIOR << endl;
        else cout << -1 << endl;
        return;
    }
    
    for (int i = 1; i*i <= m; i++) {
        if (m%i == 0) {
            if (check(i)) {
                cout << i << endl;
                return;
            }
            if (check(m/i)) {
                cout << (m/i) << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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