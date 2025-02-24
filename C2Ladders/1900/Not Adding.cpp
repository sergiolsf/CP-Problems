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

const int MAXN = 1e6+4;
vector<bool> v(MAXN);

signed main() {
    fastio();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x] = true;
    }

    
    int ans = 0;
    for (int i = 1e6; i > 0; i--) {
        if (v[i]) continue;
        int sum = 0;
        int ant;
        for (int j = i; j <= 1e6; j+=i) {
            if (v[j]) {
                if (sum == 0) {
                    sum++;
                    ant = j;
                } else {
                    if (j%ant) {
                        sum++;
                        break;
                    }
                }
            }
        }
        if (sum > 1) {
            ans++;
            v[i] = true;
        }
    }


    cout << ans << endl;
  
    return 0;
}