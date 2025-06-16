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

const int MAX_N = 3'005;
const int INF = 1'000'000'000'000'000'000;

int n, m;
priority_queue<tuple<int,int,int>> pq; // dist, (ponto a, ponto b)
vi p(MAX_N);
vi r(MAX_N, 0);
vector<pii> ponto(MAX_N);

int dist (int i, int j) {
    return abs(ponto[i].first-ponto[j].first) + abs(ponto[i].second-ponto[j].second);
}

int get(int a) {
    return (p[a] == a ? a : get(p[a]));
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
    for (int i = 0; i < MAX_N; i++) {
        p[i] = i;
    }
}

signed main() {
    init();
    fastio();
    int q; cin >> n >> q;
    m = n;

    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        ponto[i] = {x,y};
    }

    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int d = dist(i, j);
            pq.push({-d, i, j});
        }
    }

    while (q--) {
        int op; cin >> op;

        if (op == 1) {
            int a, b; cin >> a >> b;
            ponto[n+1] = {a,b};
            for (int i = 1; i <= n; i++) {
                int d = dist(i, n+1);
                pq.push({-d, i, n+1});
            }
            n++;
            m++;
        } else if (op == 2) {
            if (m == 1) {
                cout << -1 << endl;
                continue;
            }

            int menorDist = INF;
            while (!pq.empty()) {
                auto [d, a, b] = pq.top(); d = -d;
                if (d > menorDist) break;
                a = get(a); b = get(b);
                pq.pop();
                if (a == b) {
                    continue;
                }
                menorDist = d;
                m--;
                uniao(a, b);
            }
            cout << menorDist << endl;
        } else {
            int u, v; cin >> u >> v;
            u = get(u); v = get(v);
            cout << (u == v ? "Yes\n" : "No\n");
        }

    }
  
    return 0;
}