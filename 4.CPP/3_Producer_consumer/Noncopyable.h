#ifndef __MY_NONCOPYABLE_H__
#define __MY_NONCOPYABLE_H__

namespace wd
{
class Noncopyable
{
protected:
	Noncopyable(){}
private:
	Noncopyable(const Noncopyable & rhs);//cant copy
	Noncopyable & operator=(const Noncopyable & rhs);
};
}
#endif
