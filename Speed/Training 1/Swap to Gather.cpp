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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cont = 0;
    vi v;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '1') {
            cont++;
            v.pb(i);
        }
    }
    int ans = 0;

    if (cont&1 && cont > 1) {
        int c = cont/2;
        int pos = v[c]-1;
        for (int i = c-1; i >= 0; i--) {
            ans += pos-v[i];
            pos--;
        }
        pos = v[c]+1;
        for (int i = c+1; i < cont; i++) {
            ans += v[i]-pos;
            pos++;
        }
    } else {
        int c = cont/2;
        int pos = v[c-1]-1;
        for (int i = c-2; i >= 0; i--) {
            ans += pos-v[i];
            pos--;
        }
        pos = v[c]+1;
        for (int i = c+1; i < cont; i++) {
            ans += v[i]-pos;
            pos++;
        }
        ans += c*(v[c]-v[c-1]-1);
    }

    cout << ans << endl;
  
    return 0;
}