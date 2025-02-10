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
    int N;
    double ans = 0;
    cin >> N;
    vector<map<int,int>> vp (N+1);
    vi K(N+1);
    vvi A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
        for (int j = 1; j <= K[i]; j++) {
            int a;
            cin >> a;
            if (vp[i].count(a)) {
                vp[i][a]++;
            } else {
                vp[i][a] = 1;
                A[i].push_back(a);
            }
        }
    }

    for (int i = 1; i < N; i++) {
        int k1 = A[i].size();
        for (int j = i+1; j <= N; j++) {
            double d = 0;
            int k2 = K[j];
            for (int k = 0; k < k1; k++) {
                int a = A[i][k];
                if (vp[j].count(a)) {
                    int p = vp[i][a]*vp[j][a];
                    double m = (double) p / (double) (K[i]*k2);
                    d += m;
                }
            }
            ans = max(ans, d);
        }
    }
  
    cout << setprecision(20) << ans << endl;
    return 0;
}