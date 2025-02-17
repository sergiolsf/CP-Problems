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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string h;
    h.pb(s[0]);
    char ant = s[0];
    for (int i = 1; i < (int) s.size(); i++) {
        if (s[i] != ant) {
            h.pb(s[i]);
            ant = s[i];
        }
    }

    int cont = 0;
    if (h[h.size()-1] == '1') cont++;
    for (int i = (int)h.size()-2; i >= 0; i--) {
        if (h[i] == '1') cont+=2;
    }

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