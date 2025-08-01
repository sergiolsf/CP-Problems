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
    int n, k; cin >> n >> k;
    map<int,int> mp;
    for (int i = 1; i <= k+1; i++) {
        cout << "?";
        for (int j = 1; j <= k+1; j++) {
            if (i != j) {
                cout << " " << j;
            }
        }
        cout << endl;
        cout.flush();
        int a, b; cin >> a >> b;

        if (mp.count(b)) mp[b]++;
        else mp[b] = 1;
    }

    auto it = mp.end();
    --it;
    cout << "! " << it->second << endl;
    cout.flush();
    return 0;
}