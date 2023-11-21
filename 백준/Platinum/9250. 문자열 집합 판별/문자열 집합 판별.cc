// https://www.acmicpc.net/problem/9250
// 분야 : 아호-코라식
// 후기 : KMP 공부할때에도 느꼈던 벽을 다시한번 느낄 수 있었습니다 ㅜㅜ

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;

//트라이 클래스 
class Trie {
public:
	Trie* trie[26]; // 알파벳 개수
	Trie* failure; // 실패함수
	bool isEnd; // 문자열 끝

	//생성자 초기화
	Trie() {
		fill(trie, trie + 26, nullptr);
		isEnd = false;
	}

	//소멸자 메모리 해제
	~Trie() {
		for (int i = 0; i < 26; ++i) {
			if (trie[i]) delete trie[i];
		}
	}

	//노드 삽입
	void insertNode(string& s, int idx) {
		if (idx == s.length()) {
			isEnd = true;
			return;
		}

		int iidx = s[idx] - 'a';

		if (!trie[iidx]) {
			trie[iidx] = new Trie();
		}

		trie[iidx]->insertNode(s, idx + 1);

	}
};

//실패 함수 만들기
inline void makeFailure(Trie* root) {
	
	//BFS 활용 
	queue<Trie*> q;
	root->failure = root; 
	q.push(root); // 처음에 root 삽입

	//q가 비어있기 전까지
	while (!q.empty()) {
		Trie* cur = q.front();

		q.pop();

		//모든 알파벳에 대해서 
		for (int i = 0; i < 26; ++i) {

			//다음노드는 현재노드의 다음노드(당연한말)
			Trie* nextN = cur->trie[i];

			//다음노드가 없으면 건너뛰기
			if (!nextN) continue;

			//현재노드가 루트이면 실패함수는 루트
			if (cur == root) nextN->failure = root;
			else {
				//실패함수가 가리켜야할 dest 포인터 선언
				Trie* dest = cur->failure;

				//KMP 구조 활용
				while (dest != root && !dest->trie[i]) {
					dest = dest->failure;
				}

				//실패함수의 다음노드가 있는경우
				if (dest->trie[i]) {
					dest = dest->trie[i];
				}

				//실패함수 위치 선정
				nextN->failure = dest;
			}
			
			//작은 문자열을 포함하는 경우
			if (nextN->failure->isEnd) nextN->isEnd = true;

			//다음 노드 큐에 넣기
			q.push(nextN);
		}
	}
}

int main() {

	fastio;

	Trie* root = new Trie();

	int N, M;
	cin >> N;

	//작은 문자열 트라이 만들기
	while (N--) {
		string s;
		cin >> s;

		root->insertNode(s, 0);
	}

	//실패 함수 만들기
	makeFailure(root);

	cin >> M;

	//긴 문자열에서 작은 문자열 포함여부 찾기
	while (M--) {
		
		bool flag = true;

		string s;
		cin >> s;

		Trie* cur = root;


		for (int i = 0; i < s.length(); ++i) {

			//실패함수 찾아 이동
			while (cur != root && !cur->trie[s[i] - 'a']) {
				cur = cur->failure;
			}

			//긴 문자열, 작은 문자열의 현재 글자가 같은 경우
			if (cur->trie[s[i] - 'a']) {
				cur = cur->trie[s[i] - 'a'];
				if (cur->isEnd) {
					flag = false;
					cout << "YES" << "\n";
					break;
				}
			} 
		}

		//못찾은 경우
		if (flag) cout << "NO" << "\n";
	}

	//메모리 할당 해제
	delete root;

	return EXIT_SUCCESS;
}