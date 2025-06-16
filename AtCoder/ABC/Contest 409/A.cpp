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
    int n; cin >> n;
    string a, t; cin >> a >> t;
    for (int i = 0; i  < n; i++) {
        if (a[i] == 'o' && t[i] == 'o') {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}
