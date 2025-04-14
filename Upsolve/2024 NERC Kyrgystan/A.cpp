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
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;

    int ans;
    if (a == c) ans = d-b;
    else {
        ans = (c-a-1)*n + d + (n-b)+(c-a);
    }

    cout << ans << endl;
  
    return 0;
}