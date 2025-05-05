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

const int MAX_N = 10'000'000;

vi sieve;
vi sum(MAX_N);
bitset<MAX_N> marc;

void solve() {
    int n; cin >> n;
    vi a(n);
    int s = 0;
    for (auto &i: a) {
        cin >> i;
        s += i;
    }
    sort(all(a));

    int ans = 0;
    while (s < sum[n]) {
        s -= a[ans];
        n--;
        ans++;
    }

    cout << ans << endl;
}

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!marc[i]) {
            sieve.push_back(i);
            for (int j = i; j < MAX_N; j+=i) {
                marc[j] = true;
            }
        }
    }

    for (int i = 0; i < sieve.size(); i++) {
        sum[i+1] = sum[i] + sieve[i];
    }
}

signed main() {
    fastio();
    init();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}