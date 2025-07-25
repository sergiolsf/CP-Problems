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
bool cont[105];

signed main() {
    fastio();
    int n; cin >> n;
    while (n--) {
        int a; cin >> a;
        cont[a] = true;
    }
    int x; cin >> x;
    cout << (cont[x]? "Yes\n" : "No\n");
    
  
    return 0;
}