/*
 * ---------------------------------------------------------------------------
 * D3D9LDR.H : Direct3D 9.0c loader with a clean C interface.
 * ---------------------------------------------------------------------------
 * Created on: 22 sep 2019
 * Updated on: 10 may 2020
 *     Author: Martin Andreasson
 *    Version: 1.0
 *    License: Mozilla Public License Version 2.0
 * ---------------------------------------------------------------------------
 * Usage:
 * 
 * #define D3D9LDR_IMPLEMENTATION
 * 
 * before including this file in *one* C or C++
 * file to create the implementation.
 * 
 *    // that may look like this
 *    #include ...
 *    #include ...
 *    #include ...
 *    #define D3D9LDR_IMPLEMENTATION
 *    #include "D3D9LDR.H"
 * 
 * You can, (if you want) before the #include, do any of the following:
 * - #define D3D9LDR_ASSERT(x) to avoid using assert.h
 * - #define D3D9LDR_MALLOC(x) to avoid malloc
 * - #define D3D9LDR_REALLOC to avoid realloc
 * - #define D3D9LDR_FREE(x) to avoid free
 * - #define D3D9LDR_MEMCPY(d,p,s) to avoid memcpy
 * - #define D3D9LDR_MEMSET(d,v,s) to avoid memset
 * - #define D3D9LDR_STRLEN(x) to avoid strlen
 * - #define D3D9LDR_LOGF(...) to use your printf instead of stderr fprintf
 * 
 * Std library function(s) will be used if one of the above is not defined.
 * 
 * Please note that at minimum, Windows 98 SE is required for Direct3D 9.0c.
 */
/*#########################################################################*/
#if defined(_MSC_VER) && (_MSC_VER >= 1020)                  /* MSVC GUARD */
#	pragma once
#endif                                                       /* MSVC GUARD */
/*#########################################################################*/
#ifndef HEADER_D3D9LDR_H_INCLUDED_
#define HEADER_D3D9LDR_H_INCLUDED_                /* STANDARD HEADER GUARD */
/*#########################################################################*/
// #define OVERRIDE_DYNALOAD_MALLOC to provide your own malloc

#include "HARDFORM.H" // compiler/platform wrangler

#include "D3D9ENUM.H" // enums
#include "D3D9TYPE.H" // types
#include "D3D9UTIL.H" // type utils
#include "D3D9PROT.H" // prototypes
#include "D3D9VTBL.H" // vtables
#include "D3D9COM.H"  // com objects
#include "D3D9API.H"  // api functions

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#define SI static HF_INLINE

//! The DLL function pointer table
typedef struct D3D9LDR_FUNCTIONS_T
{
	d3d9_t * ( * create )( void ); //!< Returns a Direct3D 9.0c Interface
}
d3d9ldr_functions_t;


/**
 * Wrapper for Direct3DCreate9 which returns a clean function interface.
 * 
 * @pre d3d9ldr_init() must've been called with @p api before calling
 * 
 * @param[in] api Instance
 * 
 * @return d3d9_t function table
 */
SI d3d9_t * d3d9_create( d3d9ldr_functions_t * api )
{
	return api->create();
}


/**
 * Loads the Direct3D 9.0c DLL and fills out function pointer table @p api
 * 
 * @remark This function uses reference counting so it's *NOT* threadsafe.
 * 
 * @param api Instance
 * 
 * @return whether successful
 */
hbool d3d9ldr_init( d3d9ldr_functions_t * api );


/**
 * Unloads the Direct3D 9.0c DLL
 * 
 * @remark This function uses reference counting so it's *NOT* threadsafe.
 * 
 * @param api Instance
 * 
 * @return whether successful
 */
hbool d3d9ldr_free( d3d9ldr_functions_t * api );


#undef SI
#ifdef __cplusplus
}
#endif //__cplusplus

/****************************************************************************
 *
 * IMPLEMENTATION
 *
 ****************************************************************************/
#ifdef D3D9LDR_IMPLEMENTATION

#include "DYNALOAD.H" // for loading the d3d9 dynamic library

#ifndef   D3D9LDR_MALLOC
#define   D3D9LDR_MALLOC( size ) malloc( size )
#ifndef   D3D9LDR_USES_STDLIB_H
#define   D3D9LDR_USES_STDLIB_H
#endif //!D3D9LDR_USES_STDLIB_H
#endif //!D3D9LDR_MALLOC

#ifndef   D3D9LDR_REALLOC
#define   D3D9LDR_REALLOC realloc
#ifndef   D3D9LDR_USES_STDLIB_H
#define   D3D9LDR_USES_STDLIB_H
#endif //!D3D9LDR_USES_STDLIB_H
#endif //!D3D9LDR_REALLOC

#ifndef   D3D9LDR_FREE
#define   D3D9LDR_FREE(x) free(x)
#ifndef   D3D9LDR_USES_STDLIB_H
#define   D3D9LDR_USES_STDLIB_H
#endif //!D3D9LDR_USES_STDLIB_H
#endif //!D3D9LDR_FREE

