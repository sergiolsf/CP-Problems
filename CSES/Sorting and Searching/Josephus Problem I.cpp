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
    list<int> l;
    for (int i = 1; i <= n; i++) l.push_back(i);

    bool f = false;
    while (!l.empty()) {
        list<int> aux;
        for (auto it = l.begin(); it != l.end();) {
            if (f) {
                cout << *it << " ";
                it = l.erase(it);
            } else {
                ++it;
            }
            f = !f;
        }
    }
    cout << endl;
  
    return 0;
}