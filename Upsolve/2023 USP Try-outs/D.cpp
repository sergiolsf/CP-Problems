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
    int n, k;
    cin >> n >> k;
    vector<queue<pii>> fila (k+1);
    int pos = 1;
    int maior = 0;
    vi ans;
    for (int i = 1; i <= 2*n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int p, f;
            cin >> p >> f;
            fila[f].push({p, pos});
            pos++;
        } else {
            int f;
            cin >> f;
            pii u = fila[f].front();
            fila[f].pop();
            if (u.second < maior) ans.pb(u.first);
            maior = max(u.second, maior);
         }
    }

    cout << ans.size() << endl;
    sort(all(ans));
    for (auto e: ans) {
        cout << e << " ";
    }
    if (ans.size()) cout << endl;
  
    return 0;
}