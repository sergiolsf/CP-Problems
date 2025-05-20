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
    int n, x; cin >> n >> x;
    vi a(n);
    for (auto &i: a) cin >> i;

    int sum = 0; 
    queue<int> q;

    int i = 0, j = 0, ans = 0;
    while (j <= n && i < n) {
        if (sum <= x) {
            if (j >= n) break;
            sum += a[j];
            q.push(a[j]);
            j++;
        } else if (sum > x) {
            sum -= q.front();
            q.pop();
            i++;
        }

        if (sum == x){
            ans++;
        }
    }

    cout << ans << endl;
  
    return 0;
}