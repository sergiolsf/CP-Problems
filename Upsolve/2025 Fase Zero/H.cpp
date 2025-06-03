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

int transf(vi a) {
    int n = 1;
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) ans += n; 
        n *= 2;
    }
    return ans;
}

signed main() {
    fastio();
    int n; cin >> n;
    int N = n;
    vi bin;
    while (n) {
        bin.push_back(n%2);
        n /= 2;
    }

    int i = bin.size()-1;
    int j = 0;
    bool flag = false;
    while (j < i) {
        if (bin[i] != bin[j]) {
            if (!flag) {
                bin[j] = bin[i] = 1;
                flag = true;
            } else {
                bin[j] = bin[i] = 0;
            }
        }
        j++;
        i--;
    }

    int num = transf(bin);
    if (num > N) {
        bin[i] = bin[j] = 0;
        num = transf(bin);
    }

    cout << num << endl;
  
    return 0;
}