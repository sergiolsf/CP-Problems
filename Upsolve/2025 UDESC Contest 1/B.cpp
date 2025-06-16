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
    string s; cin >> s;
    string sord = s;
    sort(all(sord));

    int i = 0;
    for (;i < n; i++) {
        if (sord[i] != s[i]) break;
    }

    if (i == n) {
        cout << s << endl;
        return 0;
    }

    int j = n-1;
    for (; j >= 0; j--) {
        if (s[j] == sord[i]) break;
    }

    swap(s[i], s[j]);

    cout << s << endl;
  
    return 0;
}