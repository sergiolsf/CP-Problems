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



void solve() {

    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vvi f, g, novoF;
    f.resize(n+1);
    g.resize(n+1);
    novoF.resize(n+1);

    vi ccF(n+1, 0);
    vi ccG(n+1, 0);
    vi cc(n+1, 0);

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        f[u].push_back(v);
        f[v].push_back(u);
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> visitedg(n+1, false);
    int c = 1;
    for (int i = 1; i <= n; i++) {
        if (!visitedg[i]) {
            queue<int> q;

            visitedg[i] = true;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                ccG[node] = c;

                for (int e : g[node]) {
                    if (!visitedg[e]) {
                        visitedg[e] = true;
                        q.push(e);
                    }
                }
            }
            
        }
        c++;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (auto e: f[i]) {
            if (ccG[e] == ccG[i]) {
                novoF[i].push_back(e);
            } else {
                ans++;
            }
        }
    }

    ans /= 2;


    vector<bool> visitedf(n+1, false);
    c = 1;
    for (int i = 1; i <= n; i++) {
        if (!visitedf[i]) {
            queue<int> q;

            visitedf[i] = true;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                ccF[node] = c;
                for (int e : novoF[node]) {
                    if (!visitedf[e]) {
                        visitedf[e] = true;
                        q.push(e);
                    }
                }
            }
            
        }
        c++;
    }

    set<int> st;

    for (int i = 1; i <= n; i++) {
        if (ccG[i] != ccF[i]) {
            if(!st.count(ccF[i]) && g[i].size()) {
                ans++;
                st.insert(ccF[i]);
            }
        }
    }

    cout << ans << endl;  

    
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