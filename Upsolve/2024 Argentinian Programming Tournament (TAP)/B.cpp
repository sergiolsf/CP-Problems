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

void solve (int n) {
    //cout << n << ":\n";
    vi ans;    
    
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            ans.push_back(i);
            if (n/i != i) ans.push_back(n/i);
        }
    }

    if (ans.size() == 0) {
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
    } else {
        for (int i = ans.size()-1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (ans[i]%ans[j] == 0) ans[j] = 1;
                else if (ans[j]%ans[i] == 0) ans[i] = 1;
            }
        }

        vi ans2;
        for (auto e : ans) if (e != 1) ans2.push_back(e);

        if (ans2.size() == 0) {
            cout << 1 << endl;
            cout << 1 << " " << 1 << endl;
        } else {
            cout << ans2.size() << endl;
            for (auto e: ans2) 
                cout << 1 << " " << e << endl;
        }
    }
}

signed main() {
    fastio();
    int n; cin >> n;
    //for (int i = 10; i <= 60; i++)
    solve(n);
    return 0;
}