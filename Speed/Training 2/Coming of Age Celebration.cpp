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
    vi c(n+1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    map<int,int> mp;
    int cont = 0;

    for (int i = 1; i <= n; i++) {
        int u = 0;
        if(mp.count(i)) u = mp[i];
        cont -= u;
        int p = c[i] + cont;

        if (p >= n-i) {
            cout << p - (n-i) << " ";
        } else {
            cout << 0 << " ";
            int j = (n+1) - ((n-i)-(p));
            if (mp.count(j)) mp[j]++;
            else mp[j] = 1;
        }

        cont++;
    }
    cout << endl;
  
    return 0;
}