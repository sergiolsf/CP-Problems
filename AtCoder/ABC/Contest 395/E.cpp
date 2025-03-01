#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int INF = 1e18;

signed main(){
    fastio();
    int N, M, X;
    cin >> N >> M >> X;
    vvi f(N+1), b(N+1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        f[u].push_back(v);
        b[v].push_back(u);
    }

    vvi dist(N+1, vi(2, INF));
    dist[1][0] = 0;
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    pq.push({0,{1,0}});

    while (!pq.empty())
    {
        pair<int,pii> topo = pq.top();
        pq.pop();
        int c = topo.first;
        int v = topo.second.first;
        int d = topo.second.second;
        if (c > dist[v][d]) continue;
        vi p;
        if (d == 0) p = f[v];
        else p = b[v];
        for (auto e : p)
        {
            int cost = c+1;
            if (cost < dist[e][d])
            {
                dist[e][d]=cost;
                pq.push({cost,{e,d}});
            }
        }
        int k = c+X;
        if (k < dist[v][1-d])
        {
            dist[v][1-d] = k;
            pq.push({k,{v,1-d}});
        }
    }

    cout << min(dist[N][0], dist[N][1]) << endl;

    return 0;
}
