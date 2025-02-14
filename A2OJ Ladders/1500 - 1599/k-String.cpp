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

vi cont(30, 0);

signed main() {
    fastio();
    int k;
    string s;
    cin >> k >> s;

    for (int i = 0; i < (int)s.size(); i++) {
        int d = s[i]-'a';
        cont[d]++;
    }

    string ans;
    for (int i = 0; i <= 27; i++) {
        if (cont[i]%k != 0) {
            cout << -1 << endl;
            return 0;
        }
        char c = 'a'+i;
        for (int j = 1; j <= cont[i]/k; j++) {
            ans.pb(c);
        }
    }

    for (int i = 0; i < k; i++) {
        cout << ans;
    }
    cout << endl;
    
  
    return 0;
}