#include "Socket.h"

Socket::Socket()
	:m_initSuccess(false)
	,m_socket(INVALID_SOCKET)
{
	int result = WSAStartup(MAKEWORD(2, 2), &m_wsaData);

	if (result)
		ThrowC("WSAStartup", result);

	m_initSuccess = true;
}

Socket::~Socket()
{
	if (m_initSuccess)
	{
		WSACleanup();
		m_initSuccess = false;
	}
}