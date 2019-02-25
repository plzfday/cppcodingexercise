#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
struct Review
{
	std::string title;
	int rating;
	int price;
};

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool priceWorseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
void ShowReview(const shared_ptr<Review>& rr);
bool FillReview(Review& rr);

int main()
{

	vector<shared_ptr<Review>> books;
	Review temp;
	while (FillReview(temp))
	{
		books.push_back(make_shared<Review>(temp));
	}
	if (books.size() > 0)
	{
		cout << "감사합니다. 당신은 다음과 같이 " << books.size() << "개의 책 등급을 입력하셨습니다.\n";
		cout.width(4);
		cout << "등급 ";
		cout.width(40);
		cout << "제목 ";
		cout.width(22);
		cout << "가격\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << "알파벳 순서\n";
		sort(books.begin(), books.end());
		for_each(books.begin(), books.end(), ShowReview);
		cout << "증가율 순서\n";
		sort(books.begin(), books.end(), worseThan);
		for_each(books.begin(), books.end(), ShowReview);
		cout << "감소율 순서\n";
		sort(books.rbegin(), books.rend(), worseThan);
		for_each(books.begin(), books.end(), ShowReview);
		cout << "가격 증가 순서\n";
		sort(books.begin(), books.end(), priceWorseThan);
		for_each(books.begin(), books.end(), ShowReview);
		cout << "가격 감소 순서\n";
		sort(books.rbegin(), books.rend(), priceWorseThan);
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "프로그램을 종료합니다.\n";
	return 0;
}

bool FillReview(Review & rr)
{
	std::cout << "책 제목을 입력하십시오(끝내려면 quit를 입력): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "책 등급(0-10)을 입력하십시오: ";
	std::cin >> rr.rating;
	std::cout << "책 가격을 입력하십시오: ";
	std::cin >> rr.price;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const shared_ptr<Review> & rr)
{
	cout.width(4);
	std::cout << rr->rating << " ";
	std::cout.width(50);
	std::cout << rr->title << " ";
	cout.width(10);
	std::cout << rr->price << std::endl;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool priceWorseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}