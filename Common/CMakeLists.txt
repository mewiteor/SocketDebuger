include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/Headers"
	"${CMAKE_CURRENT_BINARY_DIR}"
)

configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/Headers/Config.h.cmakein"
	"${CMAKE_CURRENT_BINARY_DIR}/Config.h"
)

set(Headers
	"${CMAKE_CURRENT_BINARY_DIR}/Config.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Headers/Types.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Headers/ISocket.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Headers/Socket.h"
)

set(Sources
	"${CMAKE_CURRENT_SOURCE_DIR}/Sources/ISocket.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/Sources/Types.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/Sources/Socket.cpp"
)

if(${NEEDED17})
	if(WIN32)
		add_compile_options("/std:c++latest")
	elseif(UNIX)
		add_compile_options("-std=c++1z")
	endif()
endif()

add_library(SocketCommon SHARED ${Sources} ${Headers})

target_link_libraries(SocketCommon PRIVATE Ws2_32.lib)

