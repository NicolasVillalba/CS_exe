 ///
 /// @file    Noncopyable.h
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#ifndef __MY_NONCOPYABLE_H__
#define __MY_NONCOPYABLE_H__

class Noncopyable
{
protected:
	Noncopyable();
private:
	Noncopyable(const Noncopyable & rhs);

	Noncopyable & operator = (const Noncopyable & rhs);
};
#endif
