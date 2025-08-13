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

vi plots;
vi sum;
int n;

signed main() {
    fastio();
    int n; cin >> n;
    sum.resize(n);
    vector<pii> ord;

    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        plots.push_back(m);
        ord.push_back({m, i});
        if (i == 0) sum[0] = m;
        else sum[i] = sum[i-1]+m;
    }

    
    sort(all(ord));

    int l = 0, r = n-1;
    for (int i = 0; i < n; i++) {
        auto [a, b] = ord[i];
        if (!(l <= b && b <= r)) continue;

        int ss = 0, sb = 0;
        if (l != 0) ss = sum[l-1];
        if (b != 0) sb = sum[b-1];
        int se = sb - ss, te = b-l;
        int sd = sum[r] - sum[b], td = r-b;

        if (se - a*te < sd - a*td) {
            for (int j = l; j <= b-1; j++) plots[j] = a;
            l = b+1;
        } else {
            for (int j = b+1; j <= r; j++) plots[j] = a;
            r = b-1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << plots[i] << (i == n-1 ? "\n" : " ");
    }
  
    return 0;
}