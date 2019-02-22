// exc_mean.h  -- hmean(), gmean()을 위한 예외 클래스
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
    bad_gmean(const std::string& s = "gmean() 매개변수는 >= 이어야 합니다.\n") 
		: logic_error(s) {}
};