#ifndef   D3D9LDR_MEMCPY
#define   D3D9LDR_MEMCPY(d,p,s) memcpy(d,p,s)
#ifndef   D3D9LDR_USES_STDLIB_H
#define   D3D9LDR_USES_STDLIB_H
#endif //!D3D9LDR_USES_STDLIB_H
#endif //!D3D9LDR_MEMCPY

#ifndef   D3D9LDR_LOGF
#define   D3D9LDR_LOGF(...) do{fprintf( stderr, __VA_ARGS__ );}while(0)
#ifndef   D3D9LDR_USES_STDIO_H
#define   D3D9LDR_USES_STDIO_H
#endif //!D3D9LDR_USES_STDIO_H
#endif //!D3D9LDR_LOGF

#ifndef   D3D9LDR_MEMSET
#define   D3D9LDR_MEMSET(d,v,s) memset(d,v,s)
#ifndef   D3D9LDR_USES_STRING_H
#define   D3D9LDR_USES_STRING_H
#endif //!D3D9LDR_USES_STRING_H
#endif //!D3D9LDR_MEMSET

#ifndef   D3D9LDR_STRLEN
#define   D3D9LDR_STRLEN(x) strlen(x)
#ifndef   D3D9LDR_USES_STRING_H
#define   D3D9LDR_USES_STRING_H
#endif //!D3D9LDR_USES_STRING_H
#endif //!D3D9LDR_MEMSET

#ifdef D3D9LDR_USES_STDLIB_H
#include <stdlib.h>
#endif

#ifdef D3D9LDR_USES_STDIO_H
#include <stdio.h>
#endif

#ifdef D3D9LDR_USES_STRING_H
#include <string.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

//! FUNCTION SIGNATURE
typedef d3d9_t * ( __stdcall * d3d9_direct3dcreate9_t )( u32 );

//! FUNCTION POINTER
static d3d9_direct3dcreate9_t g_pfn_Direct3DCreate9;

//! returns a Direct3D 9.0c interface
static d3d9_t * wrapper_for_d3dcreate9( void )
{
	return g_pfn_Direct3DCreate9( D3D9_SDK_VERSION );
}

//! template of function pointers (const-ptr)
static const d3d9ldr_functions_t g_d3d9func =
{
	wrapper_for_d3dcreate9,
};

//! Basically a reference counter
static int g_loads = 0;

//! Instance of the dynamic library
static s_dynaload * g_d3d9 = nullp;

//! Loads the Direct3D 9.0c DLL
hbool d3d9ldr_init( d3d9ldr_functions_t * api )
{
	// Function Ptr Table
	D3D9LDR_MEMCPY( (void *) api, & g_d3d9func, sizeof(d3d9ldr_functions_t) );
	
	if ( g_loads == 0 )
	{
		// attempt to load the library first...
		g_d3d9 = dynaload_create( "d3d9.dll", 0 );
		
		// allocation of the dynaload instance may fail, though!
		if ( !g_d3d9 )
		{
			g_d3d9 = nullp;
			
			D3D9LDR_MEMSET( api, 0, sizeof( d3d9ldr_functions_t ) );
			
			return hf_false;
		}
		
		// if we're not loaded, we've failed!
		if ( !dynaload_is_loaded( g_d3d9 ) )
		{
			dynaload_destroy( g_d3d9 );
			
			g_d3d9 = nullp;
			
			D3D9LDR_MEMSET( api, 0, sizeof( d3d9ldr_functions_t ) );
			
			return hf_false;
		}
		else // we've loaded and may proceed
		{
			bool32 success = hf_false;
			
			g_pfn_Direct3DCreate9 =
				(d3d9_direct3dcreate9_t) dynaload_procload(
					g_d3d9,
					"Direct3DCreate9", & success );
			
			if ( !success )
			{
				dynaload_destroy( g_d3d9 );
				
				g_d3d9                = nullp;
				g_pfn_Direct3DCreate9 = nullp;
				
				D3D9LDR_MEMSET( api, 0, sizeof( d3d9ldr_functions_t ) );
				
				return hf_false;
			}
		}
	}
	
	g_loads++; // refcount +1
	
	return hf_true;
}

//! Unloads the Direct3D 9.0c DLL
hbool d3d9ldr_free( d3d9ldr_functions_t * api )
{
	if ( g_loads > 0 ) // got refs ?
	{
		g_loads--; // refcount -1
		
		if ( g_loads == 0 ) // unload ?
		{
			dynaload_destroy( g_d3d9 );
			
			g_d3d9                = nullp;
			g_pfn_Direct3DCreate9 = nullp;
			
			D3D9LDR_MEMSET( api, 0, sizeof( d3d9ldr_functions_t ) );
		}
	}
	
	return hf_true;
}

#ifdef __cplusplus
}
#endif //__cplusplus
#endif // D3D9LDR_IMPLEMENTATION
#endif // HEADER_D3D9LDR_H_INCLUDED_

