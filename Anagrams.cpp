// https://www.codeabbey.com/index/task_view/anagrams
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

map<string, int> MapDict(vector<string>& dictData);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Anagrams v" << VERSION << "!\n\n";
	string dict_path = "words.txt";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> dict = loadData(dict_path);
	vector<string> raw_data = loadData(path);
	//printVector(dict);
	map <string, int> DICT = MapDict(dict);
	//printMap(DICT);

	vector<int> solution;
	for (int i = 1; i < raw_data.size(); i++) {
		string C = Compact(raw_data[i]);
		cout << raw_data[i] << " : " << DICT[C]-1 << endl;
		solution.push_back(DICT[C] - 1);
	}
	cout << "Solution: " << joinVector(solution, " ") << endl;;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
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