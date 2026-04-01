#include<bits/stdc++.h>
// #include "bits/stdc++.h"
using namespace std;
#define ull       unsigned long long
#define SPEEDHACK ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff        first
#define ss        second
#define sz(v)     (ll)(v).size()
#define file      freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define mod             1000000007
// #define mod             998244353 
#define inv 499122177
#define pb push_back
#define all(a) a.begin(), a.end()
const double eps = 1e-2;
#define ll       long long
#define rep(i, c) for(int i = 0; i < (int)c; i++)
#define ri(i) for (auto &i : a) cin >> i
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template<class T> using P = pair<T, T>;
using vi = vector<int>;
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair
// int dx[] = { 1,0,-1,0,1,1,-1,-1 };
// int dy[] = { 0,1,0,-1,1,-1,1,-1 };
// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[] = {0,1,0,-1,0};

string stepDir = "URDL";


void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void radix_sort(vector<int> &a) {
    int n = (int) a.size();

    int base = 1 << 16;
    int mask = base - 1;

    vector<int> tmp(n);

    for (int shift = 0; shift < 32; shift += 16) {
        // counting sort

        vector<int> cnt(base, 0);
        for (int i = 0; i < n; i++) {
            int digit = (a[i] >> shift) & mask;
            cnt[digit]++;
        }

        // prefix sum
        for (int i = 1; i < (int) cnt.size(); i++) {
            cnt[i] += cnt[i-1];
        }


        for (int i = n-1; i  >= 0; i--) {
            int digit = (a[i] >> shift) & mask;
            tmp[--cnt[digit]] = a[i];
        }

        a.swap(tmp);

    }
}

void solve() {
    int n;
    int a,b,c,x,y;
    cin >> n >> a >> b >> c >> x >> y;

    // cout << n << " " << a << " " << b << " " << c << " " << x << " " << y << endl;

    vector<int> s(n);
    s[0] = a;
    for (int i = 1; i < n; i++) {
        s[i] = (int) (((ll)s[i-1] * b + a) % c);
    }

    radix_sort(s);





    int v = 0;
    for (int i = 0; i < n; i++) {
        v = ((ll)v*x + s[i]) % y;
    }

    cout << v << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO();
    int t = 1;
    cin >> t;
    // int c = 1;

    while (t--) {
        solve();
    }
}













