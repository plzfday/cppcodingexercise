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
		cout << "�����մϴ�. ����� ������ ���� " << books.size() << "���� å ����� �Է��ϼ̽��ϴ�.\n";
		cout.width(4);
		cout << "��� ";
		cout.width(40);
		cout << "���� ";
		cout.width(22);
		cout << "����\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << "���ĺ� ����\n";
		sort(books.begin(), books.end());
		for_each(books.begin(), books.end(), ShowReview);
		cout << "������ ����\n";
		sort(books.begin(), books.end(), worseThan);
		for_each(books.begin(), books.end(), ShowReview);
		cout << "������ ����\n";
		sort(books.rbegin(), books.rend(), worseThan);
		for_each(books.begin(), books.end(), ShowReview);
		cout << "���� ���� ����\n";
		sort(books.begin(), books.end(), priceWorseThan);
		for_each(books.begin(), books.end(), ShowReview);
		cout << "���� ���� ����\n";
		sort(books.rbegin(), books.rend(), priceWorseThan);
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

bool FillReview(Review & rr)
{
	std::cout << "å ������ �Է��Ͻʽÿ�(�������� quit�� �Է�): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "å ���(0-10)�� �Է��Ͻʽÿ�: ";
	std::cin >> rr.rating;
	std::cout << "å ������ �Է��Ͻʽÿ�: ";
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