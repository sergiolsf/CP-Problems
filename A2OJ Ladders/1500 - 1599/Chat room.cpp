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
    string s;
    cin >> s;
    string h = "helloA";
    int j = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (h[j] == s[i]) j++;
    }
    if (j == 5) cout << "YES\n";
    else cout << "NO\n";
  
    return 0;
}