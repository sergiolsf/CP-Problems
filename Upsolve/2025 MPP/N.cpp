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

const int MAX_N = 1'000'010;

bool ligado[MAX_N];
int cnt[MAX_N];
int val[MAX_N];
multiset<int> ms;

vi primes(int d) {
    vi ans;
    while (d > 1) {
        int p = val[d];
        ans.push_back(p);
        while (d%p == 0) {
            d /= p;
        }
    }
    return ans;
}

void sieve() {
    for (int i = 2; i < MAX_N; i++) {
        if (val[i]) continue;
        for (int j = i; j < MAX_N; j += i) {
            val[j] = i;
        }
    }
}

signed main() {
    fastio();
    sieve();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        ligado[d] = !ligado[d];
        vi p = primes(d);

        for (auto e: p) {
            auto it = ms.find(cnt[e]);
            if (it != ms.end()) ms.erase(it);
            if (ligado[d]) {
                cnt[e]++;
            } else {
                cnt[e]--;
            }
            ms.insert(cnt[e]);
        }

        cout << *ms.rbegin() << endl;
    }
  
    return 0;
}