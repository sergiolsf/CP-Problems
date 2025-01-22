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

signed main() {
    fastio();
    int n, x;
    cin >> n >> x;
    vector<pii> v (n);

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        v[i-1] = {k, i};
    }

    sort(all(v));

    int i = 0, j = n-1;
    while (j > i) {
        if (v[i].first + v[j].first == x) {
            cout << v[i].second << " " << v[j].second;
            return 0;
        } else if (v[i].first + v[j].first < x) {
            i++;
        } else j--;
    }

    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}