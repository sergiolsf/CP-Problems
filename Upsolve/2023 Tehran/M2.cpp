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

const int INF = 1'000'000'000'000'000'000;

signed main() {
    fastio();
    int n; cin >> n;
    unordered_map<string, int> id;
    vector<string> v(n);
    int p = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (!id.count(v[i])) id[v[i]] = p++;
    }

    unordered_map<int, int> preCalc;
    for (int i = 0; i < n; i++) {
        int msk = 0;
        for (int j = i; j < n; j++) {
            msk |= (1LL << id[v[j]]);
            int l = j-i+1;
            if (!preCalc.count(msk) || preCalc[msk] > l) {
                preCalc[msk] = l;
            }
        }
    }

    vector<pii> vec;
    for (auto [f, s]: preCalc) {
        vec.push_back({s, f});
    }
    sort (all(vec));

    int sz = vec.size();
    int ans = INF, mask = (1ll << id.size())-1;
    for (int i = 0; i < sz; i++) {
        auto [l1, msk1] = vec[i];
        int r = mask^msk1;

        if (l1 >= ans) break;

        for (int j = i+1; j < sz; j++) {
            auto [l2, msk2] = vec[j];

            if (l1 + l2 >= ans) break;

            if ((msk2 & r) == r) {
                ans = l1 + l2;
                break;
            }
        }
    }

    cout << ans << endl;

  
    return 0;
}