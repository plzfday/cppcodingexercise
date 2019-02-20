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
		cout << "직종을 입력하십시오:\n"
			<< "w: 웨이터      s: 가수      "
			<< "t: 가수 겸 웨이터      q: 종료\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q 중에서 하나를 선택하십시오: ";
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

	cout << "\n사원 현황은 다음과 같습니다:\n";
	int i;
	Worker* pi;
	for (i = 0; i < ct; ++i)
	{
		cout << endl;
		lolas.dequeue(pi);
		pi->Show();
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}