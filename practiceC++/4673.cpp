#include <stdio.h>
int ill(int num) {
	return int(num % 10);
}

int sib(int num) {
	return int(num / 10);
}

int back(int num) {
	return int(num / 100);
}

int chun(int num) {
	return int(num / 1000);
}

int producer(int num) {
	if (num >= 1000) {
		return num + chun(num) + back(num) + sib(num) + ill(num);
	}
	else if (num >= 100) {
		return num + back(num) + sib(num) + ill(num);
	}
	else if (num >= 10) {
		return num + sib(num) + ill(num);
	}
	else {
		return num + ill(num);
	}
}

int main(void) {

}