#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vii tps;

int ans;
void solve(int b, int s) {
	if (n < b) {
		return;
	}

	if (b <= n) {
		if (ans < s) {
			ans = s;
		}

		if (n == b) {
			return;
		}
	}

	solve(b + 1, s);
	solve(b + tps[b].first, s + tps[b].second);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	tps = vii(n);
	for (auto&& [t, p] : tps) {
		cin >> t >> p;
	}

	ans = 0;
	solve(0, 0);
	cout << ans;

	return 0;
}