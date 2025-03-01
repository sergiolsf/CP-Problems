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

#define MAXN 55
char grid[MAXN][MAXN];

signed main() 
{
    fastio();
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            grid[i][j] = '.';
        }
    }

    int m = (n+1)/2;
    
    for (int camada = 1; camada <= m; camada++) {
        if (camada%2 == 0) continue;
        for (int i = camada; i <= n-camada+1; i++) 
        {
            for (int j = camada; j <= n-camada+1; j++) 
            { 
                if (i == camada || i == n-camada+1) grid[i][j] = '#';
                if (j == camada || j == n-camada+1) grid[i][j] = '#';
            }
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
  
    return 0;
}