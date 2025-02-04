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

vi a(10);
pii nulo = {0,0};
vi res(10);
 
// quant de numeros, soma dos numeros
pii dp(int i, int v) {
    if (i > 9) return nulo;
    pii p1 = dp(i+1, v);

    pii p2 = nulo;
    if (v-a[i] >= 0) {
        p2 = dp(i, v-a[i]);
        p2.first++;
        p2.second += i;
    }
    
    pii ans;
    if (p1.first > p2.first) {
        ans = p1;
    } else if (p1.first < p2.first) {
        ans = p2;
        res[i]++;
    } else {
        if (p1.second > p2.second) {
            ans = p1;
        } else {
            ans = p2;
            res[i]++;
        }
    }

    return ans;   
}

signed main() {
    fastio();
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        cin >> a[i];
    }

    pii p = dp(1, n);

    if (p.first == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 9; i >= 1; i--) {
            for (int j = 1; j <= res[i]; j++) {
                cout << i;
            }
        }
        cout << endl;
    }
  
    return 0;
}