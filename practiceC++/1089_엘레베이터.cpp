#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	int n;
	long long sum = 0;
	cin >> n;
	vector <vector<int>> availableNum;
	vector<string> elevator;

	//�Է� �ޱ�
	for (int i = 0; i < 5; i++) {
		string word = "";
		cin >> word;
		elevator.push_back(word);
	}
	
	//�� �� �ִ� ���ڵ��� �迭�� ���� ex)[[0,8][8,9]]
	for (int i = 0; i < n; i++) {
		int num[10] = { 0 };
		if (elevator[0][4 * i] == '#') {
			num[1] = 10;
		}if (elevator[0][4 * i + 1] == '#') {
			num[1] = num[4] = 10;
		}if (elevator[1][4 * i] == '#') {
			num[1] = num[2] = num[3] = num[7] = 10;
		}if (elevator[1][4 * i + 2] == '#') {
			num[5] = num[6] = 10;
		}if (elevator[2][4 * i] == '#') {
			num[1] = num[7] = 10;
		}if (elevator[2][4 * i + 1] == '#') {
			num[0] = num[1] = num[7] = 10;
		}if (elevator[3][i * 4] == '#') {
			num[1] = num[2] = num[3] = num[4] = num[5] = num[7] = num[9] = 10;
		}if (elevator[3][i * 4 + 2] == '#') {
			num[2] = 10;
		}if (elevator[4][i * 4] == '#') {
			num[1] = num[4] = num[7] = 10;
		}if (elevator[4][i * 4 + 1] == '#') {
			num[1] = num[4] = num[7] = 10;
		}
		int a=pow(10, n - i - 1);
		vector<int> popo;
		for (int j = 0; j < 10; j++) {
			if (num[j] == 0) {
				popo.push_back(j);
			}
		}
		availableNum.push_back(popo);
	}

	//��ü ������ ������ ������ ����
	double mul = 1;
	for (int i = 0; i < n; i++) {
		mul *= availableNum[i].size();
	}

	// ������ ���ڿ� (��ü ������ ������ ����/���� �ڸ����� ����)��ŭ ����
	long long result = 0;
	for (int i = 0; i < n; i++) {
		int div = mul / availableNum[i].size();
		if (div == 0) {
			result = 1;
			mul = -1;
			break;
		}
		int po = pow(10, n - i-1);
		for (int j = 0;j< availableNum[i].size(); j++) {
			result+=availableNum[i][j] * div*po;
		}
	}
	
	//���� ���� ������ ������ ������ŭ ����
	cout.precision(6);
	cout << result / double(mul) << endl;
	
	return 0;
}