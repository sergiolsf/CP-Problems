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

const int MAX_N = 200'005;

bool todos[MAX_N];

signed main() {
    fastio();
    int n, m, q; cin >> n >> m >> q;
    map<int,set<int>> mp;
    while (q--) {
        int t; cin >> t;
        int x,y; 
        if (t == 1) {
            cin >> x >> y;
            mp[x].insert(y);
        } else if (t == 2) {
            cin >> x;
            todos[x] = true;
        } else {
            cin >> x >> y;
            if (todos[x] || mp[x].count(y)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }

    }

  
    return 0;
}