/*
 * D3D9COM.H : COM Interface Classes For Direct3D9, Version 9.0c.
 *
 *  Created on: 23 sep. 2019
 *      Author: Martin Andreasson
 */

#ifndef HEADER_D3D9COM_H_
#define HEADER_D3D9COM_H_

#include "HARDFORM.H"

#include "D3D9ENUM.H" // enums
#include "D3D9TYPE.H" // types
#include "D3D9UTIL.H" // type utils
#include "D3D9PROT.H" // prototypes
#include "D3D9VTBL.H" // vtables


/**
 * The Windows COM Mechanism Base Class. Required by all Direct3D interfaces.
 */
typedef struct d3d9_iunknown_t
{
	d3d9_iunknown_vtbl_t * vtbl; //!< Pointer to IDirect3D VTable
}
d3d9_iunknown_t; //!< IDirect3D


/**
 * Microsoft's Direct3D9 API. It can only be used on Windows or with Wine.
 * 
 * When running Direct3D9 application you need to have d3d9.dll installed,
 * which fortunately has been deployed with all Windows versions since XP.
 * 
 * Direct3D 9.0c is available from as early as Windows 98 Second Edition.
 */
typedef struct d3d9_t
{
	d3d9_idirect3d_vtbl_t * vtbl; //!< Pointer to IDirect3D VTable
}
d3d9_t; //!< IDirect3D


/**
 * d3d9_device_t: Device.
 * 
 * Device is used to perform DrawPrimitive-based rendering,
 * create resources, work w/ system-level variables, adjust
 * gamma ramp levels, work with palettes and create shaders.
 */
typedef struct d3d9_device_t
{
	d3d9_device_vtbl_t * vtbl; //!< Pointer to IDirect3DDevice9 VTable
}
d3d9_device_t; //!< IDirect3DDevice9


//! d3d9_state_block_t used to encapsulate render states.
typedef struct d3d9_state_block_t
{
	d3d9_state_block_vtbl_t * vtbl; //!< Ptr to IDirect3DStateBlock9 VTable
}
d3d9_state_block_t; //!< IDirect3DStateBlock9


//! d3d9_swapchain_t used to manipulate the swap chain.
typedef struct d3d9_swapchain_t
{
	d3d9_swapchain_vtbl_t * vtbl; //!< Pointer to IDirect3DSwapChain9 VTable
}
d3d9_swapchain_t; //!< IDirect3DSwapChain9


//! d3d9_resource_t used to query and prepare resources.
typedef struct d3d9_resource_t
{
	d3d9_resource_vtbl_t * vtbl; //!< Pointer to IDirect3DResource9 VTable
}
d3d9_resource_t; //!< IDirect3DResource9


//! d3d9_vertex_declaration_t used to encapsulate a vertex shader declaration.
typedef struct d3d9_vertex_declaration_t
{
	d3d9_vertex_declaration_vtbl_t * vtbl; //!< IDirect3DVertexDeclaration9
}
d3d9_vertex_declaration_t; //!< IDirect3DVertexDeclaration9


//! d3d9_vertex_shader_t used to manipulate vertex shader resources.
//! d3d9_vertex_shader_t encapsulates the functionality of a vertex shader.
typedef struct d3d9_vertex_shader_t
{
	d3d9_vertex_shader_vtbl_t * vtbl; //!< IDirect3DVertexShader9 VTable
}
d3d9_vertex_shader_t; //!< IDirect3DVertexShader9


//! d3d9_pixel_shader_t used to manipulate pixel shader resources.
typedef struct d3d9_pixel_shader_t
{
	d3d9_pixel_shader_vtbl_t * vtbl; //!< Ptr to IDirect3DPixelShader9 VTable
}
d3d9_pixel_shader_t; //!< IDirect3DPixelShader9


//! d3d9_base_texture_t methods are used to manipulate
//! texture resources including cube & volume textures.
typedef struct d3d9_base_texture_t
{
	d3d9_base_texture_vtbl_t * vtbl; //!< Ptr to IDirect3DBaseTexture9 VTable
}
d3d9_base_texture_t; //!< IDirect3DBaseTexture9


//! d3d9_texture_t used to manipulate texture resources.
typedef struct d3d9_texture_t
{
	d3d9_texture_vtbl_t * vtbl; //!< Pointer to IDirect3DTexture9 VTable
}
d3d9_texture_t; //!< IDirect3DTexture9


//! d3d9_volume_texture_t used to manipulate volume texture resources.
typedef struct d3d9_volume_texture_t
{
	d3d9_volume_texture_vtbl_t * vtbl; //!< IDirect3DVolumeTexture9 VTable
}
d3d9_volume_texture_t; //!< IDirect3DVolumeTexture9


//! d3d9_cube_texture_t used to manipulate cube texture resources.
typedef struct d3d9_cube_texture_t
{
	d3d9_cube_texture_vtbl_t * vtbl; //!< Ptr to IDirect3DCubeTexture9 VTable
}
d3d9_cube_texture_t; //!< IDirect3DCubeTexture9


//! d3d9_vertex_buffer_t used to manipulate vertex buffer resources.
typedef struct d3d9_vertex_buffer_t
{
	d3d9_vertex_buffer_vtbl_t * vtbl; //!< IDirect3DVertexBuffer9 VTable
}
d3d9_vertex_buffer_t; //!< IDirect3DVertexBuffer9


//! d3d9_index_buffer_t used to manipulate index buffer resources.
typedef struct d3d9_index_buffer_t
{
	d3d9_index_buffer_vtbl_t * vtbl; //!< Ptr to IDirect3DIndexBuffer9 VTable
}
d3d9_index_buffer_t; //!< IDirect3DIndexBuffer9


//! d3d9_surface_t used to query and prepare surfaces.
typedef struct d3d9_surface_t
{
	d3d9_surface_vtbl_t * vtbl; //!< Pointer to IDirect3DSurface9 VTable
}
d3d9_surface_t; //!< IDirect3DSurface9


//! d3d9_volume_t used to manipulate volume resources.
typedef struct d3d9_volume_t
{
	d3d9_volume_vtbl_t * vtbl; //!< Pointer to IDirect3DVolume9 VTable
}
d3d9_volume_t; //!< IDirect3DVolume9


//! d3d9_query_t used to perform asynchronous queries on a driver.
typedef struct d3d9_query_t
{
	d3d9_query_vtbl_t * vtbl; //!< Pointer to IDirect3DQuery9 VTable
}
d3d9_query_t; //!< IDirect3DQuery9
 

#endif /* HEADER_D3D9COM_H_ */


