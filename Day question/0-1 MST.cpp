#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;

    if (m == (n * (n - 1)) / 2) {
        cout << n - 1 << '\n';
        return 0;
    }

    vector<set<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    set<int> unvisited;
    for (int i = 1; i <= n; i++) {
        unvisited.insert(i);
    }

    int comp = 0;
    for (int i = 1; i <= n; i++) {
        if (unvisited.find(i) == unvisited.end()) 
            continue;

        comp++;
        queue<int> q;
        q.push(i);
        unvisited.erase(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            auto it = unvisited.begin();
            while (it != unvisited.end()) {
                int v = *it;
                if (adj[u].find(v) != adj[u].end()) {
                    it++;
                } else {
                    it = unvisited.erase(it);
                    q.push(v);
                }
            }
        }
    }

    cout << comp - 1 << '\n';
    return 0;
}