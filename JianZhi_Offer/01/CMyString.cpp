 ///
 /// @file    CMyString.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class CMyString
{
public:
	CMyString(const char * pData = NULL);
	CMyString(const CMyString& str);
	CMyString & operator=(const CMyString& pstr);
	~CMyString(void);
private:
	char *m_pData;
};


CMyString::CMyString(const char * pData)
{
	if(pData != NULL)
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}else
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
}

CMyString::~CMyString()
{
	delete [] m_pData;
}

CMyString::CMyString(const CMyString& str)
{
	if(str.m_pData == NULL)
		m_pData = NULL;
	else
	{
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
	}
}


CMyString & CMyString::operator=(const CMyString& pstr)
{
	if(this == &pstr)//易错点
		return *this;
	if(m_pData != NULL)
	{
		delete [] m_pData;
		m_pData = NULL;
	}

	m_pData = new char[strlen(pstr.m_pData) + 1];
	strcpy(m_pData, pstr.m_pData);
	return *this;
}

int main()
{
	CMyString s1("222");
	CMyString s2;
	s2 = s1;
	return 0;
}
