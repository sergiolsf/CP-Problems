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

signed main() {
    fastio();
    int n; cin >> n;
    
    multiset<int> ms;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        auto it = ms.upper_bound(k);
        if (it != ms.end()) ms.erase(it);
        ms.insert(k); 
    }

    cout << ms.size() << endl;
  
    return 0;
}