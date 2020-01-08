#ifndef IPRINTABLE_H
#define IPRINTABLE_H
#include <iostream>

class IPrintable
{
public:

	virtual ~IPrintable() {};
	virtual void output(const IPrintable&) = 0;
	virtual void input(IPrintable&) = 0;
};

#endif // !IPrintable
