#include <queue>
#include <map>

#include "iHuffmanCoding.h"

using namespace std;

namespace istd {

iHuffmanCoding::iHuffmanCoding() {}

iHuffmanCoding::~iHuffmanCoding() {}

string iHuffmanCoding::doEncoding(const string str) {

	map<char, int> freqMap;

	// ºóµµ¼ö Ã¼Å©
	string::const_iterator it = str.begin();
	for (; it != str.end(); ++it) {
		map<char, int>::iterator mapItr = freqMap.find(*it);
		if (mapItr != freqMap.end()) {
			mapItr->second++;
		}
		else {
			freqMap[*it] = 1;
		}
	}

}


} // namespace istd