#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct point {
    int x, y;
};

int area (const vector<point> &P) {
    int ans = 0;
    for (int i = 0; i < (int)P.size()-1; ++i) {
        ans += (P[i].x*P[i+1].y - P[i+1].x*P[i].y);
    }
    return abs(ans);
}

signed main() {
    fastio();
    int n; cin >> n;
    vector<point> P(n+1);
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    P[n] = P[0];

    cout << area(P) << endl;
    
    return 0;
}