#include"List.h"
#include"Queue.h"
#include"Stack.h"

int main()
{
	setlocale(LC_ALL, "");
	List<int> list1, list2;
	for (int i = 0; i < 5; i++)
	{
		list1.push_back(i + 1);
	}

	cout << list1 << endl;
	list2 = list1;
	cout << list2 << endl;

	list2.push_front(9);
	cout << list2 << endl;

	list2.remove(2);
	cout << list2 << endl;

	return 0;

}

