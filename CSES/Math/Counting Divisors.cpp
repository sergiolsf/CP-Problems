#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vi p;
int ss;
bitset<10000010> bs;

void sieve(int up) {
    ss = up+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < ss; ++i) if (bs[i]) {
        for (int j = i*i; j < ss; j += i) bs[j] = 0;
        p.push_back(i);
    }
}

void solve() {
    int N;
    cin >> N;

    int ans = 1;
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        int power = 0;
        while (N%p[i] == 0) {
            N /= p[i];
            ++power;
        }
        ans *= power+1;
    }
    if (N != 1) ans*=2;
    cout << ans << endl;
}

signed main() {
    fastio();
    sieve(10000000);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}