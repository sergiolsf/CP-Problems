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

const int MAXN = 55;
const int MOD = 1e9+7;
int n, m, k; 

struct Matrix {
    int mat[MAXN][MAXN];
};

int mod(int a) {
    return ((a%MOD)+MOD)%MOD;
}

Matrix matMul(Matrix a, Matrix b) {
    Matrix ans;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) 
            ans.mat[i][j] = 0;
    for (int i = 0; i < m; i++) 
        for (int k = 0; k < m; k++) {
            if (a.mat[i][k] == 0) continue;
            for (int j = 0; j < m; j++) {
                ans.mat[i][j] += mod(a.mat[i][k])*mod(b.mat[k][j]);
                ans.mat[i][j] = mod(ans.mat[i][j]);
            }
        }
    return ans;
}

Matrix matPow(Matrix base, int p) {
    Matrix ans;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            ans.mat[i][j] = (i == j);
    while (p) {
        if (p&1)
            ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

signed main() {
    fastio();
    cin >> n >> m >> k;

    Matrix g;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            g.mat[i][j] = 1;
        }
    }
    for (int i = 0; i < k; i++) {
        string s; cin >> s;
        int a = s[0]-'a';
        if (a < 0) a = (s[0]-'A')+26;
        int b = s[1]-'a';
        if (b < 0) b = (s[1]-'A')+26;
        g.mat[a][b] = 0;
    }

    if (n == 1) {
        cout << m << endl;
    } else {
        Matrix ans = matPow(g, n-1);
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                sum = (sum+ans.mat[i][j])%MOD;
            }
        }
        cout << sum%MOD << endl;
    }
  
    return 0;
}