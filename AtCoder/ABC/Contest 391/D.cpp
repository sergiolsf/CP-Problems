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

const int INF = 1e10;

signed main() {
    fastio();
    int N, W;
    cin >> N >> W;
    vvi col(W+1);
    vi blocks(N+1, INF);
    map<pii, int> mp;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        mp[{x,y}] = i;
        col[x].pb(y);
    }

    int menor = INF;

    for (int i = 1; i <= W; i++) {
        sort(all(col[i]));
        menor = min(menor, (int) col[i].size());
    }

    int tira = W*menor;

    vvi tempo;

    int j = 0;
    int tAnt = -1;
    while(tira) {
        int t = tAnt;
        for (int i = 1; i <= W; i++) {
            int y = col[i][j];
            t = max(t, y);
            /*if (j == 0) {
                t = max(t, y);
            } else {
                t = max(t, y);
            }*/
        }
        tAnt = t;
        for (int i = 1; i <= W; i++) {
            int y = col[i][j];
            int k = mp[{i,y}];
            blocks[k] = t;
        }
        j++;
        tira -= W;
    }

    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int a, b;
        cin >> a >> b;
        if (blocks[b] <= a) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
  
    return 0;
}