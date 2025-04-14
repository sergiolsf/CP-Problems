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

int n; 

int F (int v, int k) {
    return v*(n+1)+k;
}

signed main() {
    fastio();
    cin >> n;
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;

    int f1 = F(a, b);
    int f2 = F(c, d);

    cout << f2 - f1 << endl;
  
    return 0;
}