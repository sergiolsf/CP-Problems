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
    vi a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int sum = 0, cont = 0;
    priority_queue<int> negativos;

    for (int i = 1; i <= n; i++) {
        if (a[i] >= 0) {
            sum += a[i];
            cont++;
        }
        else {
            if (a[i]+sum >= 0) {
                negativos.push(-a[i]);
                sum += a[i];
                cont++;
            } else {
                if (negativos.empty()) continue;
                int u = negativos.top();
                if (u > -a[i]) {
                    negativos.pop();
                    negativos.push(-a[i]);
                    sum += u + a[i];
                }
            }
        }
    }

    cout << cont << endl;
  
    return 0;
}