// exc_mean.h  -- hmean(), gmean()�� ���� ���� Ŭ����
#include <iostream>
#include <string>
#include <stdexcept>

using std::logic_error;

class bad_hmean : public logic_error
{
public:
    bad_hmean(const std::string& s = "hmean function error: don't set a = -b") 
		: logic_error(s) {}
};

class bad_gmean : public logic_error
{
public:
    bad_gmean(const std::string& s = "gmean() �Ű������� >= �̾�� �մϴ�.\n") 
		: logic_error(s) {}
};
