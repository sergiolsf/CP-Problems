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
    int a = 0, b = 0, x = 0;
    int quantP = 0;
    for (int i = 0; i < n; i++) {
        if (i%2 == 1 && s[i] == 'B') b++;
        if (s[i] == 'B') {
            a++;
            x += quantP;
        } else {
            quantP++;
        }
    }

    int d = abs(a/2 - b);

    cout << (x+d)/2 << endl;


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

/*
1
6
BPBPBP
*/