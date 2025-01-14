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
    int n;
    cin >> n;
    vi x(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(all(x));

    int ant = x[0];
    int ans = 1;

    for (int i = 0; i < n; i++) {
        if (x[i] != ant) {
            ans++;
            ant = x[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}