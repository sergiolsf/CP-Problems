#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define s second
#define f first
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
    int n, x; cin >> n >> x;
    vector<pii> a(n);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        a[i-1] = {t, i};
    }

    sort(all(a));

    for (int i = 0; i <= n-4; i++) {
        for (int j = i+1; j <= n-3; j++) {
            int S = x-a[i].f-a[j].f;
            int ini = j+1, fim = n-1;
            int sum = a[ini].f+a[fim].f;
            while (ini < fim) {
                sum = a[ini].f+a[fim].f;
                if (sum < S) {
                    ini++;
                } else if (sum > S) {
                    fim--;
                } else {
                    cout << a[i].s << " " << a[j].s << " " << a[ini].s << " " << a[fim].s << endl;
                    return 0;
                }
            }

        }
    }

    cout << "IMPOSSIBLE\n";
  
    return 0;
}