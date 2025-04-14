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
    int n, D; cin >> n >> D;
    vi c(n+1, 0);
    int M = 0;
    for (int i = 0; i < D; i++) {
        int f, s; cin >> f >> s;
        c[f]++; c[s]++;
        M = max({M, c[f], c[s]});
    }

    int maxH = 0, S = 0;
    for (int i = 1; i <= n; i++) {
        S += M-c[i];
        maxH = max(maxH, M-c[i]);
    }

    while (S%2 == 1 || 2*maxH > S) {
        M++;
        S += n;
        maxH++;
    }

    cout << M << endl;
  
    return 0;
}