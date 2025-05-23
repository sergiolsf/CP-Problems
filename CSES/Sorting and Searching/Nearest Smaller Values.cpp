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
    deque<pii> dq;

    dq.push_back({0,0});
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while(dq.back().first >= x) dq.pop_back();
        cout << dq.back().second << " ";
        dq.push_back({x, i+1});
    }
  
    return 0;
}