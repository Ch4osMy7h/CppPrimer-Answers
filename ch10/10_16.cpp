#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using std::vector; using std::string; using std::cout; using std::endl;

void elimDups(vector<string> &v) {
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void biggies(vector<string> &v, vector<string>::size_type sz) {
	elimDups(v);
	stable_sort(v.begin(), v.end(), isShorter);
	auto wc = find_if(v.begin(), v.end(),
		[sz](const string &s) {
			return s.size() >= sz;
		});
	std::for_each(wc, v.end(), [](const string &s) {cout << s << " ";});
	cout << endl;
}


int main() {
	vector<string> v = { "a", "aa", "aaaa", "aaaaaa", "bbbb", "aa", "bbbb" };
	biggies(v, 3);
	return 0;
}