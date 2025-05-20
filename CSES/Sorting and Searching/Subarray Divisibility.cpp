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

int mod(int b) {
    return (b%n + n)%n;
}

signed main() {
    fastio();
    cin >> n;
    vi a(n);
    vi r(n, 0);
    for (auto &i: a) cin >> i;

    int sum = 0;
    r[0]++;

    int ans = 0;
    for (auto e: a) {
        sum = mod(sum+e);
        ans += r[sum];
        r[sum]++;
    }

    cout << ans << endl;
  
    return 0;
}