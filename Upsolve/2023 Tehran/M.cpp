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
    vector<string> vc(n);
    for (auto &s: vc) cin >> s;

    unordered_map<string, int> id;
    int k = 0;
    for (auto &s : vc) {
        if (!id.count(s)) {
            id[s] = k;
            k++;
        }
    }
    
    int sz = id.size();
    int msk = (1LL << sz) - 1;

    unordered_map<int, int> preComp;
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = i; j < n; j++) {
            int p = id[vc[j]];
            mask |= (1LL << p);
            int l = j - i + 1;
            if (!preComp.count(mask) || preComp[mask] > l) {
                preComp[mask] = l;
            }
        }
    }

    vector<pii> vp;
    for (auto e : preComp) {
        vp.push_back({e.second, e.first});
    }
    sort(all(vp));

    int ans = INF;
    for (auto e : preComp) {
        int mask = e.first;
        int l = e.second;
        int r = msk^mask;

        for (auto h : vp) {
            int l2 = h.first;
            int mask2 = h.second;

            if (l + l2 >= ans) break;

            if ((mask2&r) == r) {
                ans = l + l2;
                break;
            }
        }
    }

    cout << ans << endl;
  
    return 0;
}