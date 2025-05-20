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

const int MAX_N = 5005;

string x, y;
int n, m;
vvi memo(MAX_N, vi (MAX_N, -1));

int cost(int a, int b) {
    if (x[a] == y[b]) return 0;
    return 1;
}

int distance(int a, int b) {
    if (a == -1) return b+1;
    if (b == -1) return a+1;

    int &ans = memo[a][b];
    if (ans != -1) return ans;

    int d1 = distance(a, b-1)+1;
    int d2 = distance(a-1, b)+1;
    int d3 = distance(a-1, b-1)+cost(a,b);
    return ans = min({d1, d2, d3});
}

signed main() {
    fastio();
     cin >> x >> y;
     n = x.size();
     m = y.size();

     cout << distance(n-1, m-1) << endl;
  
    return 0;
}