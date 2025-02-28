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
    vector<bool> alf(30, false);

    char ult = s[0];
    int c = s[0]-'A';
    alf[c] = true;
    for (int i = 1; i < n; i++) {
        int d = s[i]-'A';
        if (alf[d] && s[i] != ult) {
            cout << "NO\n";
            return;
        }
        ult = s[i];
        alf[d] = true;
    }
    cout << "YES\n";
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