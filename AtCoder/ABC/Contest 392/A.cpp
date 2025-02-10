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
    vi a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(all(a));
    if (a[0]*a[1] == a[2]) cout << "Yes\n";
    else cout << "No\n";

  
    return 0;
}