/*
 * D3D9PROT.H : Prototypes For Direct3D9, Version 9.0c.
 *
 *  Created on: 23 sep. 2019
 *      Author: Martin Andreasson
 */

#ifndef HEADER_D3D9PROT_H_
#define HEADER_D3D9PROT_H_

#include "ENGINE/SUPPORT/HARDFORM.H"

#include "ENGINE/DIRECT3D/D3D9ENUM.H" // enums
#include "ENGINE/DIRECT3D/D3D9TYPE.H" // types
#include "ENGINE/DIRECT3D/D3D9UTIL.H" // type utils

/*
typedef interface IDirect3D9Ex                   IDirect3D9Ex;
typedef interface IDirect3DDevice9Ex             IDirect3DDevice9Ex;
typedef interface IDirect3DSwapChain9Ex          IDirect3DSwapChain9Ex;
typedef interface IDirect3D9ExOverlayExtension   IDirect3D9ExOverlayExtension;
typedef interface IDirect3DDevice9Video          IDirect3DDevice9Video;
typedef interface IDirect3DAuthenticatedChannel9 IDirect3DAuthenticatedChannel9;
typedef interface IDirect3DCryptoSession9        IDirect3DCryptoSession9;
*/

typedef struct d3d9_iunknown_t             d3d9_iunknown_t            ;
typedef struct d3d9_t                      d3d9_t                     ;
typedef struct d3d9_device_t               d3d9_device_t              ;
typedef struct d3d9_state_block_t          d3d9_state_block_t         ;
typedef struct d3d9_swapchain_t            d3d9_swapchain_t           ;
typedef struct d3d9_resource_t             d3d9_resource_t            ;
typedef struct d3d9_vertex_declaration_t   d3d9_vertex_declaration_t  ;
typedef struct d3d9_vertex_shader_t        d3d9_vertex_shader_t       ;
typedef struct d3d9_pixel_shader_t         d3d9_pixel_shader_t        ;
typedef struct d3d9_base_texture_t         d3d9_base_texture_t        ;
typedef struct d3d9_texture_t              d3d9_texture_t             ;
typedef struct d3d9_volume_texture_t       d3d9_volume_texture_t      ;
typedef struct d3d9_cube_texture_t         d3d9_cube_texture_t        ;
typedef struct d3d9_vertex_buffer_t        d3d9_vertex_buffer_t       ;
typedef struct d3d9_index_buffer_t         d3d9_index_buffer_t        ;
typedef struct d3d9_surface_t              d3d9_surface_t             ;
typedef struct d3d9_volume_t               d3d9_volume_t              ;
typedef struct d3d9_query_t                d3d9_query_t               ;

#endif /* HEADER_D3D9PROT_H_ */


