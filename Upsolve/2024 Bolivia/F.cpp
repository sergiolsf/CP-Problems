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

const int MAX_N = 100'010;

vi h(MAX_N);
vi x(MAX_N);

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 2; i <= n; i++) cin >> x[i];

    int maior = 0, qnt = 0;
    for (int i = 1; i < n; i++) {
        maior = max(maior, h[i]);
        if (maior <= x[i+1]) break;
        maior -= x[i+1];
        qnt++;
    }
    if (qnt == (n-1)) {
        cout << "habibi\n";
        return;
    }

    maior = 0; qnt = 0;
    for (int i = n; i > 1; i--) {
        maior = max(maior, h[i]);
        if (maior <= x[i]) break;
        maior -= x[i];
        qnt++;
    }
    if (qnt == (n-1)) {
        cout << "habibi\n";
        return;
    }
    
    cout << "which\n";
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}