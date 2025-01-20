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

vi v(1e6+1, 0);

signed main() {
    fastio();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }

    for (int i = 1e6; i > 0; i--) {
        int sum = 0;
        for (int j = i; j <= 1e6; j += i) {
            sum += v[j];
            if (sum >= 2) { 
                cout << i << endl;
                return 0;
            }
        }
    }
    
    return 0;
}