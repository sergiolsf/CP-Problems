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
    vector<pair<int, char>> vp;
    int sum = 0;
    bool f = false;
    for (int i = 0; i < n; i++) {
        char c; int l;
        cin >> c >> l;
        if (!f) sum += l;
        if (!f && sum > 100) {
            cout << "Too Long\n";
            f = true;
        }
        vp.push_back({l, c});
    }

    if (f) return 0;

    for (auto [l, c]: vp) {
        while (l--) {
            cout << c;
        }
    }
    cout << endl;  
    return 0;
}