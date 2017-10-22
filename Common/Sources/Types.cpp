#include "Types.h"

Exception::Exception(const std::string_view & s)
	:message(s)
{

}

Exception::Exception(const std::string & s)
	:message(&s[0],s.size())
{

}

#if IS_WINDOWS

// Retrieve the system error message for the last-error code
Exception::Exception(
		HWND hParent,
		const char * fileName,
		size_t line,
		const char* parentFunction,
		const char* function,
		unsigned int code)
{
    // Retrieve the system error message for the last-error code
    char * msgBuf = nullptr;

    FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS|
        FORMAT_MESSAGE_MAX_WIDTH_MASK,
        nullptr,
        code,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (char*) &msgBuf,
        0, nullptr );

	if (msgBuf)
	{
		std::ostringstream oss;
		oss << "Filename:" << fileName << std::endl;
		oss << "Line:" << line << std::endl;
		oss << "Parent function:" << parentFunction << std::endl;
		oss << "Function:" << function << std::endl;
		oss << "Code:" << code << std::endl;
		oss << "Description:" << msgBuf << std::endl;
	}

    if(msgBuf)
        LocalFree(msgBuf);
}
#endif