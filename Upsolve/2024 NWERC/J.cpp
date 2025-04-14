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

int dist(pii p1, pii p2) {
    int x2 = (p1.first-p2.first)*(p1.first-p2.first);
    int y2 = (p1.second-p2.second)*(p1.second-p2.second);
    int d = sqrtl((long double) x2 + (long double) y2);
    return d;
}

signed main() {
    fastio();
    int n; cin >> n;
    vector<tuple<int,int,int>> crane(n);
    for (auto &[x, y, h]: crane) cin >> x >> y >> h;

    vi ans(n);

    for (int i = 0; i < n; i++) {
        auto [xi, yi, hi] = crane[i];
        int &menor_dist = ans[i];
        menor_dist = hi;
        for (int j = 0; j < n; j++) {
            auto [xj, yj, hj] = crane[j];
            if (hj <= hi) continue;
            menor_dist = min(menor_dist, dist({xi, yi}, {xj, yj}));
        }
    }

    for (auto e: ans) cout << e << endl;
  
    return 0;
}