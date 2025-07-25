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
    vi v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') v.push_back(i+1);
    }
    for (int i = 0; i < v.size(); i+=2) {
        cout << v[i] << "," << v[i+1] << endl;
    }
  
    return 0;
}