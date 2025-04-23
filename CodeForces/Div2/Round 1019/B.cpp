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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cont = 0;
    int inv = 0;
    char ant = '0';
    for (int i = 0; i < n; i++) {
        if (s[i] != ant) {
            cont++;
            inv++;
        }
        cont++;
        ant = s[i];
    }

    if (inv == 2) cont--;
    else if (inv > 2) cont -= 2;

    cout << cont << endl;
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