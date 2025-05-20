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

const int MAX_N = 105;

vvi grid(MAX_N, vi (MAX_N));

signed main() {
    fastio();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            set<int> st;
            for (int k = 1; k < j; k++) st.insert(grid[i][k]);
            for (int k = 1; k < i; k++) st.insert(grid[k][j]);
            int cont = 0;
            for (auto e: st) {
                if (cont != e) {
                    break;
                }
                cont++;
            }
            grid[i][j] = cont;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << (j == n ? "\n" : " ");
        }
    }
  
    return 0;
}