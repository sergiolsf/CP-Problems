#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int MOD = 1'000'000'007;
const int MAXN = 2;
struct Matrix {int mat[MAXN][MAXN];};

int mod(int a, int m) {
    return ((a%m)+m)%m;
}

Matrix matMul(Matrix a, Matrix b) {
    Matrix ans;
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            ans.mat[i][j] = 0;
    for (int i = 0; i < MAXN; i++)
        for (int k = 0; k < MAXN; k++) {
            if (a.mat[i][k] == 0) continue;
            for (int j = 0; j < MAXN; j++) {
                ans.mat[i][j] += mod(a.mat[i][k], MOD)*mod(b.mat[k][j], MOD);
                ans.mat[i][j] = mod(ans.mat[i][j], MOD);
            }
        }
    return ans;
}

Matrix matpow(Matrix base, int p) {
    Matrix ans;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++)
            ans.mat[i][j] = (i == j);
    }
    while (p) {
        if (p&1)
            ans  = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

signed main() {
    fastio();
    int n; cin >> n;

    Matrix m;
    m.mat[0][0] = 1; m.mat[0][1] = 1;
    m.mat[1][0] = 1; m.mat[1][1] = 0;

    Matrix ans;
    ans = matpow(m, n);

    int p = ans.mat[0][1];

    cout << p << endl;
    return 0;
}