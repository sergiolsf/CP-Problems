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

const int MAXN = 200'010;

vi adj[MAXN];
bool removedNode[MAXN]; 
int degNode[MAXN];     
int sizeAnts[MAXN];    
signed main() {
    fastio();
    int n; cin >> n;
    
    if (n == 1) {
        cout << "YES\n";
        return 0;
    }
    
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        removedNode[i] = false;
        sizeAnts[i] = 1; 
    }
    for (int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++){
        degNode[i] = adj[i].size();
    }
    
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    
    for(int i = 1; i <= n; i++){
        if(degNode[i] == 1) {
            pq.push({sizeAnts[i], i});
        }
    }
    
    int removalsNeeded = n - 1;
    
    while (removalsNeeded > 0 && !pq.empty()) {
        auto [leafSize, leaf] = pq.top(); 
        pq.pop();
        
        if(removedNode[leaf]) continue;
        if(degNode[leaf] != 1) continue; 
        
        int parent = -1;
        for(int nx : adj[leaf]){
            if(!removedNode[nx]) {
                parent = nx;
                break;
            }
        }
        
        if (parent == -1) {
            cout << "NO\n";
            return 0;
        }
        
        if (sizeAnts[parent] < sizeAnts[leaf]) {
            cout << "NO\n";
            return 0;
        }
        
        sizeAnts[parent] += sizeAnts[leaf];
        removedNode[leaf] = true;
        sizeAnts[leaf] = 0;
        degNode[leaf] = 0;
        degNode[parent]--;
        removalsNeeded--;
        
        if (!removedNode[parent] && degNode[parent] == 1) {
            pq.push({sizeAnts[parent], parent});
        }
    }
    
    if (removalsNeeded == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
