// queue.h -- ť�� ���� �������̽�
#ifndef QUEUE_H_
#define QUEUE_H_
// �� ť�� Customer �׸���� �����ϰ� �ȴ�
class Customer
{
private:
    long arrive;        // ���� ť�� ������ �ð�
    int processtime;    // ���� �ŷ��� ó���ϴ� �ð�
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
