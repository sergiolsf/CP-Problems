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
    int r, x; cin >> r >> x;
    if (x == 1) {
        if (1600 <= r && r <= 2999) {
            cout << "Yes\n";
            return 0;
        }
    } else {
        if (1200 <= r && r <= 2399) {
            cout << "Yes\n";
            return 0;
        }
    }
  
    cout << "No\n";
    return 0;
}