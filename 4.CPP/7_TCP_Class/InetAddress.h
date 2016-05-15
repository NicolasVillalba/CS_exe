
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
class InetAddress
{
public
	InetAddress(unsigned short port);
	InetAddress(const string & ip, unsigned short port);

	string ip() const;
	unsigned short port() const;

	const struct sockaddr_in * getInetAddressPtr();
private:
	struct sockaddr_in_addr;

}
}
