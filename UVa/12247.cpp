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

class DSU {
public:
	vector<int> root;
	vector<int> size;
	int cc;


	DSU(int n) {
		root = vector<int>(n);
		size = vector<int>(n, 1);
		iota(all(root), 0);
		cc = n;
	}

	int get(int x) { return root[x] == x ? x : x = get(root[x]);};

	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) { return;}

		if (size[x] > size[y]) swap(x, y);
		size[y] += size[x];
		root[x] = y;
		cc--;
	}

	bool sameSet(int x, int y) {
		return get(x) == get(y);
	}
};




bool solve() {
	
	vector<int> A(3);
	rep(i, 3) cin >> A[i];

	vector<int> B(2);
	rep(i, 2) cin >> B[i];

	if (A[0] == 0 and A[1] == 0 and A[2] == 0 and B[0] == 0 and B[1] == 0) return 0;

	set<int> used(all(A));
	for (auto b : B) used.insert(b);

	sort(all(A));
	sort(all(B));



	int turn = 2;
	int winA = 0;
	int winB = 0;
	while(turn--) {
		if (B.back() > A.back()) {
			A.erase(A.begin());
			B.pop_back();
		} else {
			int lb = lower_bound(all(A), (int) B.back()) - A.begin();
			A.erase(A.begin()+lb);
			B.pop_back();
			winA++;
		}
	}

	if (winA == 2) {
		cout << -1 << endl;
		return 1;;
	}

	for (int i = A.back() + 1; i <= 52; i++) {
		if (!used.count(i)) {
			cout << i << endl;
			return 1;
		}
	}

	cout << -1 << endl;
	return 1;


}

int main() {
	setIO(); 
	// setIO("circlecross"); 
	int t = 1;
	// cin >> t;
	bool f = 1;
	while (f) {
		f = solve();
	}
	

}		