/*
 * D3D9API.H : Application Programming Interface For Direct3D9, Version 9.0c.
 *
 *  Created on: 23 sep. 2019
 *      Author: Martin Andreasson
 */

#ifndef HEADER_D3D9API_H_
#define HEADER_D3D9API_H_

#include "HARDFORM.H"

#include "D3D9ENUM.H" // enums
#include "D3D9TYPE.H" // types
#include "D3D9UTIL.H" // type utils
#include "D3D9PROT.H" // prototypes
#include "D3D9VTBL.H" // vtables
#include "D3D9COM.H"  // com objects

#define SI static HF_INLINE


//! This function is never used.
SI hresult_t d3d9_iunknown_query_interface(
	d3d9_iunknown_t    iunknown,
	d3d9_guid_t      * riid,
	void            ** ppvObj )
{
	return iunknown.vtbl->queryInterface( & iunknown, riid, ppvObj );
}

//! AddRef increments the reference count for an interface on an object.
//! This method should be called for every new copy of a pointer
//! to an interface on an object.
SI u32 d3d9_iunknown_add_ref( d3d9_iunknown_t iunknown )
{
	return iunknown.vtbl->addRef( & iunknown );
}

//! Release has to be called when finished using
//! the object to free its associated resources.
SI u32 d3d9_iunknown_release( d3d9_iunknown_t iunknown )
{
	return iunknown.vtbl->release( & iunknown );
}

//! GetContainerTexture provides access to the parent texture.
SI void d3d9_surface_get_container_texture(
	d3d9_surface_t         surface,
	d3d9_guid_t          * riid,
	d3d9_texture_t      ** dest )
{
	surface.vtbl->getContainer( & surface, riid, (void**) dest );
}

//! GetContainerCubeTexture provides access to the parent cube texture.
SI void d3d9_surface_get_container_cube_texture(
	d3d9_surface_t         surface,
	d3d9_guid_t          * riid,
	d3d9_cube_texture_t ** dest )
{
	surface.vtbl->getContainer( & surface, riid, (void**) dest );
}

//! Access the parent swap chain if this surface is a back buffer.
SI void d3d9_surface_get_container_swap_chain(
	d3d9_surface_t         surface,
	d3d9_guid_t          * riid,
	d3d9_cube_texture_t ** dest )
{
	surface.vtbl->getContainer( & surface, riid, (void**) dest );
}


#undef SI
#endif /* HEADER_D3D9API_H_ */


