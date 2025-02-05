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

int n;
vi x, v;

bool good (double t) {
    double menor = -1e10;
    double maior = 1e10;

    for (int i = 1; i <= n; i++) {
        menor = max(menor, (double) x[i] - t*((double) v[i]));
        maior = min(maior, (double) x[i] + t*((double) v[i]));
    }

    return maior >= menor;
}

signed main() {
    fastio();
    cin >> n;
    v.resize(n+1);
    x.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> v[i];
    }

    double l = 0; // tempo que ainda não é possível
    double r = 1; // tempo que é possível

    while (!good(r)) r *= 2;

    for (int i = 1; i <= 100; i++) {
        double m = (r+l)/2;
        if (good(m)) r = m;
        else l = m;
    }

    cout << setprecision(20) << r << endl;
  
    return 0;
}