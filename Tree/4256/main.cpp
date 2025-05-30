#include<bits/stdc++.h>
#define MX 1001
using namespace std;

int N;
int preorder[MX], inorder[MX], pos[MX];

void postorder(int pLo, int pHi, int iLo, int iHi) {
	if (pLo > pHi) return;

	int root = preorder[pLo];
	int lSize = pos[root] - iLo;

	postorder(pLo + 1, pLo + lSize, iLo, pos[root] - 1);
	postorder(pLo + lSize + 1, pHi, pos[root] + 1, iHi);

	cout << root << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> preorder[i];
		for (int i = 0; i < N; i++) {
			cin >> inorder[i];
			pos[inorder[i]] = i;
		}

		postorder(0, N - 1, 0, N - 1);
		cout << '\n';
	}

	return 0;
}