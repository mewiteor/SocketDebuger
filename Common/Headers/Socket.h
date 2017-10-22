#ifndef _SOCKET_H_
#define _SOCKET_H_

#include "ISocket.h"

class Socket : public ISocket
{
public:
	Socket();
	~Socket();

	void open();
	void close();

private:
#if IS_WINDOWS
	WSADATA m_wsaData;
	bool m_initSuccess;

#endif
	SOCKET m_socket;
};

#endif // _SOCKET_H_
