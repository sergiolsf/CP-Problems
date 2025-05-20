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
    string s; cin >> s;
    if (s == "?R-SP" || s == "B?-SP" || s == "BR?SP") cout << "S\n";
    else if (s == "BR-?P" || s == "BR-S?") cout << "T\n";
    else cout << "N\n";
  
    return 0;
}