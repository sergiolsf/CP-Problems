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
    if (n >= 3 && s[n-1] == 'a' && s[n-2] == 'e' && s[n-3] == 't') cout << "Yes\n";
    else cout << "No\n";

  
    return 0;
}