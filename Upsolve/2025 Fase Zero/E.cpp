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

vi divisores(int n) {
    vi ans;
    for (int i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            ans.push_back(i);
            if (n/i != i) ans.push_back(n/i);
        }
    }
    sort(all(ans));
    return ans;
}

signed main() {
    fastio();
    int y, k; cin >> y >> k;
    vi d = divisores(y);

    int p = 1;
    int quant = 0;
    for (int i = 1; i < d.size(); i++) {
        if (d[i]%p == 0) {
            int q = d[i]/p;
            if (q+quant-1 >= k) {
                cout << (k-quant+1)*p << endl;
                return 0;
            }
            p = d[i];
            quant += q-1;
        }
    }
  
    cout << (k-quant+1)*p << endl;
    return 0;
}