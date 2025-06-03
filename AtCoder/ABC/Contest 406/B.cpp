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

int contaDigitos(int a) {
    int cont = 0;
    while (a > 0) {
        a /= 10;
        cont++;
    }
    return cont;
}

signed main() {
    fastio();
    int n, k;
    cin >> n >> k;
    int ans = 1;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        int c = contaDigitos(a);
        int d = contaDigitos(ans);
        if (c+d-1 > 18) ans = 1;
        else {
            ans = a*ans;
            if (contaDigitos(ans) > k) ans = 1;
        }
    }

    cout << ans << endl;
  
    return 0;
}