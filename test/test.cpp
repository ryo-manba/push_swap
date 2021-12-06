#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
**	< 3 and 5 all tests >
**	1 g++ test.cpp
**	2 ./a.out > all.sh
**	3 chmod 755 all.sh
**	4 ./all.sh
*/

void	put_result(const vector<int> &a)
{
	cout << "./push_swap ";
	for_each(a.begin(), a.end(), [](int x)
	{
		cout << x << " ";
	});
	cout << "| ./checker ";
	for_each(a.begin(), a.end(), [](int x)
	{
		cout << x << " ";
	});
	cout << endl;
}

void	put_actions(const vector<int> &a)
{
	cout << "./push_swap ";
	for_each(a.begin(), a.end(), [](int x)
	{
		cout << x << " ";
	});
	cout << "| wc -l" << endl;
}

int	main()
{
	vector<int> three = {1, 2, 3};
	vector<int> five = {1, 2, 3, 4, 5};
	cout << "echo =======three=======" << endl;
	do {
		put_result(three);
	} while (next_permutation(three.begin(), three.end()));

	cout << endl << "echo =======five=======" << endl;
	do {
		put_result(five);
	} while (next_permutation(five.begin(), five.end()));
	cout << endl;
	cout << "echo =======three=======" << endl;
	do {
		put_actions(three);
	} while (next_permutation(three.begin(), three.end()));

	cout << endl << "echo =======five=======" << endl;
	do {
		put_actions(five);
	} while (next_permutation(five.begin(), five.end()));
}