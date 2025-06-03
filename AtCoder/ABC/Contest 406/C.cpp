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

vi minimo, maximo;

signed main() {
    fastio();
    int n; cin >> n;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i < n; i++) {
        if (a[i-1] < a[i] && a[i+1] < a[i]) maximo.push_back(i);
        else if (a[i-1] > a[i] && a[i+1] > a[i]) minimo.push_back(i);
    }

    int i = 0, j = 0;
    int ans = 0;
    while (i < minimo.size() && j < maximo.size()) {
        if (minimo[i] < maximo[j]) i++;
        else {
            int m;
            if (i - 1 < 0) {
                m = 1;
            } else m = minimo[i-1];

            int cont = maximo[j]-m;

            if (j + 1 >= maximo.size()) {
                m = n;
            } else m = maximo[j+1];
            cont *= m-minimo[i];

            ans += cont;
            i++;
            j++;
        }
    }

    cout << ans << endl;
  
    return 0;
}