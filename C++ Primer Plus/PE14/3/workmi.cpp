#include <iostream>
#include <cstring>
#include "workermi.hpp"
#include "queue.hpp"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Queue<Worker*> lolas(SIZE);

	int ct;
	for (ct = 0; ct < SIZE; ++ct)
	{
		char choice;
		cout << "������ �Է��Ͻʽÿ�:\n"
			<< "w: ������      s: ����      "
			<< "t: ���� �� ������      q: ����\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q �߿��� �ϳ��� �����Ͻʽÿ�: ";
			cin >> choice;
		}
		while (cin.get() != '\n');
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':
			{
				Waiter* tmpWaiter = new Waiter();
				tmpWaiter->Set();
				lolas.enqueue(tmpWaiter);
				break;
			}
		case 's':
			{
				Singer* tmpSinger = new Singer();
				tmpSinger->Set();
				lolas.enqueue(tmpSinger);
				break;
			}
		case 't':
			{
				SingingWaiter* tmpSingingWaiter = new SingingWaiter();
				tmpSingingWaiter->Set();
				lolas.enqueue(tmpSingingWaiter);
				break;
			}
		}
	}

	cout << "\n��� ��Ȳ�� ������ �����ϴ�:\n";
	int i;
	Worker* pi;
	for (i = 0; i < ct; ++i)
	{
		cout << endl;
		lolas.dequeue(pi);
		pi->Show();
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}