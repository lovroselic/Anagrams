// https://www.codeabbey.com/index/task_view/anagrams
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<map>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "0.1"

using namespace std;

string Compact(string str);
string Pack(vector<string>& cell);
map<string, int> MapDict(vector<string>& dictData);
void printMap(map<string, int> map);

int main() {
	cout << "Anagrams v" << VERSION << "!\n\n";
	string dict_path = "words2.txt";
	string path = "Test.txt";
	//string path = "Try.txt";
	vector<string> dict = loadData(dict_path);
	vector<string> raw_data = loadData(path);
	//printVector(dict);
	map <string, int> DICT = MapDict(dict);
	printMap(DICT);


	for (int i = 1; i < raw_data.size(); i++) {
		string C = Compact(raw_data[i]);
		//cout << raw_data[i] << " : " << C << endl;
	}
}

map<string, int> MapDict(vector<string>& dictData) {
	map<string, int> dict;
	for (const auto& str : dictData) {
		string packed = Compact(str);
		if (dict.count(packed) > 0) {
			dict[packed]++;
		}
		else {
			dict[packed] = 1;
		}
	}
	return dict;
}

void printMap(map<string, int> map) {
	for (const auto& el : map) {
		cout << el.first << "\t-> " << el.second << endl;
	}
};


string Compact(string str) {
	vector<string> S = splitString(str);
	sort(S.begin(), S.end());
	string packed = Pack(S);
	return packed;
}

string Pack(vector<string>& cell) {
	string compacted = "";
	string pchar = "";
	int count = 0;
	for (auto& c : cell) {
		if (c == pchar) {
			count++;
		}
		else {
			if (count > 0) {
				compacted += to_string(count);
				compacted += pchar;
			}
			pchar = c;
			count = 1;
		}
	}
	compacted += to_string(count);
	compacted += pchar;

	return compacted;
}
