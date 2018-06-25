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
		// 배수만큼 더 찍어줌
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

		// 한 글자씩 확인
		for (int strNum = 0; strNum < strLen; strNum++) {

			// 한 글자의 한 줄씩 출력
			for (int w = 0; w < BITMAP_WIDTH; w++) {
				printBitmapMark(bitmap[str[strNum]][h][w], multipleW);
			}

			// 글자 끝까지하면 줄 바꿈
			if (strNum == strLen - 1) {
				cout << "\n";
			}// 한 글자 끝나면 한칸 띄움
			else {
				cout << " ";
			}
		}

		// 수직 배수만큼 수직으로 더 찍기 위해 h를 올리지 않음.
		if (countMultiV > 1) {
			countMultiV--;
		}
		// 배수만큼 찍었다면 다시 초기화하고 h++
		else {
			countMultiV = multipleH;
			h++;
		}
	}
}

void printAngle_90(const string& str, const int multipleW, const int multipleH) {
	const int strLen = str.length();

	// 한 글자씩 확인
	for (int strNum = 0; strNum < strLen; strNum++) {
		int countMultiH = multipleW;
		for (int w = 0; w < BITMAP_WIDTH;) {
			// 한 글자의 한 줄씩 출력
			for (int h = 1; h < BITMAP_HEIGHT + 1; h++) {
				printBitmapMark(bitmap[str[strNum]][BITMAP_HEIGHT - h][w], multipleH);
			}
			cout << "\n";
			// 수평 배수만큼 수평으로 더 찍기 위해 w를 올리지 않음.
			if (countMultiH > 1) {
				countMultiH--;
			}
			// 배수만큼 찍었다면 다시 초기화하고 w++
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

		// 한 글자씩 확인
		for (int strNum = 1; strNum < strLen + 1; strNum++) {

			// 한 글자의 한 줄씩 출력
			for (int w = 1; w < BITMAP_WIDTH + 1; w++) {
				printBitmapMark(bitmap[str[strLen - strNum]][BITMAP_HEIGHT - h][BITMAP_WIDTH - w], multipleW);
			}

			// 글자 끝까지하면 줄 바꿈
			if (strNum == strLen) {
				cout << "\n";
			}// 한 글자 끝나면 한칸 띄움
			else {
				cout << " ";
			}
		}

		// 수직 배수만큼 수직으로 더 찍기 위해 h를 올리지 않음.
		if (countMultiV > 1) {
			countMultiV--;
		}
		// 배수만큼 찍었다면 다시 초기화하고 h++
		else {
			countMultiV = multipleH;
			h++;
		}
	}
}

void printAngle_270(const string& str, const int multipleW, const int multipleH) {
	const int strLen = str.length();

	// 거꾸로 한 글자씩 확인
	for (int strNum = 1; strNum < strLen + 1; strNum++) {
		int countMultiH = multipleW;
		for (int w = 1; w < BITMAP_WIDTH + 1;) {
			// 한 글자의 한 줄씩 출력
			for (int h = 0; h < BITMAP_HEIGHT; h++) {
				printBitmapMark(bitmap[str[strLen - strNum]][h][BITMAP_WIDTH - w], multipleH);
			}
			cout << "\n";
			// 수평 배수만큼 수평으로 더 찍기 위해 w를 올리지 않음.
			if (countMultiH > 1) {
				countMultiH--;
			}
			// 배수만큼 찍었다면 다시 초기화하고 w++
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
		cout << "A~Z 까지의 알파벳만 넣어주세요.\n";
		return;
	}

	if (!angleValidationCheck(angle)) {
		cout << "유효하지 않은 회전각입니다.\n";
		return;
	}

	if (!mutiValidationCheck(multipleW) || !mutiValidationCheck(multipleH)) {
		cout << "유효하지 않은 배수입니다.\n";
		return;
	}

	printString(str, angle, multipleW, multipleH);
}

int main() {
	runApp("VICTORY KOREA", 90, 2, 6);

	return 0;
}
	
