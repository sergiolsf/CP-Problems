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

int N, M, Q;
vvi g, v;
vector<set<int>> movies;
vi ans;
vector<bool> visited;

bool dfs (int F1, int F2) {
    visited[F1] = true;
    if (F1 == F2) {
        ans.push_back(F2);
        return true;
    }
    
    for (auto e: g[F1]) {
        if (!visited[e]) {
            
            if (dfs (e, F2)) {
                ans.push_back(v[F1][e]);
                ans.push_back(F1);
                return true;
            }
        }
    }

    return false;
}

void print() {
    int sz = ans.size();

    int actor, otherActor;

    for (int i = sz-1; i > 0; i -= 2) {
        actor = i;
        otherActor = i-2;
        if (actor != otherActor) {
            cout << ans[i] << " " << ans[i-1] << " ";
        }
        if (i-2 == 0) cout << ans[i-2];
    }
}

signed main() {
    fastio();

    cin >> N >> M;

    movies.resize(M+1); // filmes que um ator fez
    g.resize(N+1); // ligação entre filmes
    v.resize(N+1, vi(N+1, -1)); // ator que fez os filmes F1 e F2: v[F1][F2]

    /// first step
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            int k;
            cin >> k;
            if (!movies[k].empty()) {
                for (auto e: movies[k]) {
                    if (v[e][i] == -1) {
                        v[e][i] = v[i][e] = k;
                        g[e].push_back(i);
                        g[i].push_back(e);
                    }
                }
            }
            movies[k].insert(i);
        }
    }

    // second step
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int x, y;
        cin >> x >> y;
        int F1, F2;
        if (movies[x].empty() || movies[y].empty()) {
            cout << -1 << endl;
            continue;
        }
        F1 = *movies[x].begin();
        F2 = *movies[y].begin();

        ans.clear();
        ans.push_back(y);
        visited.clear();
        visited.resize(N+1,false);
        if(dfs(F1, F2)) {
            ans.push_back(x);
            cout << (ans.size()+1)/2 << endl;
            print();
        } else {
            cout << -1;
        }
        cout << endl;

    }

    
    return 0;
}