#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class dmaABC
{
private:
	char* label;
	int rating;
protected:
	virtual void print(std::ostream& os) const = 0;
public:
	dmaABC(const char* l = "null", int r = 0);
	dmaABC(const dmaABC& rs);
	virtual ~dmaABC();
	virtual void View() const = 0;
	virtual dmaABC& operator=(const dmaABC& rs);
	friend std::ostream& operator<<(std::ostream& os, const dmaABC& rs);
};

class baseDMA : public dmaABC
{
protected:
	virtual void print(std::ostream& os) const;
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	virtual void View() const;
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

class lacksDMA : public dmaABC
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
protected:
	virtual void print(std::ostream& os) const;
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	~lacksDMA() { }
	virtual void View() const;
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};

class hasDMA : public dmaABC
{
private:
	char* style;
protected:
	virtual void print(std::ostream& os) const;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	virtual void View() const;
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};

#endif // !DMA_H_
