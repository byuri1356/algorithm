#include<iostream>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using int64 = int64_t;

class Trie {
public:
	int cnt;
	Trie* ch[2];

	Trie() {
		cnt = 0;
		ch[0] = ch[1] = nullptr;
	}

	~Trie() {
		if (!ch[0]) delete ch[0];
		if (!ch[1]) delete ch[1];
	}

	void insert(int num, int idx) {
		cnt++;
		if (idx == -1) return;

		int iidx = num & (1 << idx);
		iidx = iidx ? 1 : 0;

		if (!ch[iidx]) ch[iidx] = new Trie();

		ch[iidx]->insert(num, idx - 1);
	}

	void del(int num, int idx) {
		cnt--;
		if (idx == -1) return;

		int iidx = num & (1 << idx);
		iidx = iidx ? 1 : 0;

		ch[iidx]->del(num, idx - 1); 
	}

	int find(int num, int idx, int sum) {
		if (idx == -1) return sum;

		int iidx = ~num & (1 << idx);
		iidx = iidx ? 1 : 0;

		if (ch[iidx] && ch[iidx]->cnt != 0) return ch[iidx]->find(num, idx - 1, sum + (1 << idx));

		else {
			iidx = (iidx + 1) % 2;
			return ch[iidx]->find(num, idx - 1, sum);
		}
	}
};

int main() {

	fastio;

	int N;
	cin >> N;

	Trie* root = new Trie();
	root->insert(0, 30);

	while (N--) {
		int q, a;
		cin >> q >> a;

		switch (q) {
		case 1:
			root->insert(a, 30);
			break;
		case 2:
			root->del(a, 30);
			break;
		default:
			cout << root->find(a, 30, 0) << "\n";
		}
	}

	return EXIT_SUCCESS;
}