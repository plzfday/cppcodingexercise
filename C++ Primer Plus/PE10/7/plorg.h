#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
    enum { STR_LEN = 20 };
    char mName[STR_LEN];
    int mCI;
public:
    Plorg(const char* str = "Plorga");
    void SetCI(int ci);
    void ShowPlorg() const;
};

#endif // !PLORG_H_
