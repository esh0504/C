#include <iostream>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	multiset<string> s;

	//set���� binary tree �� ���� �ȴ�.
	for (auto it = completion.begin(); it != completion.end(); it++) {
		s.insert(*it);
	}

	for (auto it = participant.begin(); it != participant.end(); it++) {
		answer = *it;

		//�α�2��N �� ã�� (binary tree�̱� ������)
		auto found = s.find(answer);
		
		if (found == s.end()) {
			break;
		}

		//���������� �ɷ����� ���ؼ�
		else {
			s.erase(found);
		}
	}
	return answer;
}