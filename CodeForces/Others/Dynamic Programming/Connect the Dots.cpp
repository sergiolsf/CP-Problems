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

const int MAX_N = 200'005;

int n, m; 
vector< vector< tuple<int,int,int> > > point(MAX_N); // d, k, grupo
vi p(MAX_N);
vi r(MAX_N);

int get(int a) {
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void uniao(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;

    if (r[a] == r[b]) r[a]++;
    if (r[a] > r[b]) {
        p[b] = a;
    } else {
        p[a] = b;
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        while(!point[i].empty()) point[i].pop_back();
        p[i] = i;
        r[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    init();

    for (int i = 0; i < m; i++) {
        int a, d, k; cin >> a >> d >> k;

        if (point[a].empty()) {
            point[a].push_back({d, k, a});
        } else {
            bool f = false;
            for (auto &[da, ka, ga]: point[a]) {
                if (da == d) {
                    ka = max(ka, k);
                    f = true;
                    break;
                }
            }
            if (!f) {
                point[a].push_back({d, k, a});
            }
        }
    }


    for (int i = 1; i <= n ; i++) {
        int grupo = get(i);
        for (auto &[da, ka, ga]: point[i]) {
            uniao(grupo, ga);
            if (ka == 0) continue;

            bool f = false;
            for (auto &[db, kb, gb]: point[i+da]) {
                if (da == db) {
                    kb = max(ka-1, kb);
                    f = true;
                    uniao(grupo, gb);
                    break;
                }
            }
            if (!f) {
                uniao(grupo, i+da);
                point[i+da].push_back({da, ka-1, grupo});
            }
        }
    }

    set<int> ans;
    for (int i = 1; i <= n; i++) {
        int grupo = get(i);
        ans.insert(grupo);
    }

    cout << ans.size() << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}