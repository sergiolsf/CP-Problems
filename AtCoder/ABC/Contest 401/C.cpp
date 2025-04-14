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

const int MOD = 1'000'000'000;

signed main() {
    fastio();
    int n, k; cin >> n >> k;
    if (n < k) {
        cout << 1 << endl;
        return 0;
    }

    int sum = k;
    int i = 0, j = k;
    vi v(n+1, 0);
    for (int i = 0; i < k; i++) {
        v[i] = 1;
    }

    v[k] = k;
    while (j < n) {
        sum = ((sum-v[i]+v[j])%MOD+MOD)%MOD;
        j++;
        v[j] = sum;
        i++;
    }
    cout << sum << endl;
  
    return 0;
}