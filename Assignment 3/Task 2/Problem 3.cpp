#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isInDictionary(string);

bool solve(string curr, const string& end, set<string>& vis, vector<string>& res) {
	vis.insert(curr);
	for (int i = 0; i < curr.length(); i++) {
		if (curr[i] == end[i]) continue;
		char orig = curr[i];
		for (char ch = 'a'; ch <= 'z'; ch++) {
			curr[i] = ch;
			if (curr == end) return true;
			if (isInDictionary(curr) && vis.find(curr) == vis.end()){
				if (solve(curr, end, vis, res)) {
					res.push_back(curr);
					return true;
				}
			}
			
		}
		curr[i] = orig;
	}
	return false;
}

vector<string> Ladder(const string& start, const string& end) {
	set<string> vis;
	vector<string> res;
	solve(start, end, vis, res);
	reverse(res.begin(), res.end());
	return res;
	
}
string dict[87315];
int sz = 0;
bool isInDictionary(string word) {
	return binary_search(dict, dict + sz, word);
}

void readFromFile() {
	ifstream in("words.txt");
	for(int i = 0; i < 87314; i++)
		in >> dict[sz++];
	in.close();

}

int main() {
	readFromFile();
	vector<string> res = Ladder("yeah", "nope");
	for (string i : res)
		cout << i << "\n";

}
