#ifndef __TUM3D_CUDACOMPRESS__GLOBAL_H__
#define __TUM3D_CUDACOMPRESS__GLOBAL_H__


namespace cudaCompress {

typedef unsigned char byte;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef long long int int64;
typedef unsigned long long int uint64;

}


#if defined(CUCOMP_BUILD_STANDALONE)
	#define CUCOMP_DLL
#elif defined(CUCOMP_BUILD_DLL)
	#if defined _WIN32 || defined __CYGWIN__
		#ifdef __GNUC__
			#define CUCOMP_DLL __attribute__ ((dllexport))
		#else
			#define CUCOMP_DLL __declspec(dllexport)
		#endif
	#else
		#if __GNUC__ >= 4
			#define CUCOMP_DLL __attribute__ ((visibility("default")))
		#else
			#define CUCOMP_DLL
		#endif
	#endif
#else
	#if defined _WIN32 || defined __CYGWIN__
		#ifdef __GNUC__
			#define CUCOMP_DLL __attribute__ ((dllimport))
		#else
			#define CUCOMP_DLL __declspec(dllimport)
		#endif
	#else
		// Not sure if this is needed or not, better be safe and put it in just in case.
		#if __GNUC__ >= 4
			#define CUCOMP_DLL __attribute__ ((visibility("default")))
		#else
			#define CUCOMP_DLL
		#endif
	#endif
#endif


#endif
