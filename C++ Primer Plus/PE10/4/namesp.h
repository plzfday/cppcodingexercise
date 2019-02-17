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
        // 대화식 버전:
        void SetSales();

        // s 구조체에 들어 있는 모든 정보를 출력한다
        void ShowSales() const;
    };
}