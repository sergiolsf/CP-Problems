#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
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
    int n;
    cin >> n;
    vector<pii> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }

    sort(all(movies));

    int ult = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (movies[i].second >= ult) {
            ult = movies[i].first;
            ans++;
        }
    }   

    cout << ans << endl;    
    return 0;
}