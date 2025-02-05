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

int k, n;
vi a;

bool good (int x) {
    int cont = 0;
    int f = x;
    for (int i = 0; i < n; i++) {
        if (a[i] >= x) cont++;
        else {
            if (a[i] >= f) {
                cont++;
                f = x - (a[i]-f);
            } else {
                f = f-a[i];
            }
        }
    }
    return cont >= k;
}

signed main() {
    fastio();
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }

    sort(a.rbegin(), a.rend());

    int l = 0; // possível formar l grupos
    int r = 1; // impossível formar r grupos

    while (good(r)) r *= 2;

    while (r-l != 1) {
        int m = (r+l)/2;
        if (good(m)) l = m;
        else r = m;
    }

    cout << l << endl;
  
    return 0;
}