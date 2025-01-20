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
int N, M;
vi P;

bool ok(int x) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        //int k = (x+P[i])/(2*P[i]);
        int k = (x)/(2*P[i]);
        if (P[i]*(2*k+1) <= x) k++;
        sum += k*k*P[i];
    }
    return (sum <= M);
}

signed main() {
    fastio();
    
    cin >> N >> M;
    P.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int x = -1;
    for (int b = M+1; b >= 1; b /= 2) {
        while (ok(x+b)) x += b;
    }

    int sum = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        //int k = (x+P[i])/(2*P[i]);
        int k = (x)/(2*P[i]);
        if (P[i]*(2*k+1) <= x) k++;
        sum += k*k*P[i];
        ans += k;
    }

    for (int i = 0; i < N; i++) {
        //int k = (x+P[i])/(2*P[i]);
        int k = (x)/(2*P[i]);
        if (P[i]*(2*k+1) <= x) k++;
        if ((2*(k+1)-1)*P[i] == x+1) {
            if (sum+x+1 <= M) {
                sum += x+1;
                ans++;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
