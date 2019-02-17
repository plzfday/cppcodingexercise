#ifndef GOLF_H_
#define GOLF_H_

class Golf
{
private:
    static const int LEN = 40;
    char mFullName[LEN];
    int mHandicap;
public:
    // ������
    Golf() { mFullName[0] = '\0', mHandicap = 0; }
    Golf(const char * name, int hc);

    // ��ȭ�� ����:
    // �� �Լ��� ����ڿ��� �̸��� �ڵ�ĸ�� ���´�
    // g�� ������� �Էµ� ������ �����Ѵ�
    // �̸��� �ԷµǸ� 1�� �����ϰ�, �̸��� �� ���ڿ��̸� 0�� �����Ѵ�
    int SetGolf();

    // �� �Լ��� handicap�� ���ο� ������ �����Ѵ�
    void Handicap(int hc);

    // �� �Լ��� golf ����ü�� ������ ����Ѵ�
    void ShowGolf() const;
};

#endif // !GOLF_H_
