#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

template <class Iter>
void uniuqeWord(Iter begin, Iter end)
{
	unordered_set<string> unique;
	copy(begin, end, inserter(unique, unique.begin()));
	for (const auto &w : unique)
	{
		cout << w << "\t";
	}
	cout << endl;
}

int main()
{
	vector<string> words =
	{   "so", "close", "no", "matter", "how", "far", "couldn't", "be", "much", "more", "from", "the", "heart", "forever",
		"trusting", "who", "we", "are", "and", "nothing", "else", "matters", "never", "opened", "myself", "this", "way",
		"life", "is", "ours", "we", "live", "it", "our", "way", "all", "these" "words", "i", "don't", "just", "say", "and",
		"nothing", "else", "matters"
	};
	uniuqeWord(words.begin(), words.end());
	return 0;
}