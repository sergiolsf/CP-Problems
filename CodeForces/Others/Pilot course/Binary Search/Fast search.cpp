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
    int n;
    cin >> n;
    vi a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }

    sort(all(a));

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int ri, le;
        cin >> ri >> le;

        int l = -1, r = n;
        while (r-l != 1) {
            int m = (r+l)/2;
            if (a[m] < ri) l = m;
            else r = m;
        }
        int h1 = r;

        l = -1; r = n;
        while (r-l != 1) {
            int m = (r+l)/2;
            if (a[m] <= le) l = m;
            else r = m;
        }
        int h2 = l;

        cout << h2-h1+1 << " ";
    }

    cout << endl;    
    return 0;
}