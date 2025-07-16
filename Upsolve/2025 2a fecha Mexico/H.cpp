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

const int MAX_N = 10'005;

struct node {
    int x, y, z;
};

int n, h, k, m;
vector<node> v;
bool visited[MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        visited[i] = false;
    }
}

signed main() {
    fastio();
    init();
    cin >> n >> h >> k;
    //swap(h,k);
    for (int i = 0; i < n; i++) {
        node a; cin >> a.x >> a.y >> a.z;
        v.push_back(a);
    }

    node a; a.x = 0; a.y = 0; a.z = 0;
    v.push_back(a);

    int x0, y0; cin >> x0 >> y0;
    for (int i = 0; i < n; i++) {
        auto [x, y, z] = v[i];
        if (x == x0 && y == y0) {
            m = i;
            break;
        }
    }

    vi pulos;
    pulos.push_back(n);
    visited[n] = true;

    int dist = 0;
    for (int i = 0; i < n; i++) {
        auto [x, y, z] = v[i];
        if (y == 0) {
            if (m == i) {
                cout << 0 << endl;
                return 0;
            }
            pulos.push_back(i);
            visited[i] = true;
        }
    }

    

    while(!pulos.empty()) {
        dist++;
        vi pp;

        for (auto e: pulos) {
            auto [x, y, z] = v[e];
            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;

                auto [xx, yy, zz] = v[i];
                if (abs(yy) <= h && zz == 1) {
                    pp.push_back(i);
                    if(m == i) {
                        cout << dist << endl;
                        return 0;
                    }
                }

                int d = (xx-x)*(xx-x) + (yy-y)*(yy-y);
                if ((d <= h*h && zz == 1) || (d <= k*k && z == 1)) {
                    pp.push_back(i);
                    visited[i] = true;
                    if(m == i) {
                        cout << dist << endl;
                        return 0;
                    }
                }

            }
        }
        pulos = pp;
    }

    cout << -1 << endl;  

  
    return 0;
}