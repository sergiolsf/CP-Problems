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

const int INF = 1e8;

signed main() {
    fastio();

    int n,x;
    cin >> n >> x;

    vi c;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        c.push_back(d);
    }

    vi count(x+1, INF);

    count[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (auto coin : c) {
            if (i-coin >= 0) {
                count[i] = min(count[i], count[i-coin]+1);
            }
        }
    }

    if (count[x] >= INF) cout << "-1\n";
    else cout << count[x] << endl;

    return 0;
}