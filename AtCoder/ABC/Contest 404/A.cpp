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
    vector<bool> v(26, false);
    string s; cin >> s;
    for (int i=0; i < s.size(); i++) {
        v[(int) (s[i]-'a')] = true;
    }

    for (int i = 0; i < 26; i++) {
        if (!v[i]) {
            char c = 'a'+i;
            cout << c << endl;
            return 0;
        }
    }
}