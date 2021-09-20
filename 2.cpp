#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string text;
	string separators = ".!?";
	string temp;
	cout << "Введите текст для разделения на предложения (в конце предложения необходимо поставить один из 3 знаков (. ! ?): " << endl;
	getline(cin, text);
	multimap<size_t, string> splitting;
	for (auto iter = text.begin(); iter != text.end(); iter++)
	{
		auto sentence = find_first_of(iter, text.end(), separators.begin(), separators.end());
		if (sentence != text.end())
		{
			auto sentenceBegin = distance(text.begin(), iter);
			auto sentenceEnd = distance(text.begin(), sentence);
			temp = text.substr(sentenceBegin, sentenceEnd - sentenceBegin + 1);
			iter = sentence;
			if (temp[0] == ' ')
			{
				temp = temp.substr(1);
			}
			splitting.emplace(temp.size(), temp);
		}
	}
	cout << endl << "Предложения, отсортированные по длине" << endl;
	for (const auto &n : splitting)
	{
		cout << n.second << endl;
	}
	return 0;
}