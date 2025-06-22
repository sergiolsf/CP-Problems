#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef pair<int,int> pii;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ost;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() {
    fastio();
    int n, k; cin >> n >> k;
    vi a(n);
    ost ms;
    for (auto &i: a) cin >> i;

    int m = ((k+1)/2)-1;

    int qnt = 0, ini = 0;
    for (int i = 0; i < n; i++) {
        if (qnt < k) {
            ms.insert({a[i], i});
            qnt++;
        } else {
            cout << ms.find_by_order(m)->first << " ";
            ms.erase({a[ini], ini});
            ini++;
            ms.insert({a[i], i});
        }
    }
    
    cout << ms.find_by_order(m)->first << " ";
  
    return 0;
}