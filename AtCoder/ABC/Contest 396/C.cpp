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
    vi a(n);
    for (auto &i: a) cin >> i;

    map<int,int> mp1;
    map<int,int> mp2;
    for (int i: a) {
        if (mp2.count(i)) mp2[i]++;
        else mp2[i] = 1;
    }

    int ans =  0;

    for (int i: a) {
        mp2[i]--;
        if(mp2[i] == 0) mp2.erase(i);
        if (!mp1.count(i)) mp1[i] = 1;

        ans = max(ans, (int)mp1.size() + (int)mp2.size());
    }

    cout << ans << endl;   
  
    return 0;
}