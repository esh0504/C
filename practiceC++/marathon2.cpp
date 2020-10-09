#include <iostream>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	multiset<string> s;

	//set에는 binary tree 로 저장 된다.
	for (auto it = completion.begin(); it != completion.end(); it++) {
		s.insert(*it);
	}

	for (auto it = participant.begin(); it != participant.end(); it++) {
		answer = *it;

		//로그2의N 번 찾음 (binary tree이기 때문에)
		auto found = s.find(answer);
		
		if (found == s.end()) {
			break;
		}

		//동명이인을 걸러내기 위해서
		else {
			s.erase(found);
		}
	}
	return answer;
}