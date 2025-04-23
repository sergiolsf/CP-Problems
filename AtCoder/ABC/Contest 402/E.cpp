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

const int MAX_N = 21;
int n, m; 
vvi grid(MAX_N, vi(MAX_N));
vi mult; /// preencher com os restos de potencia de 10

int dp(int i, int j, int pos) {
    if (i == n && j == n) return grid[n][n]%m


    int x = ((grid[i][j]%m)*mult[pos])%m;
    if (i == n) return (x + dp(i, j+1, pos-1))%m;
    else if (j == n) return (x + dp(i+1, j))%m;
    int d1 = (x + dp(i, j+1, pos-1))%m;
}

signed main() {
    fastio();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    

    
    
  
    return 0;
}