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

int dp(int i){
    if (i == 2) {
        return 2;
    }

    return dp(i-2)*2;
}

signed main() {
    fastio();
    int n;
    cin >> n;
    if (n&1) {
        cout << 0 << endl;
        return 0;
    }

    cout << dp(n) << endl;


    
    return 0;
}