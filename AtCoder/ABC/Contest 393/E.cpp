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

const int MAXA = 1e6;

signed main() {
    fastio();
    int n, k;
    vi v(MAXA+1, 0);
    vi mdc(MAXA+1, 0);

    cin >> n >> k;

    vi a(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]]++;
    }

    for (int i = MAXA; i > 0; i--) {
        int sum = 0;
        for (int j = i; j <= MAXA; j+=i) {
            sum += v[j];
        }
        if (sum >= k)
            for (int j = i; j <= MAXA; j+=i) {
                mdc[j] = max(mdc[j], i);
            }
    }

    for (int i = 1; i <= n; i++) {
        cout << mdc[a[i]] << endl;
    }
  
    return 0;
}