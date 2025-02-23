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

bool s(string a, string b) {
    return ((int) a.size() < (int) b.size());
}

signed main() {
    fastio();
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v), s);

    for (int i = 0; i < n; i++) cout << v[i];
    cout << endl;
  
    return 0;
}