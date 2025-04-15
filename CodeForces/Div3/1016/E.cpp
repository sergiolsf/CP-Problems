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

const int MAX_N = 200'005;

int n, k; 
int a[MAX_N];

bool f(int x) {
    int qnt = 0;
    vector<bool> vb (x+1, false);
    int tem = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x && !vb[a[i]]) {
            tem++;
            vb[a[i]] = true;
        }
        if (tem == x+1) {
            qnt++;
            tem = 0;
            for (int j = 0; j <= x; j++) vb[j] = false;
        }
    }


    return (qnt >= k);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int lo = 0, hi = 200'001;
    while (hi-lo != 1) {
        int m = (hi+lo)/2;
        if (f(m-1)) lo = m;
        else hi = m;
    }
    
    cout << lo << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}