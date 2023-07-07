#include<iostream>
#include<vector>

using namespace std;

struct Item {
	int first;
	int occ;
};

Item hist_domain[100001];

int main() {
	int n;
	cin >> n;

	vector<int> b(n);

	for (int &e : b) cin >> e;

	int max = 0;
	int count = 0;
	for (int j = 0; j < n; j++) {
		int i = b[j];
		if (max < i) max = i;
		if (hist_domain[i].occ == 0) {
			hist_domain[i].occ = 1;
			hist_domain[i].first = j;
			count++;
		}
		else if (hist_domain[i].occ == 1) {
			hist_domain[i].occ = 2;
			hist_domain[i].first = j - hist_domain[i].first;
		} else {
			if (hist_domain[i].occ > 0) {
				if  (b[(j - hist_domain[i].first)] != i) {
					hist_domain[i].occ = -1;
					count--;
				} else {
					hist_domain[i].occ++;
				}
			}
		}
	}

	int j = 0;
	cout << count << '\n';
	for (Item i : hist_domain) {
		if (i.occ > 0) {
			cout << j << ' ' << ((i.occ > 1) ? i.first : 0) << '\n';
		}
		if (++j > max) { break; } 
	}
}
