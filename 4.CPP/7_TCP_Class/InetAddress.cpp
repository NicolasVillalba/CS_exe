 ///
 /// @file    InetAddress.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include "InetAddress.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/inet.h>
using std::cout;
using std::endl;


namespace wd
{
InetAddress::InetAddress(unsigned short port)
{
	memset(& addr, 0, sizeof(_addr));
	addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = INADDR_ANY;
}

InetAddress::InetAddress(const )
{
	memset(& addr, 0, sizeof(_addr));
	addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = INADDR_ANY;
}
}
