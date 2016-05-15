#ifndef __MY_NONCOPYABLE_H__
#define __MY_NONCOPYABLE_H__
namespace wd
{
class Noncopyable
{
protected:
	Noncopyable(){}
private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable & operator=(const Noncopyable & rhs);
};
}
#endif
