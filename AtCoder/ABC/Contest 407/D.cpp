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

const int MAX_N = 22;

int h, w;
int A[MAX_N][MAX_N];
vector<vector<unsigned>> memo;
int S = 0;

int t(int i, int j) {
    int a = (i-1)*w;
    a += j;
    return --a;
}

pii inv(int pos) {
    int i, j;
    i = pos/w + 1;
    j = pos-(i-1)*w+1;
    return {i, j};
}

int dp(int pos, int mask) {
    auto [i, j] = inv(pos);
    if (i == h && j == w) return S;

    unsigned &ans = memo[pos][mask];
    if (ans != 0) return ans;

    int d1 = -1, d2 = -1, d3 = -1, d4 = -1, d5 = -1;
    int I = i, J = j;
    if (j+1 <= w) J++;
    else {
        I++;
        J = 1;
    }

    d1 = dp(t(I,J), mask);

    if (j+1 <= w && !(mask&(1LL<<t(i, j))) && !(mask&(1LL<<t(i, j+1)))) {
        int m = (1LL<<t(i, j))|(1LL<<t(i, j+1));
        d3 = dp(t(I,J), mask|m)^A[i][j]^A[i][j+1];
    }

    if (i+1 <= h && !(mask&(1LL<<t(i, j))) && !(mask&(1LL<<t(i+1, j)))) {
        int m = (1LL<<t(i, j))|(1LL<<t(i+1, j));
        d2 = dp(t(I,J), mask|m)^A[i][j]^A[i+1][j];
    }

    if (i-1 >= 1 && !(mask&(1LL<<t(i, j))) && !(mask&(1LL<<t(i-1, j)))) {
        int m = (1LL<<t(i, j))|(1LL<<t(i-1, j));
        d4 = dp(t(I,J), mask|m)^A[i][j]^A[i-1][j];
    }

    if (j-1 >= 1 && !(mask&(1LL<<t(i, j))) && !(mask&(1LL<<t(i, j-1)))) {
        int m = (1LL<<t(i, j))|(1LL<<t(i, j-1));
        d5 = dp(t(I,J), mask|m)^A[i][j]^A[i][j-1];
    }

    if (d2 != -1) d1 = max(d1, d2);
    if (d3 != -1) d1 = max(d1, d3);
    if (d4 != -1) d1 = max(d1, d4);
    if (d5 != -1) d1 = max(d1, d5);

    return ans = d1;;
}

signed main() {
    fastio();
    cin >> h >> w;
    memo.resize(t(h, w)+1, vector<unsigned>((1LL<<(h*w))+1, 0));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> A[i][j];
            S ^= A[i][j];
        }
    }
    
    //cout << S << endl;
    cout << dp(t(1,1), 0) << endl;
  
    return 0;
}