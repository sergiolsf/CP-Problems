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

vi P(110, 0);
vi r(110, 0);

signed main() {
    fastio();
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) {
        cin >> i;
        P[i]++;
    }
    
    int k = 1;
    for (int i = 100; i >= 0; i--) {
        if (P[i]) {
            r[i] = k;
            k += P[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << r[a[i]] << endl;
    }

  
    return 0;
}