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

vvi g;

vi ans;

int sub (int i) {
    if (ans[i] != -1) return ans[i];
    int a = 0;
    for (auto e: g[i]) {
        a += sub(e)+1;
    }
    ans[i] = a;
    return a;
}

signed main() {
    fastio();
    int n;
    cin >> n;

    g.resize(n+1);
    ans.resize(n+1, -1);

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << sub(i) << " ";
    }

    cout << endl;
    
    return 0;
}