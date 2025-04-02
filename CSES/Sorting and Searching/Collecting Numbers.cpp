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
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x] = i;
    }

    int ans = 1;
    int ant = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] < ant) ans++;
        ant = a[i];
    }

    cout << ans << endl;
  
    return 0;
}