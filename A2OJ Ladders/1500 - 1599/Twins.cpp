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
    vi coins(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        sum += coins[i];
    }
    sort(coins.rbegin(), coins.rend());
    int ans = 0, cont = 0, i = 0;
    while (sum >= cont && i < n) {
        cont += coins[i];
        sum -= coins[i];
        i++;
        ans++;
    }

    cout << ans << endl;

  
    return 0;
}