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

int n;

const int MAX_N = 10'005;
const int MAX_P = 1'001;

int P[MAX_N];
int A[MAX_N];
int B[MAX_N];
int sumAcum[MAX_N];
int res[MAX_P][MAX_N];

signed main() {
    fastio();
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> P[i] >> A[i] >> B[i];
        sumAcum[i] = sumAcum[i-1] + B[i];
    }

    for (int i = 0; i <= 1000; i++) {
        int ans;

        if (i <= P[n]) ans = i+A[n];
        else ans = max(i-B[n], 0LL);

        res[i][n] = ans;
    }

    for (int j = n-1; j >= 1; j--) {
        for (int i = 0; i <= 1000; i++) {
            int ans;

            if (i <= P[j]) ans = i+A[j];
            else ans = max(i-B[j], 0LL);

            res[i][j] = res[ans][j+1];
        }
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;

        if (x - sumAcum[n-1] > 500) {
            cout << x-sumAcum[n] << endl;
            continue;
        }

        int lo = 0, hi = n;
        while (hi-lo > 1) {
            int m = (hi+lo)/2;
            if (x-sumAcum[m] > 500) lo = m;
            else hi = m;
        }
        cout << res[x-sumAcum[hi-1]][hi] << endl;
    }
  
    return 0;
}