#ifndef _TYPES_H_
#define _TYPES_H_
#define _HAS_CXX17 1

#include "Config.h"

#if IS_HAVE_CSTDINT

#include <cstdint>

#else

#endif

#include <string>
#include <sstream>

#if IS_HAVE_STRING_VIEW
#include <string_view>
#else
namespace std
{
	typedef string string_view;
}
#endif

#if IS_WINDOWS

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>

#endif

#if IS_UNIX

typedef int SOCKET;
enum
{
	INVALID_SOCKET = -1;
};
#endif

class Exception
{
public:
	Exception() {}
	Exception(const std::string_view & s);
	Exception(const std::string & s);
#if IS_WINDOWS
	Exception(
		HWND hParent,
		const char * fileName,
		size_t line,
		const char* parentFunction,
		const char* function,
		unsigned int code);
#endif
	const std::string_view & what() const { return message; }
private:
	std::string_view message;
};

#if IS_WINDOWS
#	define ThrowHC(func,hwnd,code) throw Exception(hwnd, __FILE__, __LINE__, __FUNCDNAME__, func, code)
#	define ThrowC(func,code) ThrowHC(func,nullptr,code)
#	define ThrowHCX(func,hwnd,xcode) ({ \
		DWORD code = xcode; \
		if (code) \
			throw Exception(hwnd, __FILE__, __LINE__, __FUNCDNAME__, func, code); \
	})
#	define ThrowCX(func,xcode) ThrowHCX(func,nullptr,xcode)
#	define ThrowH(func,hwnd) ThrowHCX(func,hwnd,GetLastError()) 
#	define Throw(func) ThrowH(func,nullptr)
#elif IS_UNIX
#endif

#endif // !_TYPES_H_
