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
    int a, b;
    int ans = 1;
    for (int i = 0; i < s.size()-1; i++) {
        a = s[i]-'0';
        b = s[i+1]-'0';
        if (a >= b) {
            ans += a-b;
            ans++;
        } else {
            ans += 9-(b-a-1);
            ans++;
        }
    }

    a = s[s.size()-1]-'0';
    ans += a;

    cout << ans << endl;
  
    return 0;
}