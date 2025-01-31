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

vi a;

bool bb(int ini, int fim, int x) {

    if (fim < ini) return false;

    int med = (ini+fim)/2;
    if (a[med] == x) {
        return true;
    }

    if (a[med] < x) {
        return bb(med+1, fim, x);
    }

    return bb(ini, med-1, x);
}

signed main() {
    fastio();

    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a.pb(t);
    }

    for (int i = 1; i <= k; i++) {
        int b;
        cin >> b;
        if (bb(0, n-1, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}