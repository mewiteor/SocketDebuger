# include(CheckCXXSourceCompiles)
include(CheckIncludeFileCXX)

if(WIN32)
	set(IS_WINDOWS 1)
endif()

if(UNIX)
	set(IS_UNIX 1)
endif()

macro(check_needed_header header varname)
	check_include_file_cxx(${header} ${varname})
	
	if(NOT ${varname})
		if(DEFINED NEEDED_HEADER)
			set(NEEDED_HEADER "${header}")
		else()
			set(NEEDED_HEADER ", ${header}")
		endif()
	endif()
endmacro()

set(NEEDED17 OFF)

check_needed_header("cstdint" IS_HAVE_CSTDINT)
check_needed_header("string" IS_HAVE_STRING)
if(WIN32)
	check_include_file_cxx("string_view" IS_HAVE_STRING_VIEW "/std:c++latest")
	if(NOT NEEDED17)
		set(NEEDED17 ON)
	endif()
elseif(UNIX)
	check_include_file_cxx("string_view" IS_HAVE_STRING_VIEW "-std=c++1z")
	if(NOT NEEDED17)
		set(NEEDED17 ON)
	endif()
endif()

if(WIN32)
	check_needed_header("windows.h" IS_HAVE_WINDOWS_H)
	check_needed_header("winsock2.h" IS_HAVE_WINSOCK2_H)
elseif(UNIX)
endif()

if(DEFINED NEEDED_HEADER)
	message(FATAL_ERROR "need header: ${NEEDED_HEADER}")
endif()