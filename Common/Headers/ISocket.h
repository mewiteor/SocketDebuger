#ifndef _ISOCKER_H_
#define _ISOCKER_H_


#include "Types.h"

class ISocket
{
public:
	virtual ~ISocket() = 0;
protected:
	virtual std::string GetSrcHost() = 0;
	virtual uint16_t GetSrcPort() = 0;
	virtual std::string GetDstHost() = 0;
	virtual uint16_t GetDstPort() = 0;
	virtual int GetDomainFamily() = 0;
	virtual int GetType() = 0;
	virtual int GetProtocol() = 0;
};

#endif // _ISOCKER_H_
