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

const int MAXX = 5e5+5;

signed main() {
    fastio();
    
    int q;
    cin >> q;

    vector<pii> v;
    vector<pair<int, pii>> two;

    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            v.pb({i,x});
        } else {
            int x, y;
            cin >> x >> y;
            two.pb({i, {x,y}});
        }
    }

    int j = (int)v.size()-1;
    int k = q;
    int p = (int)two.size()-1;

    if (p < 0) {
        for (int i = 0; i < (int) v.size(); i++) {
            cout << v[i].second << " ";
        }
        cout << endl;
        return 0;
    }

    vi ans(MAXX, 0);

    while (j >= 0) {
        int i1 = v[j].first, val = v[j].second;
        int x, y;
        if (p >= 0)  { 
            x = two[p].second.first;
            y = two[p].second.second;
        }

        if (i1 == k) {
            if (ans[val] != 0) v[j].second = ans[val];
            j--;
        } else {
            int u = ans[y];
            ans[x] = y;
            if (u != 0) ans[x] = u;
            p--;
        }
        k--;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second << " ";
    }
    cout << endl;
  
    return 0;
}