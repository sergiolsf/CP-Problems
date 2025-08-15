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
    int n, k; cin >> n >> k;
    vector<pii> movies(n);

    for (auto &[fim, ini]: movies) cin >> ini >> fim;

    sort(all(movies));

    multiset<int> assistindo;
    int ans = 0;

    for (int i = 0; i < k; i++) {
        assistindo.insert(0);
    }

    for (int i = 0; i < n; i++) {
        auto [fim, ini] = movies[i];
        auto it = assistindo.upper_bound(ini);
        if (it == assistindo.begin()) continue;
        ++ans;
        --it;
        assistindo.erase(it);
        assistindo.insert(fim);
    }

    cout << ans << endl;
  
    return 0;
}