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

const int MAX_N = 10;
int ans = INF;
int n, m; 

bool g[MAX_N][MAX_N];

void backtrack (int u, vector<vector<bool>> adj, int cont) {

    bool f = true;
    for (int i = 1; i <= n; i++) {
            int C = 0;
            for (int j = 1; j <= n; j++) {
                if (adj[i][j]) C++;
            }
            if (C != 2) f = false;
    }

    if (f) {
        int A = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (adj[i][j] && g[i][j]) A++;
            }
        }

        int B = (m-A) + (cont-A);
        
        ans = min(ans, B);
        return;
    }

    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[u][i]) c++;
    }

    if (c == 0) {
        for (int i = u+1; i < n; i++) {
            int c1 = 0;
            for (int k = 1; k <= n; k++) {
                if (adj[i][k]) c1++;
            }

            if (c1 == 2) continue;

            for (int j = i+1; j <= n; j++) {
                int c2 = 0;
                for (int k = 1; k <= n; k++) {
                    if (adj[j][k]) c2++;
                }

                if (c2 == 2) continue; 

                adj[i][u] = adj[u][i] = adj[u][j] = adj[j][u] = true;          
                backtrack(u+1, adj, cont+2);
                adj[i][u] = adj[u][i] = adj[u][j] = adj[j][u] = false; 
            }
        }
    } else if (c == 1) {
        for (int j = u+1; j <= n; j++) {
            int c1 = 0;
            for (int k = 1; k <= n; k++) {
                if (adj[j][k]) c1++;
            }
            if (c1 == 2) continue;      

            adj[u][j] = adj[j][u] = true;          
            backtrack(u+1, adj, cont+1);
            adj[u][j] = adj[j][u] = false;
        }
    } else {
        backtrack(u+1, adj, cont);
    }
}

signed main() {
    fastio();
    cin >> n >> m;  

    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 1; j <= MAX_N; j++) {
            g[i][j] = false;
        }
    }

    int aum = 0;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        if (g[b][a]) aum++;
        g[a][b] = g[b][a] = true;
    }

    vector<vector<bool>> adj (MAX_N, vector<bool> (MAX_N, false));

    backtrack(1, adj, 0);

    cout << ans+aum << endl;

    return 0;
}