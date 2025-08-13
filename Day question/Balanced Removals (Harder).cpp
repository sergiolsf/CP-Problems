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

struct point {
    int x, y, z, pnt;
    // ordenar por z, x, y
};

int n; 
vector<point> p;
vector<pii> ans;
vector<int> sobra;

// nivel = 0 (z), 1 (x), 2 (y)
void solve(int nivel, int pos, int ini, int fim) {
    if (pos == fim) return;
    if (nivel == 0) {
        if (pos == fim-1 || p[pos+1].z != p[pos].z) {
            solve (1, ini, ini, pos+1);
            solve (0, pos+1, pos+1, fim);
            return;
        } else {
            solve (0, pos+1, ini, fim);
            return;
        }
    } else if (nivel == 1) {
        if (pos == fim-1 || p[pos].x != p[pos+1].x) {
            solve (2, ini, ini, pos+1);
            solve (1, pos+1, pos+1, fim);
        } else {
            solve (1, pos+1, ini, fim);
        }
    } else {
        if (fim-ini %2 == 1) {
            fim--;
            sobra.push_back(p[fim].pnt);
        }
        for (int i = ini; i < fim; i+=2) {
            ans.push_back({})
        }
    }
}

signed main() {
    fastio();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        point t;
        cin >> t.x >> t.y >> t.z;
        t.pnt = i;
        p.push_back(t);
    }

    sort(all(p));
  
    
  
    return 0;
}