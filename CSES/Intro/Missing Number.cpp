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

signed main() {
    fastio();
    int sum = 0, tot = 0;
    int n; 
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        tot += x;
        sum += i;
    }

    cout << sum - tot + n << endl;
    
    return 0;
}