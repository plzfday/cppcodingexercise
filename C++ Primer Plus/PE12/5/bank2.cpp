// bank2.cpp -- Queue 인터페이스를 사용한다
#include <iostream>
using namespace std;
#include <cstdlib>		// rand()와 srand()를 사용하기 위해
#include <ctime>		// time()을 사용하기 위해
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);	// 새 고객이 도착했는가?

int main()
{
    // 필요한 여러 가지를 준비한다
    srand(time(0));			// rand()의 무작위 초기화

    cout << "사례 연구: 히서 은행의 자동 지급기\n";
    cout << "큐의 최대 길이를 입력하십시오: ";
    int qs;
    cin >> qs;

    int hours;			// 시뮬레이션 시간 수
    while (1)
    {
        cout << "시뮬레이션 시간 수를 입력하십시오(>= 100): ";
        cin >> hours;
        if (hours >= 100)
            break;
    }
    // 시뮬레이션은 1분에 1주기를 실행한다
    long cyclelimit = MIN_PER_HR * hours;	// 시뮬레이션 주기 수

    double perhour;		// 시간당 평균 고객 수
    double min_per_cust; 	// 평균 고객 도착 간격(분 단위)
    double avg_wait_time = 0;	// 평균 대기 시간(분 단위)

    Item temp;			// 새 고객 데이터
    long turnaways;			// 큐가 가득 차서 발길을 돌린 고객 수
    long customers;			// 큐에 줄을 선 고객 수
    long served;			// 시뮬레이션에서 거래를 처리한 고객 수
    long sum_line;			// 큐의 누적 길이
    int wait_time;			// 자동 지급기가 빌 때까지 대기하는 시간
    long line_wait;			// 고객들이 줄을 서서 대기한 누적 시간

    for (perhour = 1; avg_wait_time < 1; perhour++)		// 평균 대기 시간이 1분 이상이 되면 루프를 탈출한다
    {
        Queue line(qs);		// line 큐에는 최대 qs명까지 대기할 수 있다

        min_per_cust = MIN_PER_HR / perhour;
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time = 0;
        line_wait = 0;

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))	// 새 고객이 도착했다
            {
                if (line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);		// cycle이 도착 시간이 된다
                    line.enqueue(temp); 	// 큐에 새 고객을 추가한다
                }
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp); 		// 다음 고객을 받는다
                wait_time = temp.ptime();	// wait_time을 설정한다
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }

        if (customers > 0)
        {
            cout << "-------------------------------\n";
            cout << "  시간당 평균 고객 수: " << (int)perhour << '\n';
            cout << " 큐에 줄을 선 고객 수: " << customers << '\n';
            cout << "거래를 처리한 고객 수: " << served << '\n';
            cout << "  발길을 돌린 고객 수: " << turnaways << '\n';
            cout << "       평균 큐의 길이: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout.setf(ios_base::showpoint);
            cout << (double)sum_line / cyclelimit << '\n';
            cout << "       평균 대기 시간: "
                << (double)line_wait / served << "분\n";
        }
        else
            cout << "고객이 한 명도 없습니다!\n";

        avg_wait_time = (double)line_wait / served;
    }

    cout << "\n" << "시간당 평균 고객 수가 " << (int)perhour - 1 << "명 이상이 되면,\n"
        << "평균 대기 시간이 1분을 초과하게 됩니다.\n";

    return 0;
}

//  x는 고객 간의 평균 시간 간격이다(분 단위)
//  이 시간 내에 고객이 도착하면 리턴값은 true이다
bool newcustomer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}