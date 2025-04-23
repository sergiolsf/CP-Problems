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
    deque<int> dq;
    int n; cin >> n;
    while (n--) {
        int q; cin >> q;
        if (q == 1) {
            int v; cin >> v;
            dq.push_back(v);
        } else {
            cout << dq.front() << endl;
            dq.pop_front();
        }
    }
  
    return 0;
}