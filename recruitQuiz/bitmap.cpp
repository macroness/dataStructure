#include <iostream>
#include <map>
#include <vector>
#include <string>

#define BITMAP_HEIGHT 7
#define BITMAP_WIDTH 6

using namespace std;
static map<char, vector<vector<bool>>> bitmap =
{
{'A',
{{0,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,1,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
}},

{'B',
{{1,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,1,1,0}
} },

{'C',
{{0,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,0,0,1,1}
,{0,1,1,1,1,0}
} },

{'D',
{{1,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,1,1,0}
}},

{'E',
{{0,1,1,1,1,1}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,1,1,1,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{0,1,1,1,1,1}
}},

{'F',
{{1,1,1,1,1,1}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,1,1,1,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
}},

{'G',
{{0,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,0,0}
,{1,1,0,1,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{0,1,1,1,1,0}
}},

{'H',
{{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,1,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
}},

{'I',
{{0,1,1,1,1,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,1,1,1,1,0}
}},

{'J',
{{0,0,0,1,1,0}
,{0,0,0,1,1,0}
,{0,0,0,1,1,0}
,{0,0,0,1,1,0}
,{0,0,0,1,1,0}
,{1,1,0,1,1,0}
,{0,1,1,1,0,0}
}},

{'K',
{{1,1,0,0,1,1}
,{1,1,0,1,1,0}
,{1,1,1,1,0,0}
,{1,1,1,0,0,0}
,{1,1,1,1,0,0}
,{1,1,0,1,1,0}
,{1,1,0,0,1,1}
}},

{'L',
{{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,1,1,1,1}
}},

{'M',
{{1,1,0,0,1,1}
,{1,1,1,1,1,1}
,{1,1,1,1,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
}},

{'N',
{{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,0,1,1}
,{1,1,0,1,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
}},

{'O',
{{0,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{0,1,1,1,1,0}
}},

{'P',
{{1,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,1,1,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
,{1,1,0,0,0,0}
}},

{'Q',
{{0,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,1,1,1}
,{0,1,1,1,1,0}
,{0,0,0,0,1,1}
}},

{'R',
{{1,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,1,1,0}
,{1,1,1,1,0,0}
,{1,1,0,1,1,0}
,{1,1,0,0,1,1}
}},

{'S',
{{0,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,0,0}
,{0,1,1,1,1,0}
,{0,0,0,0,1,1}
,{1,1,0,0,1,1}
,{0,1,1,1,1,0}
}},

{'T',
{{1,1,1,1,1,1}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
}},

{'U',
{{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{0,1,1,1,1,0}
}},

{'V',
{{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{0,1,1,1,1,0}
,{0,0,1,1,0,0}
}},

{'W',
{{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,1,1,1,1}
,{1,1,1,1,1,1}
,{1,1,0,0,1,1}
}},

{'X',
{{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{0,1,1,1,1,0}
,{0,0,1,1,0,0}
,{0,1,1,1,1,0}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
}},

{'Y',
{{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{1,1,0,0,1,1}
,{0,1,1,1,1,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
,{0,0,1,1,0,0}
}},

{'Z',
{{1,1,1,1,1,1}
,{0,0,0,0,1,1}
,{0,0,0,1,1,0}
,{0,0,1,1,0,0}
,{0,1,1,0,0,0}
,{1,1,0,0,0,0}
,{1,1,1,1,1,1}
}},

{' ',
{{0,0,0,0,0,0}
,{0,0,0,0,0,0}
,{0,0,0,0,0,0}
,{0,0,0,0,0,0}
,{0,0,0,0,0,0}
,{0,0,0,0,0,0}
,{0,0,0,0,0,0}
}}
};

void printMulti(const char c, const int muti) {
	for (int m = 0; m < muti; m++) {
		cout << c;
	}
}

void printBitmapMark(const bool mark, const int multiple) {
	if (mark) {
		// �����ŭ �� �����
		printMulti('@', multiple);
	}
	else {
		printMulti(' ', multiple);
	}
}

void printAngle_0(const string& str, const int multipleW, const int multipleH) {
	const int strLen = str.length();

	int countMultiV = multipleH;
	for (int h = 0; h < BITMAP_HEIGHT;) {

		// �� ���ھ� Ȯ��
		for (int strNum = 0; strNum < strLen; strNum++) {

			// �� ������ �� �پ� ���
			for (int w = 0; w < BITMAP_WIDTH; w++) {
				printBitmapMark(bitmap[str[strNum]][h][w], multipleW);
			}

			// ���� �������ϸ� �� �ٲ�
			if (strNum == strLen - 1) {
				cout << "\n";
			}// �� ���� ������ ��ĭ ���
			else {
				cout << " ";
			}
		}

		// ���� �����ŭ �������� �� ��� ���� h�� �ø��� ����.
		if (countMultiV > 1) {
			countMultiV--;
		}
		// �����ŭ ����ٸ� �ٽ� �ʱ�ȭ�ϰ� h++
		else {
			countMultiV = multipleH;
			h++;
		}
	}
}

void printAngle_90(const string& str, const int multipleW, const int multipleH) {
	const int strLen = str.length();

	// �� ���ھ� Ȯ��
	for (int strNum = 0; strNum < strLen; strNum++) {
		int countMultiH = multipleW;
		for (int w = 0; w < BITMAP_WIDTH;) {
			// �� ������ �� �پ� ���
			for (int h = 1; h < BITMAP_HEIGHT + 1; h++) {
				printBitmapMark(bitmap[str[strNum]][BITMAP_HEIGHT - h][w], multipleH);
			}
			cout << "\n";
			// ���� �����ŭ �������� �� ��� ���� w�� �ø��� ����.
			if (countMultiH > 1) {
				countMultiH--;
			}
			// �����ŭ ����ٸ� �ٽ� �ʱ�ȭ�ϰ� w++
			else {
				countMultiH = multipleW;
				w++;
			}
		}

		cout << "\n";
	}
}

void printAngle_180(const string& str, const int multipleW, const int multipleH) {
	const int strLen = str.length();

	int countMultiV = multipleH;
	for (int h = 1; h < BITMAP_HEIGHT + 1;) {

		// �� ���ھ� Ȯ��
		for (int strNum = 1; strNum < strLen + 1; strNum++) {

			// �� ������ �� �پ� ���
			for (int w = 1; w < BITMAP_WIDTH + 1; w++) {
				printBitmapMark(bitmap[str[strLen - strNum]][BITMAP_HEIGHT - h][BITMAP_WIDTH - w], multipleW);
			}

			// ���� �������ϸ� �� �ٲ�
			if (strNum == strLen) {
				cout << "\n";
			}// �� ���� ������ ��ĭ ���
			else {
				cout << " ";
			}
		}

		// ���� �����ŭ �������� �� ��� ���� h�� �ø��� ����.
		if (countMultiV > 1) {
			countMultiV--;
		}
		// �����ŭ ����ٸ� �ٽ� �ʱ�ȭ�ϰ� h++
		else {
			countMultiV = multipleH;
			h++;
		}
	}
}

void printAngle_270(const string& str, const int multipleW, const int multipleH) {
	const int strLen = str.length();

	// �Ųٷ� �� ���ھ� Ȯ��
	for (int strNum = 1; strNum < strLen + 1; strNum++) {
		int countMultiH = multipleW;
		for (int w = 1; w < BITMAP_WIDTH + 1;) {
			// �� ������ �� �پ� ���
			for (int h = 0; h < BITMAP_HEIGHT; h++) {
				printBitmapMark(bitmap[str[strLen - strNum]][h][BITMAP_WIDTH - w], multipleH);
			}
			cout << "\n";
			// ���� �����ŭ �������� �� ��� ���� w�� �ø��� ����.
			if (countMultiH > 1) {
				countMultiH--;
			}
			// �����ŭ ����ٸ� �ٽ� �ʱ�ȭ�ϰ� w++
			else {
				countMultiH = multipleW;
				w++;
			}
		}

		cout << "\n";
	}
}

void printString(const string& str, const int angle, const int multipleW, const int multipleH) {

	switch (angle) {
	case 0:
		printAngle_0(str, multipleW, multipleH);
		break;
	case 90:
		printAngle_90(str, multipleW, multipleH);
		break;
	case 180:
		printAngle_180(str, multipleW, multipleH);
		break;
	case 270:
		printAngle_270(str, multipleW, multipleH);
		break;
	default:
		cout << "Wrong angle value!\n";
	}
}

bool stringValidationCheck(const string& str) {

	for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if ((*it < 'A' || 'Z' < *it) && (' ' != *it))
			return false;
	}

	return true;
}

bool angleValidationCheck(const int angle) {
	return angle == 0 || angle == 90 || angle == 180 || angle == 270;
}

bool mutiValidationCheck(const int multi) {
	return multi > 0;
}

void runApp(const string& str, const int angle, const int multipleW, const int multipleH) {

	if (!stringValidationCheck(str)) {
		cout << "A~Z ������ ���ĺ��� �־��ּ���.\n";
		return;
	}

	if (!angleValidationCheck(angle)) {
		cout << "��ȿ���� ���� ȸ�����Դϴ�.\n";
		return;
	}

	if (!mutiValidationCheck(multipleW) || !mutiValidationCheck(multipleH)) {
		cout << "��ȿ���� ���� ����Դϴ�.\n";
		return;
	}

	printString(str, angle, multipleW, multipleH);
}

int main() {
	runApp("VICTORY KOREA", 90, 2, 6);

	return 0;
}
	
