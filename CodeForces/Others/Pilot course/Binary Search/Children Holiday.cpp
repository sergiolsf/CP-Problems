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

int m, n;
vi t, z, y;

bool good (int T) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int a = T/(z[i]*t[i] + y[i]);
        int x = min(T-(z[i]*t[i]+y[i])*a, z[i]*t[i]);
        s += a*z[i] + x/t[i];
    }
    return s >= m;
}


signed main() {
    fastio();
    
    cin >> m >> n;
    t.resize(n);
    z.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> z[i] >> y[i];
    }

    if (m == 0) {
        cout << 0 << endl;
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
        return 0;
    }

    int l = 0; // nao terminou de preencher
    int r = 1; // terminou de preencher

    while (!good(r)) r *= 2;

    while (r-l != 1) {
        int M =(l+r)/2;
        if (good(M)) r = M;
        else l = M;
    }

    cout << r << endl;

    vi ans(n);
    int s = 0;

    for (int i = 0; i < n; i++) {
        int a = r/(z[i]*t[i] + y[i]);
        int x = min(r-(z[i]*t[i]+y[i])*a, z[i]*t[i]);
        ans[i] = a*z[i] + x/t[i];
        s += ans[i];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] - min(ans[i], s-m) << " ";
        s -= min(ans[i], s-m);
    }

    cout << endl;
  
    return 0;
}