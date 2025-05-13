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

const int MAX_N = 10'001;

signed main() {
    fastio();
    int n; cin >> n;
    vi v(MAX_N, 0);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x]++;
    }

    int ans = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (v[i] == 0) continue;
        ans += i*i*(v[i]*(v[i]-1)/2);
        for (int j = i+1; j < MAX_N; j++) {
            ans += i*j*v[i]*v[j];
        }
    }

    cout << ans << endl;
  
    return 0;
}