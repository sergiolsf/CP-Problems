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
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;

    int ans = 0;
    for (int maior = 1; maior <= 30; maior++) {
        int sum = 0, best = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum < 0 || a[i] > maior) sum = 0;
            best = max(best, sum);
        }
        ans = max(ans, best-maior);
    }

    cout << ans << endl;
  
    return 0;
}