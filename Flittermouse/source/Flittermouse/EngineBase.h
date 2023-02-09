#pragma once

#ifdef FM_PLATFORM_WINDOWS
	#ifdef FM_BUILD_DLL
		#define FM_PUBLIC_API __declspec(dllexport)
	#else
		#define FM_PUBLIC_API __declspec(dllimport)
	#endif
//#else
//	#error Unsupported platform
#endif
