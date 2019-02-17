#pragma once
namespace SALES
{
    const int QUARTERS = 4;
    class Sales
    {
    private:
        double mSales[QUARTERS];
        double mAverage;
        double mMax;
        double mMin;
    public:
        Sales();
        Sales(const double ar[], int n);
        // ��ȭ�� ����:
        void SetSales();

        // s ����ü�� ��� �ִ� ��� ������ ����Ѵ�
        void ShowSales() const;
    };
}