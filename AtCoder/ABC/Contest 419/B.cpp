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
    priority_queue<int> pq;
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            pq.push(-x);
        } else {
            int u = pq.top(); pq.pop();
            cout << -u << endl;
        }
    }
  
    return 0;
}