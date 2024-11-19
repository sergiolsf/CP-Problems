///Tudo o que Você Precisa é Amor
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
}

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a%b) : a;
}

signed main() {
    fastio();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        bitset<30> b1, b2;
        cin >> b1 >> b2;

        int i1 = b1.to_ullong();
        int i2 = b2.to_ullong();

        cout << "Pair #" << i << ": ";
        if (i1 == i2 || gcd(i1,i2) > 1) {
            cout << "All you need is love!" << endl;
        } else {
            cout << "Love is not all you need!" << endl;
        }

    }


    
    return 0;
}