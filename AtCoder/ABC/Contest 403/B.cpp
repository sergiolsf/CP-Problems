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

signed main() {
    fastio();
    string t, u; cin >> t >> u;
    for (int i = 0; i < t.size(); i++) {
        int cont = 0;
        for (int j = 0; j < u.size() && i+j < t.size(); j++) {
            if (t[i+j] == u[j] || t[i+j] == '?') cont++;
            else break;
        }
        if (cont == u.size()) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}