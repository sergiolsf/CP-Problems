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

const int MAX_N = 100'005;

bool visited[MAX_N];
bool finished[MAX_N];
vvi adj(MAX_N);
int start;
bool cycle = false;
int p[MAX_N];

void dfs(int u) {
    if (cycle) return;
    visited[u] = true;
    for (auto e: adj[u]) {
        if (cycle) return;
        if (!visited[e]) {
            p[e] = u;
            dfs(e);
        } else {
            if (finished[e]) continue;
            p[e] = u;
            start = e;
            cycle = true;
            return;
        }
    }
    finished[u] = true;
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i <= n && !cycle; i++) {
        if (!visited[i]) dfs(i);
    }

    if (!cycle) cout << "IMPOSSIBLE\n";
    else {
        stack<int> st;
        st.push(start);
        int u = p[start];
        while (start != u) {
            st.push(u);
            u = p[u];
        }
        st.push(u);

        cout << st.size() << endl;
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }

    return 0;
}