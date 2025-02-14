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
    int n;
    cin >> n;
    int cont = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cont -= a;
        cont += b;
        ans = max(ans, cont);
    }

    cout << ans << endl;
  
    return 0;
}