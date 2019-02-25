// queue.h -- 큐를 위한 인터페이스
#ifndef QUEUE_H_
#define QUEUE_H_
// 이 큐는 Customer 항목들을 포함하게 된다
class Customer
{
private:
    long arrive;        // 고객이 큐에 도착한 시간
    int processtime;    // 고객의 거래를 처리하는 시간
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

typedef Customer Item;
#endif
