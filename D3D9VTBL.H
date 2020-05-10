/*
 * D3D9VTBL.H : VTables For Direct3D9, Version 9.0c.
 *
 * Created on: 22 sep 2019
 * Updated on: 10 may 2020
 *     Author: Martin Andreasson
 *    Version: 1.0
 *    License: Mozilla Public License Version 2.0
 */

#ifndef HEADER_D3D9VTBL_H_
#define HEADER_D3D9VTBL_H_

#include "HARDFORM.H"

#include "D3D9ENUM.H" // enums
#include "D3D9TYPE.H" // types
#include "D3D9UTIL.H" // type utils
#include "D3D9PROT.H" // prototypes

//! The VTable of IUnknown.
typedef struct D3D9_IUNKNOWN_VTBL_T
{
#if 1 // IUnknown functions
	//! This function is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_iunknown_t * p,
		d3d9_guid_t     * riid,
		void           ** ppvObj );
	
	//! AddRef increments the reference count for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_iunknown_t * p );
	
	//! Release has to be called when finished using
	//! the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_iunknown_t * p );
#endif
}
d3d9_iunknown_vtbl_t;

//! The VTable of IDirect3D.
typedef struct D3D9_IDIRECT3D_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_t          * p,
		d3d9_guid_t     * riid,
		void           ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_t * p );
#endif
#if 1 // IDirect3D functions
	//! RegisterSoftwareDevice registers a pluggable software device.
	//! Software devices provide software rasterization enabling
	//! applications to access a variety of software rasterizers.
	hresult_t ( __stdcall * registerSoftwareDevice )(
		d3d9_t                 * p,
		void                   * p_initializeFunction );
	
	//! GetAdapterCount returns the number of adapters on the system.
	u32 ( __stdcall * getAdapterCount )( d3d9_t * p );
	
	//! GetAdapterIdentifier describes the physical display adapters
	//! present in the system when the IDirect3D9 interface was instantiated.
	//! Adapter must be a value from 0 to GetAdapterCount()-1.
	hresult_t ( __stdcall * getAdapterIdentifier )(
		d3d9_t                    * p,
		u32                         a_adapter,
		u32                         a_flags,
		d3d9_adapter_identifier_t * p_identifier );
	
	//! GetAdapterModeCount returns the number of
	//! display modes available on this adapter.
	u32 ( __stdcall * getAdapterModeCount )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_format_t            a_format );
	
	//! EnumAdapterModes queries the device to determine whether the specified
	//! adapter supports the requested format and display mode. This method
	//! could be used in a loop to enumerate all the available adapter modes.
	//!
	//! Allowed formats are as follows:
	//!   FMT_A1R5G5B5
	//!   FMT_A2R10G10B10
	//!   FMT_A8R8G8B8
	//!   FMT_R5G6B5
	//!   FMT_X1R5G5B5
	//!   FMT_X8R8G8B8
	//!
	//! EnumAdapterModes treats pixel formats 565 and 555 as equivalent, and
	//! returns the correct version. The difference comes into play only when
	//! the application locks the back buffer and there is an explicit flag
	//! that the application must set in order to accomplish this.
	hresult_t( __stdcall * enumAdapterModes )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_format_t            a_format,
		u32                      a_mode,
		d3d9_displaymode_t     * p_mode );
	
	//! GetAdapterDisplayMode retrieves current display mode of the adapter.
	hresult_t ( __stdcall * getAdapterDisplayMode )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_displaymode_t     * p_mode );
	
	//! CheckDeviceType verifies whether a hardware
	//! accelerated device type can be used on this adapter.
	hresult_t ( __stdcall * checkDeviceType )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_devtype_t           a_devType,
		d3d9_format_t            a_adapter_format,
		d3d9_format_t            a_backbuffer_format,
		bool32                   b_windowed );
	
	//! CheckDeviceFormat determines whether a surface format is available as
	//! a specified resource type and can be used as a texture, depth-stencil
	//! buffer, or render target, or any combination of the three,
	//! on a device representing this adapter.
	hresult_t ( __stdcall * checkDeviceFormat )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_devtype_t           a_deviceType,
		d3d9_format_t            a_adapterFormat,
		u32                      a_usage,
		d3d9_resourcetype_t      a_rType,
		d3d9_format_t            a_checkFormat );
	
	//! CheckDeviceMultiSampleType determines if a
	//! multisampling technique is available on this device.
	hresult_t ( __stdcall * checkDeviceMultiSampleType )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_devtype_t           a_deviceType,
		d3d9_format_t            a_surfaceFormat,
		bool32                   a_windowed,
		d3d9_multisample_type_t  a_multiSampleType,
		u32                    * p_qualityLevels );
	
	//! CheckDepthStencilMatch determines whether a depth-stencil format is
	//! compatible with a render-target format in a particular display mode.
	hresult_t ( __stdcall * checkDepthStencilMatch )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_devtype_t           a_deviceType,
		d3d9_format_t            a_adapterFormat,
		d3d9_format_t            a_renderTargetFormat,
		d3d9_format_t            a_depthStencilFormat );
	
	//! CheckDeviceFormatConversion tests the device to see if it
	//! supports conversion from one display format to another.
	hresult_t ( __stdcall * checkDeviceFormatConversion )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_devtype_t           a_deviceType,
		d3d9_format_t            a_sourceFormat,
		d3d9_format_t            a_targetFormat );
	
	//! GetDeviceCaps retrieves device-specific information about a device.
	hresult_t ( __stdcall * getDeviceCaps )(
		d3d9_t                 * p,
		u32                      a_adapter,
		d3d9_devtype_t           a_deviceType,
		d3d9_caps_t            * p_caps );
	
	//! GetAdapterMonitor returns the handle of the
	//! monitor associated with the Direct3D object.
	hmonitor_t ( __stdcall * getAdapterMonitor )(
		d3d9_t                 * p,
		u32                      a_adapter );
	
	//! CreateDevice creates a device to represent the display adapter.
	hresult_t ( __stdcall * createDevice )(
		d3d9_t                     * p,
		u32                          a_adapter,
		d3d9_devtype_t               a_deviceType,
		hwnd_t                       a_hFocusWindow,
		u32                          a_behaviorFlags,
		d3d9_present_parameters_t  * p_presentationParameters,
	d3d9_device_t             ** pp_returnedDeviceInterface );
#endif
}
d3d9_idirect3d_vtbl_t;

//! The VTable of IDirect3DDevice9.
typedef struct D3D9_DEVICE_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_device_t   * p,
		d3d9_guid_t     * riid,
		void           ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_device_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_device_t * p );
#endif
#if 1 // IDirect3DDevice9 functions
	//! TestCooperativeLevel reports the current cooperative-level status
	//! of the Direct3D device for a windowed or full-screen application.
	hresult_t ( __stdcall * testCooperativeLevel )(
		d3d9_device_t * p );
	
	//! GetAvailableTextureMem returns an estimate
	//! of the amount of available texture memory.
	u32 ( __stdcall * getAvailableTextureMem )(
		d3d9_device_t * p );
	
	//! EvictManagedResources evicts all managed resources,
	//! including both Direct3D and driver-managed resources.
	hresult_t ( __stdcall * evictManagedResources )(
		d3d9_device_t * p );
	
	//! GetDirect3D returns an interface to the instance
	//! of the Direct3D object that created the device.  Call
	//! Release on the returned object when finished using it.
	hresult_t ( __stdcall * getDirect3D )(
		d3d9_device_t * p,
		d3d9_t       ** ppD3D9 );
	
	//! GetDeviceCaps retrieves the capabilities of the rendering device.
	hresult_t ( __stdcall * getDeviceCaps )(
		d3d9_device_t * p,
		d3d9_caps_t   * pCaps );
	
	//! GetDisplayMode retrieves the display mode's spatial
	//! resolution, color resolution, and refresh frequency.
	hresult_t ( __stdcall * getDisplayMode )(
		d3d9_device_t      * p,
		u32                  iSwapChain,
		d3d9_displaymode_t * pMode );
	
	//! GetCreationParameters retrieves the creation parameters of the device.
	hresult_t ( __stdcall * getCreationParameters )(
		d3d9_device_t                     * p,
		d3d9_device_creation_parameters_t * pParameters );
	
	//! SetCursorProperties sets properties for the cursor.
	hresult_t ( __stdcall * setCursorProperties )(
		d3d9_device_t  * p,
		u32              XHotSpot,
		u32              YHotSpot,
		d3d9_surface_t * pCursorBitmap );
	
	//! SetCursorPosition sets the cursor position and update options.
	void ( __stdcall * setCursorPosition )(
		d3d9_device_t * p,
		int             aX,
		int             aY,
		u32             aFlags );
	
	//! ShowCursor displays or hides the cursor.
	bool32 ( __stdcall * showCursor )(
		d3d9_device_t * p,
		bool32          bShow );
	
	//! Create additional swap chain for rendering multiple views.
	hresult_t ( __stdcall * createAdditionalSwapChain )(
		d3d9_device_t             * p,
		d3d9_present_parameters_t * pPresentationParameters,
		d3d9_swapchain_t         ** pSwapChain );
	
	//! GetSwapChain returns a pointer to a swap chain.
	hresult_t ( __stdcall * getSwapChain )(
		d3d9_device_t     * p,
		u32                 iSwapChain,
		d3d9_swapchain_t ** pSwapChain );
	
	//! GetNumberOfSwapChains returns the number of implicit swap chains.
	u32 ( __stdcall * getNumberOfSwapChains )( d3d9_device_t * p );
	
	//! Reset resets the type, size, and format of the swap chain.
	hresult_t ( __stdcall * reset )(
		d3d9_device_t             * p,
		d3d9_present_parameters_t * pPresentationParameters );
	
	//! Present presents the contents of the next buffer
	//! in the sequence of back buffers owned by the device.
	hresult_t ( __stdcall * present )(
		d3d9_device_t        * p,
		const d3d9_rect_t    * pSourceRect,
		const d3d9_rect_t    * pDestRect,
		hwnd_t                 hDestWindowOverride,
		const d3d9_rgndata_t * pDirtyRegion );
	
	//! GetBackBuffer retrieves a back buffer from the device's swap chain.
	//! Call Release on the returned surface when finished using it.
	hresult_t ( __stdcall * getBackBuffer )(
		d3d9_device_t          * p,
		u32                      iSwapChain,
		u32                      iBackBuffer,
		d3d9_backbuffer_type_t   aType,
		d3d9_surface_t        ** ppBackBuffer );
	
	//! GetRasterStatus returns information describing the raster
	//! of the monitor on which the swap chain is presented.
	hresult_t ( __stdcall * getRasterStatus )(
		d3d9_device_t        * p,
		u32                    iSwapChain,
		d3d9_raster_status_t * pRasterStatus );
	
	//! SetDialogBoxMode allows the use of
	//! GDI dialog boxes in full-screen mode applications.
	hresult_t ( __stdcall * setDialogBoxMode )(
		d3d9_device_t     * p,
		bool32              bEnableDialogs );
	
	//! SetGammaRamp sets the gamma correction ramp for the
	//! implicit swap chain.  This method will affect the entire screen
	//! (not just the active window if you are running in windowed mode).
	void ( __stdcall * setGammaRamp )(
		d3d9_device_t          * p,
		u32                      iSwapChain,
		u32                      aFlags,
		const d3d9_gammaramp_t * pRamp );
	
	//! GetGammaRamp retrieves the gamma correction ramp for the swap chain.
	void ( __stdcall * getGammaRamp )(
		d3d9_device_t    * p,
		u32                iSwapChain,
		d3d9_gammaramp_t * pRamp );
	
	//! CreateTexture creates a texture resource.
	hresult_t ( __stdcall * createTexture )(
		d3d9_device_t   * p,
		u32               aWidth,
		u32               aHeight,
		u32               aLevels,
		u32               aUsage,
		d3d9_format_t     aFormat,
		d3d9_pool_t       aPool,
		d3d9_texture_t ** ppTexture,
		handle_t        * pSharedHandle );
	
	//! CreateVolumeTexture creates a volume texture resource.
	hresult_t ( __stdcall * createVolumeTexture )(
		d3d9_device_t          * p,
		u32                      aWidth,
		u32                      aHeight,
		u32                      aDepth,
		u32                      aLevels,
		u32                      aUsage,
		d3d9_format_t            aFormat,
		d3d9_pool_t              aPool,
		d3d9_volume_texture_t ** ppVolumeTexture,
		handle_t               * pSharedHandle );
	
	//! CreateCubeTexture creates a cube texture resource.
	hresult_t ( __stdcall * createCubeTexture )(
		d3d9_device_t        * p,
		u32                    aEdgeLength,
		u32                    aLevels,
		u32                    aUsage,
		d3d9_format_t          aFormat,
		d3d9_pool_t            aPool,
		d3d9_cube_texture_t ** ppCubeTexture,
		handle_t             * pSharedHandle );
	
	//! CreateVertexBuffer creates a vertex buffer.
	hresult_t ( __stdcall * createVertexBuffer )(
		d3d9_device_t         * p,
		u32                     aLength,
		u32                     aUsage,
		u32                     aFVF,
		d3d9_pool_t             aPool,
		d3d9_vertex_buffer_t ** ppVertexBuffer,
		handle_t              * pSharedHandle );
	
	//! CreateIndexBuffer creates an index buffer.
	hresult_t ( __stdcall * createIndexBuffer )(
		d3d9_device_t         * p,
		u32                     aLength,
		u32                     aUsage,
		d3d9_format_t           aFormat,
		d3d9_pool_t             aPool,
		d3d9_index_buffer_t  ** ppIndexBuffer,
		handle_t              * pSharedHandle );
	
	//! CreateRenderTarget creates a render-target surface.
	hresult_t ( __stdcall * createRenderTarget )(
		d3d9_device_t          * p,
		u32                      aWidth,
		u32                      aHeight,
		d3d9_format_t            aFormat,
		d3d9_multisample_type_t  aMultiSample,
		u32                      aMultisampleQuality,
		bool32                   aLockable,
		d3d9_surface_t        ** ppSurface,
		handle_t               * pSharedHandle );
	
	//! CreateDepthStencilSurface creates a depth-stencil resource.
	hresult_t ( __stdcall * createDepthStencilSurface )(
		d3d9_device_t          * p,
		u32                      aWidth,
		u32                      aHeight,
		d3d9_format_t            aFormat,
		d3d9_multisample_type_t  aMultiSample,
		u32                      aMultisampleQuality,
		bool32                   aDiscard,
		d3d9_surface_t        ** ppSurface,
		handle_t               * pSharedHandle );
	
	//! UpdateSurface copies rectangular
	//! subsets of pixels from one surface to another.
	hresult_t ( __stdcall * updateSurface )(
		d3d9_device_t      * p, 
		d3d9_surface_t     * pSourceSurface,
		const d3d9_rect_t  * pSourceRect,
		d3d9_surface_t     * pDestinationSurface,
		const d3d9_point_t * pDestPoint );
	
	//! UpdateTexture updates the dirty portions of a texture.
	hresult_t ( __stdcall * updateTexture )(
		d3d9_device_t       * p,
		d3d9_base_texture_t * pSourceTexture,
		d3d9_base_texture_t * pDestinationTexture );
	
	//! GetRenderTargetData copies the render-target
	//! data from device memory to system memory.
	hresult_t ( __stdcall * getRenderTargetData )(
		d3d9_device_t  * p,
		d3d9_surface_t * pRenderTarget,
		d3d9_surface_t * pDestSurface );
	
	//! GetFrontBufferData generates a copy of the device's front buffer and
	//! places that copy in a system memory buffer provided by an application.
	hresult_t ( __stdcall * getFrontBufferData )(
		d3d9_device_t  * p,
		u32              iSwapChain,
		d3d9_surface_t * pDestSurface );
	
	//! StretchRect copies the contents of the source rectangle to the dest
	//! rectangle. The source rect can be stretched & filtered by the copy.
	//! This function is often used to change the AR of a video stream.
	hresult_t ( __stdcall * stretchRect )(
		d3d9_device_t            * p,
		d3d9_surface_t           * pSourceSurface,
		const d3d9_rect_t        * pSourceRect,
		d3d9_surface_t           * pDestSurface,
		const d3d9_rect_t        * pDestRect,
		d3d9_texturefiltertype_t   aFilter );
	
	//! ColorFill allows an application to fill a rectangular
	//! area of a POOL_DEFAULT surface with a specified color.
	hresult_t ( __stdcall * colorFill )(
		d3d9_device_t     * p,
		d3d9_surface_t    * pSurface,
		const d3d9_rect_t * pRect,
		d3d9_color_t        aColor );
	
	//! CreateOffscreenPlainSurface creates an off-screen surface.
	hresult_t ( __stdcall * createOffscreenPlainSurface )(
		d3d9_device_t          * p,
		u32                      aWidth,
		u32                      aHeight,
		d3d9_format_t            aFormat,
		d3d9_pool_t              aPool,
		d3d9_surface_t        ** ppSurface,
		handle_t               * pSharedHandle );
	
	//! SetRenderTarget sets a new color buffer for the device.
	hresult_t ( __stdcall * setRenderTarget )(
		d3d9_device_t  * p,
		u32              aRenderTargetIndex,
		d3d9_surface_t * pRenderTarget );
	
	//! GetRenderTarget retrieves a render-target surface.
	hresult_t ( __stdcall * getRenderTarget )(
		d3d9_device_t   * p,
		u32               aRenderTargetIndex,
		d3d9_surface_t ** ppRenderTarget );
	
	//! SetDepthStencilSurface sets the depth stencil surface.
	hresult_t ( __stdcall * setDepthStencilSurface )(
		d3d9_device_t  * p,
		d3d9_surface_t * pNewZStencil );
	
	//! GetDepthStencilSurface returns the
	//! depth-stencil surface owned by the Direct3DDevice object.
	//! Call Release on the returned surface when finished using it.
	hresult_t ( __stdcall * getDepthStencilSurface )(
		d3d9_device_t   * p,
		d3d9_surface_t ** ppZStencilSurface );
	
	//! BeginScene begins a scene. Applications must call BeginScene
	//! before performing any rendering and must call EndScene when
	//! rendering is complete and before calling BeginScene again.
	hresult_t ( __stdcall * beginScene )( d3d9_device_t * p );
	
	//! EndScene ends a scene that was begun by calling BeginScene.
	hresult_t ( __stdcall * endScene )( d3d9_device_t * p );
	
	//! Clear clears one or more surfaces such as a render target,
	//! multiple render targets, a stencil buffer, and a depth buffer.
	hresult_t ( __stdcall * clear )(
		d3d9_device_t     * p,
		u32                 aCount,
		const d3d9_rect_t * pRects,
		u32                 aFlags,
		d3d9_color_t        aColor,
		float               aZ,
		u32                 aStencil );
	
	//! SetTransform sets a single device transformation-related state.
	hresult_t ( __stdcall * setTransform )(
		d3d9_device_t             * p,
		d3d9_transformstatetype_t   aState,
		const d3d9_matrix_t       * pMatrix );
	
	//! GetTransform retrieves a matrix describing a transformation state.
	hresult_t ( __stdcall * getTransform )(
		d3d9_device_t             * p,
		d3d9_transformstatetype_t   aState,
		d3d9_matrix_t             * pMatrix );
	
	//! MultiplyTransform multiplies a device's world,
	//! view, or projection matrices by a specified matrix.
	hresult_t ( __stdcall * multiplyTransform )(
		d3d9_device_t             * p,
		d3d9_transformstatetype_t   aState,
		const d3d9_matrix_t       * pMatrix );
	
	//! SetViewport sets the viewport parameters for the device.
	hresult_t ( __stdcall * setViewport )(
		d3d9_device_t         * p,
		const d3d9_viewport_t * pViewport );
	
	//! GetViewport retrieves the viewport params currently set for device.
	hresult_t ( __stdcall * getViewport )(
		d3d9_device_t   * p,
		d3d9_viewport_t * pViewport );
	
	//! SetMaterial sets the material properties for the device.
	hf_addr setMaterial;
	
	//! GetMaterial retrieves the current material properties for the device.
	hf_addr getMaterial;
	
	//! SetLight assigns a set of lighting properties for this device.
	hf_addr setLight;
	
	//! GetLight retrieves a set of lighting properties that this device uses.
	hf_addr getLight;
	
	//! LightEnable enables or disables a set of lighting params for a device.
	hresult_t ( __stdcall * lightEnable )(
		d3d9_device_t * p,
		u32             aIndex,
		bool32          aEnable );
	
	//! GetLightEnable retrieves the activity status (enabled or disabled)
	//! for a set of lighting parameters within a device.
	hf_addr getLightEnable;
	
	//! SetClipPlane sets the coefficients of a
	//! user-defined clipping plane for the device.
	hresult_t ( __stdcall * setClipPlane )(
		d3d9_device_t * p,
		u32             aIndex,
		const float   * pPlane );
	
	//! GetClipPlane retrieves the coefficients of a
	//! user-defined clipping plane for the device.
	hresult_t ( __stdcall * getClipPlane )(
		d3d9_device_t * p,
		u32             aIndex,
		float         * pPlane );
	
	//! SetRenderState sets a single device render-state parameter.
	hresult_t ( __stdcall * setRenderState )(
		d3d9_device_t          * p,
		d3d9_renderstatetype_t   aState,
		u32                      aValue );
	
	//! GetRenderState retrieves a render-state value for a device.
	hresult_t ( __stdcall * getRenderState )(
		d3d9_device_t          * p,
		d3d9_renderstatetype_t   aState,
		u32                    * pValue );
	
	//! CreateStateBlock creates a new state block that contains the values
	//! for all device states, vertex-related states, or pixel-related states.
	hresult_t ( __stdcall * createStateBlock )(
		d3d9_device_t          * p,
		d3d9_stateblocktype_t    aType,
		d3d9_state_block_t    ** ppSB );
	
	//! BeginStateBlock signals Direct3D to begin making a device-state block.
	hresult_t ( __stdcall * beginStateBlock )( d3d9_device_t * p );
	
	//! EndStateBlock signals Direct3D to stop recording a device-state block
	//! and retrieve a pointer to the state block interface.
	hresult_t ( __stdcall * endStateBlock )(
		d3d9_device_t       * p,
		d3d9_state_block_t ** ppSB );
	
	//! SetClipStatus sets the clip status.
	hresult_t ( __stdcall * setClipStatus )(
		d3d9_device_t           * p,
		const d3d9_clipstatus_t * pClipStatus );
	
	//! GetClipStatus retrieves the clip status.
	hresult_t ( __stdcall * getClipStatus )(
		d3d9_device_t     * p,
		d3d9_clipstatus_t * pClipStatus );
	
	//! GetTexture retrieves a texture assigned to a stage for a device.
	hresult_t ( __stdcall * getTexture )(
		d3d9_device_t        * p,
		u32                    aStage,
		d3d9_base_texture_t ** ppTexture );
	
	//! SetTexture assigns a texture to a stage for a device.
	hresult_t ( __stdcall * setTexture )(
		d3d9_device_t       * p,
		u32                   aStage,
		d3d9_base_texture_t * pTexture );
	
	//! GetTextureStageState retrieves a state value for an assigned texture.
	hresult_t ( __stdcall * getTextureStageState )(
		d3d9_device_t                * p,
		u32                            aStage,
		d3d9_texturestagestatetype_t   aType,
		u32                          * pValue );
	
	//! Sets the state value for the currently assigned texture.
	hresult_t ( __stdcall * setTextureStageState )(
		d3d9_device_t                * p,
		u32                            aStage,
		d3d9_texturestagestatetype_t   aType,
		u32                            aValue );
	
	//! GetSamplerState return the sampler state value.
	hresult_t ( __stdcall * getSamplerState )(
		d3d9_device_t           * p,
		u32                       aSampler,
		d3d9_samplerstatetype_t   aType,
		u32                     * pValue );
	
	//! SetSamplerState sets the sampler state value.
	hresult_t ( __stdcall * setSamplerState )(
		d3d9_device_t           * p,
		u32                       aSampler,
		d3d9_samplerstatetype_t   aType,
		u32                       aValue );
	
	//! ValidateDevice reports the device's ability to render the current
	//! texture-blending operations and arguments in a single pass.
	hresult_t ( __stdcall * validateDevice )(
		d3d9_device_t * p,
		u32           * pNumPasses );
	
	//! SetPaletteEntries sets palette entries.
	hresult_t ( __stdcall * setPaletteEntries )(
		d3d9_device_t             * p,
		u32                         paletteNumber,
		const d3d9_paletteentry_t * pEntries );
	
	//! GetPaletteEntries retrieves palette entries.
	hresult_t ( __stdcall * getPaletteEntries )(
		d3d9_device_t       * p,
		u32                   paletteNumber,
		d3d9_paletteentry_t * pEntries );
	
	//! SetCurrentTexturePalette sets the current texture palette.
	hresult_t ( __stdcall * setCurrentTexturePalette )(
		d3d9_device_t * p,
		u32             paletteNumber );
	
	//! GetCurrentTexturePalette retrieves the current texture palette.
	hresult_t ( __stdcall * getCurrentTexturePalette )(
		d3d9_device_t * p,
		u32           * paletteNumber );
	
	//! SetScissorRect sets the scissor rectangle.
	hresult_t ( __stdcall * setScissorRect )(
		d3d9_device_t     * p,
		const d3d9_rect_t * pRect );
	
	//! GetScissorRect returns the scissor rectangle.
	hresult_t ( __stdcall * getScissorRect )(
		d3d9_device_t * p,
		d3d9_rect_t   * pRect );
	
	//! SetSoftwareVertexProcessing can be used to switch
	//! between software and hardware vertex processing.
	hresult_t ( __stdcall * setSoftwareVertexProcessing )(
		d3d9_device_t * p,
		bool32          bSoftware );
	
	//! GetSoftwareVertexProcessing returns true if
	//! software vertex processing is set. Otherwise, it returns false.
	bool32 ( __stdcall * getSoftwareVertexProcessing )(
		d3d9_device_t * p );
	
	// SetNPatchMode enables or disables N-patches. segmentCount specifies the
	// number of subdivision segments. If the number of segments is less than
	// 1.0, N-patches are disabled. The default value is 0.0.
	hresult_t ( __stdcall * setNPatchMode )(
		d3d9_device_t * p,
		float           nSegments );
	
	//! GetNPatchMode returns the N-patch mode segments.
	float ( __stdcall * getNPatchMode )( d3d9_device_t * p );
	
	//! DrawPrimitive renders a sequence of nonindexed, geometric primitives
	//! of the specified type from the current set of data input streams.
	hresult_t ( __stdcall * drawPrimitive )(
		d3d9_device_t      * p,
		d3d9_primitivetype_t primitiveType,
		u32                  startVertex,
		u32                  primitiveCount );
	
	//! DrawIndexedPrimitive renders the specified geometric
	//! primitive into an array of vertices, based on indexing.
	hresult_t ( __stdcall * drawIndexedPrimitive )(
		d3d9_device_t        * p,
		d3d9_primitivetype_t   primitiveType,
		int                    baseVertexIndex,
		u32                    minVertexIndex,
		u32                    numVertices,
		u32                    startIndex,
		u32                    primCount );
	
	//! DrawPrimitiveUP renders data specified by a user memory pointer
	//! as a sequence of geometric primitives of the specified type.
	hresult_t ( __stdcall * drawPrimitiveUP )(
		d3d9_device_t        * p,
		d3d9_primitivetype_t   primitiveType,
		u32                    primitiveCount,
		const void           * pVertexStreamZeroData,
		u32                    aVertexStreamZeroStride );
	
	//! DrawIndexedPrimitiveUP renders the specified geometric
	//! primitive with data specified by a user memory pointer.
	hresult_t ( __stdcall * drawIndexedPrimitiveUP )(
		d3d9_device_t        * p,
		d3d9_primitivetype_t   primitiveType,
		u32                    minVertexIndex,
		u32                    numVertices,
		u32                    aPrimitiveCount,
		const void           * pIndexData,
		d3d9_format_t          aIndexDataFormat,
		const void           * pVertexStreamZeroData,
		u32                    aVertexStreamZeroStride );
	
	//! ProcessVertices applies the vertex processing defined by the vertex
	//! shader to the set of input data streams, generating a single stream
	//! of interleaved vertex data to the destination vertex buffer.
	hresult_t ( __stdcall * processVertices )(
		d3d9_device_t             * p,
		u32                         srcStartIndex,
		u32                         destIndex,
		u32                         vertexCount,
		d3d9_vertex_buffer_t      * pDestBuffer,
		d3d9_vertex_declaration_t * pVertexDecl,
		u32                         aFlags );
	
	//! CreateVertexDeclaration creates a vertex shader declaration
	//! from the device and the vertex elements.
	//! The last element should be DeclEnd().
	hresult_t ( __stdcall * createVertexDeclaration )(
		d3d9_device_t              * p,
		const d3d9_vertexelement_t * pVertexElements,
		d3d9_vertex_declaration_t ** ppDecl );
	
	//! SetVertexDeclaration sets a vertex declaration.
	hresult_t ( __stdcall * setVertexDeclaration )(
		d3d9_device_t             * p,
		d3d9_vertex_declaration_t * pDecl );
	
	//! GetVertexDeclaration returns a vertex shader declaration.
	hresult_t ( __stdcall * getVertexDeclaration )(
		d3d9_device_t              * p,
		d3d9_vertex_declaration_t ** ppDecl );
	
	//! SetFVF sets the current vertex stream declaration.
	hresult_t ( __stdcall * setFVF )(
		d3d9_device_t * p,
		u32             aFVF );
	
	//! GetFVF gets the fixed vertex function declaration.
	hresult_t ( __stdcall * getFVF )(
		d3d9_device_t * p,
		u32           * pFVF );
	
	//! CreateVertexShader creates a vertex shader.
	hresult_t ( __stdcall * createVertexShader )(
		d3d9_device_t         * p,
		const u32             * pFunction,
		d3d9_vertex_shader_t ** ppShader );
	
	//! SetVertexShader sets the vertex shader.
	hresult_t ( __stdcall * setVertexShader )(
		d3d9_device_t        * p,
		d3d9_vertex_shader_t * pShader );
	
	//! GetVertexShader retrieves the currently set vertex shader.
	hresult_t ( __stdcall * getVertexShader )(
		d3d9_device_t         * p,
		d3d9_vertex_shader_t ** ppShader );
	
	//! SetVertexShaderConstantF sets a floating-point vertex shader constant.
	//! The length of the slice must be a multiple of four.
	hresult_t ( __stdcall * setVertexShaderConstantF )(
		d3d9_device_t * p,
		u32             startRegister,
		const float   * pConstantData,
		u32             v4fCount );
	
	//! GetVertexShaderConstantF returns a floating-point shader constant.
	//! The given float slice is filled with the constant data.
	//! The length of the slice must be a multiple of four.
	hresult_t ( __stdcall * getVertexShaderConstantF )(
		d3d9_device_t * p,
		u32             startRegister,
		float         * pConstantData,
		u32             v4fCount );
	
	//! SetVertexShaderConstantI sets an integer vertex shader constant.
	//! The length of the slice must be a multiple of four.
	hresult_t ( __stdcall * setVertexShaderConstantI )(
		d3d9_device_t * p,
		u32             startRegister,
		const int     * pConstantData,
		u32             v4iCount );
	
	//! GetVertexShaderConstantI returns an integer shader constant.
	//! The given int slice is filled with the constant data.
	//! The length of the slice must be a multiple of four.
	hresult_t ( __stdcall * getVertexShaderConstantI )(
		d3d9_device_t * p,
		u32             startRegister,
		int           * pConstantData,
		u32             v4iCount );
	
	//! SetVertexShaderConstantB sets a Boolean vertex shader constant.
	hresult_t ( __stdcall * setVertexShaderConstantB )(
		d3d9_device_t * p,
		u32             startRegister,
		const bool32  * pConstantData,
		u32             boolCount );
	
	//! GetVertexShaderConstantB returns a Boolean shader constant.
	//! The given bool slice is filled with the constant data.
	hresult_t ( __stdcall * getVertexShaderConstantB )(
		d3d9_device_t * p,
		u32             startRegister,
		bool32        * pConstantData,
		u32             boolCount );
	
	//! SetStreamSource binds a vertex buffer to a device data stream.
	hresult_t ( __stdcall * setStreamSource )(
		d3d9_device_t          * p,
		u32                      streamNumber,
		d3d9_vertex_buffer_t   * pStreamData,
		u32                      offsetInBytes,
		u32                      aStride );
	
	//! Retrieves a vertex buffer bound to the specified data stream.
	hresult_t ( __stdcall * getStreamSource )(
		d3d9_device_t           * p,
		u32                       aStreamNumber,
		d3d9_vertex_buffer_t   ** ppStreamData,
		u32                     * pOffsetInBytes,
		u32                     * pStride );
	
	//! SetStreamSourceFreq sets the stream source frequency divider value.
	//! This may be used to draw several instances of geometry.
	hresult_t ( __stdcall * setStreamSourceFreq )(
		d3d9_device_t * p,
		u32             aStreamNumber,
		u32             aSetting );
	
	//! GetStreamSourceFreq returns the stream source frequency divider value.
	hresult_t ( __stdcall * getStreamSourceFreq )(
		d3d9_device_t * p,
		u32             aStreamNumber,
		u32           * pSetting );
	
	//! SetIndices sets index data.
	hresult_t ( __stdcall * setIndices )(
		d3d9_device_t       * p,
		d3d9_index_buffer_t * pIndexData );
	
	//! GetIndices retrieves index data.
	hresult_t ( __stdcall * getIndices )(
		d3d9_device_t        * p,
		d3d9_index_buffer_t ** ppIndexData );
	
	//! CreatePixelShader creates a pixel shader.
	hresult_t ( __stdcall * createPixelShader )(
		d3d9_device_t        * p,
		const u32            * pFunction,
		d3d9_pixel_shader_t ** ppShader );
	
	//! SetPixelShader sets the current pixel shader
	//! to a previously created pixel shader.
	hresult_t ( __stdcall * setPixelShader )(
		d3d9_device_t       * p,
		d3d9_pixel_shader_t * pShader );
	
	//! GetPixelShader retrieves the currently set pixel shader.
	hresult_t ( __stdcall * getPixelShader )(
		d3d9_device_t        * p,
		d3d9_pixel_shader_t ** ppShader );
	
	//! SetPixelShaderConstantF sets a floating-point shader constant.
	//! The length of the slice must be a multiple of four.
	hresult_t ( __stdcall * setPixelShaderConstantF )(
		d3d9_device_t * p,
		u32             aStartRegister,
		const float   * pConstantData,
		u32             v4fCount );
	
	//! GetPixelShaderConstantF returns a floating-point shader constant.
	//! The given float slice is filled with the constant data.
	//! The length of the slice must be a multiple of four.
	hresult_t ( __stdcall * getPixelShaderConstantF )(
		d3d9_device_t * p,
		u32             aStartRegister,
		float         * pConstantData,
		u32             v4fCount );
	
	//! SetPixelShaderConstantI sets an integer shader constant.
	//! The length of the slice must be a multiple of four.
	hresult_t ( __stdcall * setPixelShaderConstantI )(
		d3d9_device_t * p,
		u32             aStartRegister,
		const int     * pConstantData,
		u32             v4iCount );
	
	//! GetPixelShaderConstantI returns an integer shader constant.
	//! The given int slice is filled with the constant data.
	//! The length of the slice must be a multiple of four.
	hresult_t ( __stdcall * getPixelShaderConstantI )(
		d3d9_device_t * p,
		u32             aStartRegister,
		int           * pConstantData,
		u32             v4iCount );
	
	//! SetPixelShaderConstantB sets a Boolean shader constant.
	hresult_t ( __stdcall * setPixelShaderConstantB )(
		d3d9_device_t * p,
		u32             aStartRegister,
		const bool32  * pConstantData,
		u32             aBoolCount );
	
	//! GetPixelShaderConstantB returns a Boolean shader constant.
	//! The given bool slice is filled with the constant data.
	hresult_t ( __stdcall * getPixelShaderConstantB )(
		d3d9_device_t * p,
		u32             aStartRegister,
		bool32 *        pConstantData,
		u32             aBoolCount );

	//! Draws a rectangular patch using the currently set streams.
	hresult_t ( __stdcall * drawRectPatch )(
		d3d9_device_t               * p,
		u32                           aHandle,
		const float                 * pNumSegs,
		const d3d9_rectpatch_info_t * pRectPatchInfo );
	
	//! DrawTriPatch draws a triangular patch using the currently set streams.
	hresult_t ( __stdcall * drawTriPatch )(
		d3d9_device_t              * p,
		u32                          aHandle,
		const float                * pNumSegs,
		const d3d9_tripatch_info_t * pTriPatchInfo );
	
	//! DeletePatch frees a cached high-order patch.
	hresult_t ( __stdcall * deletePatch )(
		d3d9_device_t * p,
		u32             aHandle );
	
	//! CreateQuery creates a status query.
	hresult_t ( __stdcall * createQuery )(
		d3d9_device_t     * p,
		d3d9_querytype_t    aType,
		d3d9_query_t     ** ppQuery );
#endif
}
d3d9_device_vtbl_t;

//! The VTable of IDirect3DStateBlock9.
typedef struct D3D9_STATE_BLOCK_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_state_block_t  * p,
		d3d9_guid_t         * riid,
		void               ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_state_block_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_state_block_t * p );
#endif
#if 1 // IDirect3DStateBlock9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t ( __stdcall * getDevice )(
		d3d9_state_block_t * p,
		d3d9_device_t     ** ppDevice );
	
	//! Capture captures the current value of
	//! states that are included in a stateblock.
	hresult_t ( __stdcall * capture )(
		d3d9_state_block_t * p );
	
	//! Apply applies the state block to the current device state.
	hresult_t ( __stdcall * apply )(
		d3d9_state_block_t * p );
#endif
}
d3d9_state_block_vtbl_t;

//! The VTable of IDirect3DSwapChain9.
typedef struct D3D9_SWAPCHAIN_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_swapchain_t    * p,
		d3d9_guid_t         * riid,
		void               ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_swapchain_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_swapchain_t * p );
#endif
#if 1 // IDirect3DSwapChain9 functions
	//! Present presents the contents of the next buffer in
	//! the sequence of back buffers owned by the swap chain.
	hresult_t( __stdcall * present )(
		d3d9_swapchain_t     * p,
		const d3d9_rect_t    * pSourceRect,
		const d3d9_rect_t    * pDestRect,
		hwnd_t                 hDestWindowOverride,
		const d3d9_rgndata_t * pDirtyRegion,
		u32                    dwFlags );
	
	//! GetFrontBufferData generates a copy of the swapchain's frontbuffer and
	//! places that copy in a system memory buffer provided by an application.
	//! Call Release on the returned surface when finished using it.
	hresult_t( __stdcall * getFrontBufferData )(
		d3d9_swapchain_t  * p,
		d3d9_surface_t    * pDestSurface );
	
	//! GetBackBuffer retrieves backbuffer from the swap chain of the device.
	//! Call Release on the returned surface when finished using it.
	hresult_t( __stdcall * getBackBuffer )(
		d3d9_swapchain_t       * p,
		u32                      iBackBuffer,
		d3d9_backbuffer_type_t   aType,
		d3d9_surface_t        ** ppBackBuffer );
	
	//! GetRasterStatus returns information describing the raster
	//! of the monitor on which the swap chain is presented.
	hresult_t( __stdcall * getRasterStatus )(
		d3d9_swapchain_t     * p,
		d3d9_raster_status_t * pRasterStatus );
	
	//! GetDisplayMode retrieves the display mode's spatial
	//! resolution, color resolution, and refresh frequency.
	hresult_t( __stdcall * getDisplayMode )(
		d3d9_swapchain_t   * p,
		d3d9_displaymode_t * pMode );
	
	//! GetDevice retrieves the device associated with the swap chain.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_swapchain_t  * p,
		d3d9_device_t    ** ppDevice );
	
	//! Get the presentation parameters associated with a swap chain.
	hresult_t( __stdcall * getPresentParameters )(
		d3d9_swapchain_t          * p,
		d3d9_present_parameters_t * pPresentationParameters );
#endif
}
d3d9_swapchain_vtbl_t;

//! The VTable of IDirect3DResource9.
typedef struct D3D9_RESOURCE_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_resource_t     * p,
		d3d9_guid_t         * riid,
		void               ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_resource_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_resource_t * p );
#endif
#if 1 // IDirect3DResource9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_resource_t * p,
		d3d9_device_t  ** ppDevice );
	
	//! SetPrivateData associates data with the resource that is intended for
	//! use by the application, not by Direct3D. Data is passed by value, and
	//! multiple sets of data can be associated with a single resource.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_resource_t   * p,
		d3d9_refguid_t      refGUID,
		const void        * pData,
		u32                 sizeOfData,
		u32                 aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the resource to a provided buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_resource_t * p,
		d3d9_refguid_t    refGUID,
		void            * pData,
		u32             * pSizeOfData );
	
	//! FreePrivateData frees the specified private data
	//! associated with this resource.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_resource_t * p,
		d3d9_refguid_t    refguid );
	
	//! SetPriority assigns the priority of a resource for scheduling purposes.
	u32  ( __stdcall * setPriority )(
		d3d9_resource_t * p,
		u32               priorityNew );
	
	//! GetPriority retrieves the priority for this resource.
	u32  ( __stdcall * getPriority )(
		d3d9_resource_t * p );
	
	//! PreLoad preloads a managed resource.
	void ( __stdcall * preLoad )(
		d3d9_resource_t * p );
	
	//! GetType returns the type of the resource.
	d3d9_resourcetype_t ( __stdcall * getType )(
		d3d9_resource_t * p );
#endif
}
d3d9_resource_vtbl_t;

//! The VTable of IDirect3DVertexDeclaration9.
typedef struct D3D9_VERTEX_DECLARATION_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_vertex_declaration_t  * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_vertex_declaration_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_vertex_declaration_t * p );
#endif
#if 1 // IDirect3DVertexDeclaration9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t ( __stdcall * getDevice )(
		d3d9_vertex_declaration_t * p,
		d3d9_device_t            ** ppDevice );
	
	//! GetDeclaration returns the vertex shader declaration.
	hresult_t ( __stdcall * getDeclaration )(
		d3d9_vertex_declaration_t * p,
		d3d9_vertexelement_t      * pElement,
		u32                       * pNumElements );
#endif
}
d3d9_vertex_declaration_vtbl_t;

//! The VTable of IDirect3DVertexShader9.
typedef struct D3D9_VERTEX_SHADER_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_vertex_shader_t       * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_vertex_shader_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_vertex_shader_t * p );
#endif
#if 1 // IDirect3DVertexShader9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t ( __stdcall * getDevice )(
		d3d9_vertex_shader_t * p,
		d3d9_device_t       ** ppDevice );
	
	//! GetFunction returns the shader data.
	hresult_t ( __stdcall * getFunction )(
		d3d9_vertex_shader_t * p,
		void                 * pData,
		u32                  * pSizeOfData );
#endif
}
d3d9_vertex_shader_vtbl_t;

//! The VTable of IDirect3DPixelShader9.
typedef struct D3D9_PIXEL_SHADER_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_pixel_shader_t        * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_pixel_shader_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_pixel_shader_t * p );
#endif
#if 1 // IDirect3DPixelShader9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t ( __stdcall * getDevice )(
		d3d9_pixel_shader_t * p,
		d3d9_device_t      ** ppDevice );
	
	//! GetFunction returns the shader data.
	hresult_t ( __stdcall * getFunction )(
		d3d9_pixel_shader_t  * p,
		void                 * pData,
		u32                  * pSizeOfData );
#endif
}
d3d9_pixel_shader_vtbl_t;

//! The VTable of IDirect3DBaseTexture9.
typedef struct D3D9_BASE_TEXTURE_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_base_texture_t        * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_base_texture_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_base_texture_t * p );
#endif
#if 1 // IDirect3DResource9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_base_texture_t  * p,
		d3d9_device_t       ** ppDevice );
	
	//! SetPrivateData associates data with the resource that is intended for
	//! use by the application, not by Direct3D. Data is passed by value, and
	//! multiple sets of data can be associated with a single resource.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_base_texture_t * p,
		d3d9_refguid_t        refGUID,
		const void          * pData,
		u32                   sizeOfData,
		u32                   aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the resource to a provided buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_base_texture_t * p,
		d3d9_refguid_t        refGUID,
		void                * pData,
		u32                 * pSizeOfData );
	
	//! FreePrivateData frees the specified private data
	//! associated with this resource.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_base_texture_t * p,
		d3d9_refguid_t        refguid );
	
	//! SetPriority assigns the priority of a resource for scheduling purposes.
	u32  ( __stdcall * setPriority )(
		d3d9_base_texture_t * p,
		u32                   priorityNew );
	
	//! GetPriority retrieves the priority for this resource.
	u32  ( __stdcall * getPriority )(
		d3d9_base_texture_t * p );
	
	//! PreLoad preloads a managed resource.
	void ( __stdcall * preLoad )(
		d3d9_base_texture_t * p );
	
	//! GetType returns the type of the resource.
	d3d9_resourcetype_t ( __stdcall * getType )(
		d3d9_base_texture_t * p );
#endif
#if 1 // IDirect3DBaseTexture9 functions
	//! SetLOD sets the most detailed level-of-detail for a managed texture.
	u32 ( __stdcall * setLOD )( d3d9_base_texture_t * p, u32 v );
	
	//! Get a value clamped to the maximum level-of-detail set for a managed
	//! texture (this method is not supported for an unmanaged texture).
	u32 ( __stdcall * getLOD )( d3d9_base_texture_t * p );
	
	//! Get the number of texture levels in a multilevel texture.
	u32 ( __stdcall * getLevelCount )( d3d9_base_texture_t * p );
	
	//! SetAutoGenFilterType sets the filter type that is
	//! used for automatically generated mipmap sublevels.
	hresult_t ( __stdcall * setAutoGenFilterType )(
		d3d9_base_texture_t      * p,
		d3d9_texturefiltertype_t   filterType );
	
	//! GetAutoGenFilterType returns the filter type that is
	//! used for automatically generated mipmap sublevels.
	d3d9_texturefiltertype_t ( __stdcall * getAutoGenFilterType )(
		d3d9_base_texture_t      * p );
	
	//! GenerateMipSubLevels generates mip sub levels.
	void ( __stdcall * generateMipSubLevels )( d3d9_base_texture_t * p );
#endif
}
d3d9_base_texture_vtbl_t;

//! The VTable of IDirect3DTexture9.
typedef struct D3D9_TEXTURE_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_texture_t             * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_texture_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_texture_t * p );
#endif
#if 1 // IDirect3DResource9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_texture_t       * p,
		d3d9_device_t       ** ppDevice );
	
	//! SetPrivateData associates data with the resource that is intended for
	//! use by the application, not by Direct3D. Data is passed by value, and
	//! multiple sets of data can be associated with a single resource.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_texture_t      * p,
		d3d9_refguid_t        refGUID,
		const void          * pData,
		u32                   sizeOfData,
		u32                   aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the resource to a provided buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_texture_t * p,
		d3d9_refguid_t   refGUID,
		void           * pData,
		u32            * pSizeOfData );
	
	//! FreePrivateData frees the specified private data
	//! associated with this resource.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_texture_t * p,
		d3d9_refguid_t   refguid );
	
	//! SetPriority assigns the priority of a resource for scheduling purposes.
	u32  ( __stdcall * setPriority )(
		d3d9_texture_t * p,
		u32              priorityNew );
	
	//! GetPriority retrieves the priority for this resource.
	u32  ( __stdcall * getPriority )(
		d3d9_texture_t * p );
	
	//! PreLoad preloads a managed resource.
	void ( __stdcall * preLoad )(
		d3d9_texture_t * p );
	
	//! GetType returns the type of the resource.
	d3d9_resourcetype_t ( __stdcall * getType )(
		d3d9_texture_t * p );
#endif
#if 1 // IDirect3DBaseTexture9 functions
	//! SetLOD sets the most detailed level-of-detail for a managed texture.
	u32 ( __stdcall * setLOD )( d3d9_texture_t * p, u32 v );
	
	//! Get a value clamped to the maximum level-of-detail set for a managed
	//! texture (this method is not supported for an unmanaged texture).
	u32 ( __stdcall * getLOD )( d3d9_texture_t * p );
	
	//! Get the number of texture levels in a multilevel texture.
	u32 ( __stdcall * getLevelCount )( d3d9_texture_t * p );
	
	//! SetAutoGenFilterType sets the filter type that is
	//! used for automatically generated mipmap sublevels.
	hresult_t ( __stdcall * setAutoGenFilterType )(
		d3d9_texture_t           * p,
		d3d9_texturefiltertype_t   filterType );
	
	//! GetAutoGenFilterType returns the filter type that is
	//! used for automatically generated mipmap sublevels.
	d3d9_texturefiltertype_t ( __stdcall * getAutoGenFilterType )(
		d3d9_texture_t * p );
	
	//! GenerateMipSubLevels generates mip sub levels.
	void ( __stdcall * generateMipSubLevels )( d3d9_texture_t * p );
#endif
#if 1 // IDirect3DTexture9 functions
	//! GetLevelDesc retrieves a level description of a texture resource.
	hresult_t ( __stdcall * getLevelDesc )(
		d3d9_texture_t      * p,
		u32                   aLevel,
		d3d9_surface_desc_t * pDesc );
	
	//! GetSurfaceLevel retrieves the specified texture surface level.
	hresult_t ( __stdcall * getSurfaceLevel )(
		d3d9_texture_t      * p,
		u32                   aLevel,
		d3d9_surface_t     ** ppSurfaceLevel );
	
	//! LockRect locks a rectangle on a texture resource.
	hresult_t ( __stdcall * lockRect )(
		d3d9_texture_t      * p,
		u32                   aLevel,
		d3d9_locked_rect_t  * pLockedRect,
		const d3d9_rect_t   * pRect,
		u32                   aFlags );
	
	//! UnlockRect unlocks a rectangle on a texture resource.
	hresult_t ( __stdcall * unlockRect )(
		d3d9_texture_t      * p,
		u32                   aLevel );
	
	//! AddDirtyRect adds a dirty region to a texture resource.
	hresult_t ( __stdcall * addDirtyRect )(
		d3d9_texture_t      * p,
		const d3d9_rect_t   * pDirtyRect );
#endif
}
d3d9_texture_vtbl_t;

//! The VTable of IDirect3DVolumeTexture9.
typedef struct D3D9_VOLUME_TEXTURE_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_volume_texture_t      * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_volume_texture_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_volume_texture_t * p );
#endif
#if 1 // IDirect3DResource9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_volume_texture_t  * p,
		d3d9_device_t         ** ppDevice );
	
	//! SetPrivateData associates data with the resource that is intended for
	//! use by the application, not by Direct3D. Data is passed by value, and
	//! multiple sets of data can be associated with a single resource.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_volume_texture_t * p,
		d3d9_refguid_t          refGUID,
		const void            * pData,
		u32                     sizeOfData,
		u32                     aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the resource to a provided buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_volume_texture_t * p,
		d3d9_refguid_t          refGUID,
		void                  * pData,
		u32                   * pSizeOfData );
	
	//! FreePrivateData frees the specified private data
	//! associated with this resource.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_volume_texture_t * p,
		d3d9_refguid_t          refguid );
	
	//! SetPriority assigns the priority of a resource for scheduling purposes.
	u32  ( __stdcall * setPriority )(
		d3d9_volume_texture_t * p,
		u32                     priorityNew );
	
	//! GetPriority retrieves the priority for this resource.
	u32  ( __stdcall * getPriority )(
		d3d9_volume_texture_t * p );
	
	//! PreLoad preloads a managed resource.
	void ( __stdcall * preLoad )(
		d3d9_volume_texture_t * p );
	
	//! GetType returns the type of the resource.
	d3d9_resourcetype_t ( __stdcall * getType )(
		d3d9_volume_texture_t * p );
#endif
#if 1 // IDirect3DBaseTexture9 functions
	//! SetLOD sets the most detailed level-of-detail for a managed texture.
	u32 ( __stdcall * setLOD )( d3d9_volume_texture_t * p, u32 v );
	
	//! Get a value clamped to the maximum level-of-detail set for a managed
	//! texture (this method is not supported for an unmanaged texture).
	u32 ( __stdcall * getLOD )( d3d9_volume_texture_t * p );
	
	//! Get the number of texture levels in a multilevel texture.
	u32 ( __stdcall * getLevelCount )( d3d9_volume_texture_t * p );
	
	//! SetAutoGenFilterType sets the filter type that is
	//! used for automatically generated mipmap sublevels.
	hresult_t ( __stdcall * setAutoGenFilterType )(
		d3d9_volume_texture_t    * p,
		d3d9_texturefiltertype_t   filterType );
	
	//! GetAutoGenFilterType returns the filter type that is
	//! used for automatically generated mipmap sublevels.
	d3d9_texturefiltertype_t ( __stdcall * getAutoGenFilterType )(
		d3d9_volume_texture_t * p );
	
	//! GenerateMipSubLevels generates mip sub levels.
	void ( __stdcall * generateMipSubLevels )( d3d9_texture_t * p );
#endif
#if 1 // IDirect3DVolumeTexture9 functions
	//! Retrieves a level description
	//! of a volume texture resource.
	hresult_t ( __stdcall * getLevelDesc )(
		d3d9_volume_texture_t      * p,
		u32                          aLevel,
		d3d9_volume_desc_t         * pDesc );
	
	//! GetVolumeLevel retrieves the specified volume texture level.
	//! Call Release on the returned volume when finished using it.
	hresult_t ( __stdcall * getVolumeLevel )(
		d3d9_volume_texture_t      * p,
		u32                          aLevel,
		d3d9_volume_t             ** ppVolumeLevel );
	
	//! LockBox locks a box on a volume texture resource.
	hresult_t ( __stdcall * lockBox )(
		d3d9_volume_texture_t      * p,
		u32                          aLevel,
		d3d9_locked_box_t          * pLockedVolume,
		const d3d9_box_t           * pBox,
		u32                          aFlags );
	
	//! UnlockBox unlocks a box on a volume texture resource.
	hresult_t ( __stdcall * unlockBox )(
		d3d9_volume_texture_t      * p,
		u32                          aLevel );
	
	//! AddDirtyBox adds a dirty region to a volume texture resource.
	hresult_t ( __stdcall * addDirtyBox )(
		d3d9_volume_texture_t      * p,
		const d3d9_rect_t          * pDirtyRect );
#endif
}
d3d9_volume_texture_vtbl_t;

//! The VTable of IDirect3DCubeTexture9.
typedef struct D3D9_CUBE_TEXTURE_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_cube_texture_t        * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_cube_texture_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_cube_texture_t * p );
#endif
#if 1 // IDirect3DResource9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_cube_texture_t    * p,
		d3d9_device_t         ** ppDevice );
	
	//! SetPrivateData associates data with the resource that is intended for
	//! use by the application, not by Direct3D. Data is passed by value, and
	//! multiple sets of data can be associated with a single resource.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_cube_texture_t   * p,
		d3d9_refguid_t          refGUID,
		const void            * pData,
		u32                     sizeOfData,
		u32                     aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the resource to a provided buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_cube_texture_t   * p,
		d3d9_refguid_t          refGUID,
		void                  * pData,
		u32                   * pSizeOfData );
	
	//! FreePrivateData frees the specified private data
	//! associated with this resource.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_cube_texture_t * p,
		d3d9_refguid_t        refguid );
	
	//! SetPriority assigns the priority of a resource for scheduling purposes.
	u32  ( __stdcall * setPriority )(
		d3d9_cube_texture_t * p,
		u32                   priorityNew );
	
	//! GetPriority retrieves the priority for this resource.
	u32  ( __stdcall * getPriority )(
		d3d9_cube_texture_t * p );
	
	//! PreLoad preloads a managed resource.
	void ( __stdcall * preLoad )(
		d3d9_cube_texture_t * p );
	
	//! GetType returns the type of the resource.
	d3d9_resourcetype_t ( __stdcall * getType )(
		d3d9_cube_texture_t * p );
#endif
#if 1 // IDirect3DBaseTexture9 functions
	//! SetLOD sets the most detailed level-of-detail for a managed texture.
	u32 ( __stdcall * setLOD )( d3d9_cube_texture_t * p, u32 v );
	
	//! Get a value clamped to the maximum level-of-detail set for a managed
	//! texture (this method is not supported for an unmanaged texture).
	u32 ( __stdcall * getLOD )( d3d9_cube_texture_t * p );
	
	//! Get the number of texture levels in a multilevel texture.
	u32 ( __stdcall * getLevelCount )( d3d9_cube_texture_t * p );
	
	//! SetAutoGenFilterType sets the filter type that is
	//! used for automatically generated mipmap sublevels.
	hresult_t ( __stdcall * setAutoGenFilterType )(
		d3d9_cube_texture_t      * p,
		d3d9_texturefiltertype_t   filterType );
	
	//! GetAutoGenFilterType returns the filter type that is
	//! used for automatically generated mipmap sublevels.
	d3d9_texturefiltertype_t ( __stdcall * getAutoGenFilterType )(
		d3d9_cube_texture_t * p );
	
	//! GenerateMipSubLevels generates mip sub levels.
	void ( __stdcall * generateMipSubLevels )( d3d9_texture_t * p );
#endif
#if 1 // IDirect3DCubeTexture9 functions
	//! GetLevelDesc retrieves a description of
	//! one face of the specified cube texture level.
	hresult_t ( __stdcall * getLevelDesc )(
		d3d9_cube_texture_t * p,
		u32                   aLevel,
		d3d9_surface_desc_t * pDesc );
	
	//! GetCubeMapSurface retrieves a cube texture map surface.
	hresult_t ( __stdcall * getCubeMapSurface )(
		d3d9_cube_texture_t * p,
		d3d9_cubemap_faces_t  faceType,
		u32                   aLevel,
		d3d9_surface_t     ** ppCubeMapSurface );
	
	//! LockRect locks a rectangle on a cube texture resource.
	hresult_t ( __stdcall * lockRect )(
		d3d9_cube_texture_t * p,
		d3d9_cubemap_faces_t  faceType,
		u32                   aLevel,
		d3d9_locked_rect_t  * pLockedRect,
		const d3d9_rect_t   * pRect,
		u32                   aFlags );
	
	//! UnlockRect unlocks a rectangle on a cube texture resource.
	hresult_t ( __stdcall * unlockRect )(
		d3d9_cube_texture_t * p,
		d3d9_cubemap_faces_t  faceType,
		u32                   aLevel );
	
	//! AddDirtyRect adds a dirty region to a cube texture resource.
	hresult_t ( __stdcall * addDirtyRect )(
		d3d9_cube_texture_t * p,
		d3d9_cubemap_faces_t  faceType,
		const d3d9_rect_t   * pDirtyRect );
#endif
}
d3d9_cube_texture_vtbl_t;

//! The VTable of IDirect3DVertexBuffer9.
typedef struct D3D9_VERTEX_BUFFER_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_vertex_buffer_t       * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_vertex_buffer_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_vertex_buffer_t * p );
#endif
#if 1 // IDirect3DResource9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_vertex_buffer_t   * p,
		d3d9_device_t         ** ppDevice );
	
	//! SetPrivateData associates data with the resource that is intended for
	//! use by the application, not by Direct3D. Data is passed by value, and
	//! multiple sets of data can be associated with a single resource.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_vertex_buffer_t  * p,
		d3d9_refguid_t          refGUID,
		const void            * pData,
		u32                     sizeOfData,
		u32                     aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the resource to a provided buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_vertex_buffer_t  * p,
		d3d9_refguid_t          refGUID,
		void                  * pData,
		u32                   * pSizeOfData );
	
	//! FreePrivateData frees the specified private data
	//! associated with this resource.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_vertex_buffer_t * p,
		d3d9_refguid_t         refguid );
	
	//! SetPriority assigns the priority of a resource for scheduling purposes.
	u32  ( __stdcall * setPriority )(
		d3d9_vertex_buffer_t * p,
		u32                    priorityNew );
	
	//! GetPriority retrieves the priority for this resource.
	u32  ( __stdcall * getPriority )(
		d3d9_vertex_buffer_t * p );
	
	//! PreLoad preloads a managed resource.
	void ( __stdcall * preLoad )(
		d3d9_vertex_buffer_t * p );
	
	//! GetType returns the type of the resource.
	d3d9_resourcetype_t ( __stdcall * getType )(
		d3d9_vertex_buffer_t * p );
#endif
#if 1 // IDirect3DVertexBuffer9 functions
	//! Lock locks a range of vertex data and obtains
	//! a pointer to the vertex buffer memory.
	hresult_t ( __stdcall * lock )(
		d3d9_vertex_buffer_t * p,
		u32                    offsetToLock,
		u32                    sizeToLock,
		void                ** ppbData,
		u32                    aFlags );
	
	//! Unlock unlocks vertex data.
	hresult_t ( __stdcall * unlock )(
		d3d9_vertex_buffer_t   * p );
	
	//! GetDesc retrieves a description of the vertex buffer resource.
	hresult_t ( __stdcall * getDesc )(
		d3d9_vertex_buffer_t     * p,
		d3d9_vertexbuffer_desc_t * pDesc );
#endif
}
d3d9_vertex_buffer_vtbl_t;

//! The VTable of IDirect3DIndexBuffer9.
typedef struct D3D9_INDEX_BUFFER_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_index_buffer_t        * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_index_buffer_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_index_buffer_t * p );
#endif
#if 1 // IDirect3DResource9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_index_buffer_t    * p,
		d3d9_device_t         ** ppDevice );
	
	//! SetPrivateData associates data with the resource that is intended for
	//! use by the application, not by Direct3D. Data is passed by value, and
	//! multiple sets of data can be associated with a single resource.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_index_buffer_t   * p,
		d3d9_refguid_t          refGUID,
		const void            * pData,
		u32                     sizeOfData,
		u32                     aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the resource to a provided buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_index_buffer_t   * p,
		d3d9_refguid_t          refGUID,
		void                  * pData,
		u32                   * pSizeOfData );
	
	//! FreePrivateData frees the specified private data
	//! associated with this resource.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_index_buffer_t  * p,
		d3d9_refguid_t         refguid );
	
	//! SetPriority assigns the priority of a resource for scheduling purposes.
	u32  ( __stdcall * setPriority )(
		d3d9_index_buffer_t  * p,
		u32                    priorityNew );
	
	//! GetPriority retrieves the priority for this resource.
	u32  ( __stdcall * getPriority )(
		d3d9_index_buffer_t * p );
	
	//! PreLoad preloads a managed resource.
	void ( __stdcall * preLoad )(
		d3d9_index_buffer_t * p );
	
	//! GetType returns the type of the resource.
	d3d9_resourcetype_t ( __stdcall * getType )(
		d3d9_index_buffer_t * p );
#endif
#if 1 // IDirect3DIndexBuffer9 functions
	//! Lock locks a range of index data and obtains
	//! a pointer to the index buffer memory.
	hresult_t ( __stdcall * lock )(
		d3d9_index_buffer_t * p,
		u32                    offsetToLock,
		u32                    sizeToLock,
		void                ** ppbData,
		u32                    aFlags );
	
	//! Unlock unlocks index data.
	hresult_t ( __stdcall * unlock )(
		d3d9_index_buffer_t   * p );
	
	//! GetDesc retrieves a description of the index buffer resource.
	hresult_t ( __stdcall * getDesc )(
		d3d9_index_buffer_t     * p,
		d3d9_indexbuffer_desc_t * pDesc );
#endif
}
d3d9_index_buffer_vtbl_t;

//! The VTable of IDirect3DSurface9.
typedef struct D3D9_SURFACE_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_surface_t             * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_surface_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_surface_t * p );
#endif
#if 1 // IDirect3DResource9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t( __stdcall * getDevice )(
		d3d9_surface_t         * p,
		d3d9_device_t         ** ppDevice );
	
	//! SetPrivateData associates data with the resource that is intended for
	//! use by the application, not by Direct3D. Data is passed by value, and
	//! multiple sets of data can be associated with a single resource.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_surface_t        * p,
		d3d9_refguid_t          refGUID,
		const void            * pData,
		u32                     sizeOfData,
		u32                     aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the resource to a provided buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_surface_t        * p,
		d3d9_refguid_t          refGUID,
		void                  * pData,
		u32                   * pSizeOfData );
	
	//! FreePrivateData frees the specified private data
	//! associated with this resource.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_surface_t       * p,
		d3d9_refguid_t         refguid );
	
	//! SetPriority assigns the priority of a resource for scheduling purposes.
	u32  ( __stdcall * setPriority )(
		d3d9_surface_t       * p,
		u32                    priorityNew );
	
	//! GetPriority retrieves the priority for this resource.
	u32  ( __stdcall * getPriority )(
		d3d9_surface_t * p );
	
	//! PreLoad preloads a managed resource.
	void ( __stdcall * preLoad )(
		d3d9_surface_t * p );
	
	//! GetType returns the type of the resource.
	d3d9_resourcetype_t ( __stdcall * getType )(
		d3d9_surface_t * p );
#endif
#if 1 // IDirect3DSurface9 functions
	//! GetContainer provides access to the parent resource.
	hresult_t ( __stdcall * getContainer )(
		d3d9_surface_t * p,
		d3d9_guid_t    * riid,
		void          ** ppContainer );
	
	//! GetDesc retrieves a description of the surface.
	hresult_t ( __stdcall * getDesc )(
		d3d9_surface_t      * p,
		d3d9_surface_desc_t * pDesc );
	
	//! LockRect locks a rectangle on a surface.
	hresult_t ( __stdcall * lockRect )(
		d3d9_surface_t     * p,
		d3d9_locked_rect_t * pLockedRect,
		const d3d9_rect_t  * pRect,
		u32                  aFlags );
	
	//! UnlockRect unlocks a rectangle on a surface.
	hresult_t ( __stdcall * unlockRect )(
		d3d9_surface_t * p );
	
	//! GetDC retrieves a device context.
	hresult_t ( __stdcall * getDC )(
		d3d9_surface_t * p,
		hdc_t          * phdc );
	
	//! ReleaseDC releases a device context handle.
	hresult_t ( __stdcall * releaseDC )(
		d3d9_surface_t * p,
		hdc_t            hdc );
#endif
}
d3d9_surface_vtbl_t;

//! The VTable of IDirect3DVolume9.
typedef struct D3D9_VOLUME_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_volume_t              * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_volume_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_volume_t * p );
#endif
#if 1 // IDirect3DVolume9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t ( __stdcall * getDevice )(
		d3d9_volume_t     * p,
		d3d9_device_t    ** ppDevice );
	
	//! SetPrivateData associates data with the volume that is
	//! intended for use by the application, not by Direct3D.
	hresult_t ( __stdcall * setPrivateData )(
		d3d9_volume_t     * p,
		d3d9_refguid_t      refGUID,
		const void        * pData,
		u32                 sizeOfData,
		u32                 aFlags );
	
	//! GetPrivateData copies the private data
	//! associated with the volume to a buffer.
	hresult_t ( __stdcall * getPrivateData )(
		d3d9_volume_t     * p,
		d3d9_refguid_t      refGUID,
		void              * pData,
		u32               * pSizeOfData );
	
	//! Frees the specified private data associated with this volume.
	hresult_t ( __stdcall * freePrivateData )(
		d3d9_volume_t     * p,
		d3d9_refguid_t      refguid );
	
	//! GetContainer provides access to the parent volume texture object,
	//! if this surface is a child level of a volume texture.
	//! Call Release on the returned volume texture when finished using it.
	hresult_t ( __stdcall * getContainer )(
		d3d9_volume_t     * p,
		d3d9_guid_t       * riid,
		void   ** ppContainer );
	
	//! GetDesc retrieves a description of the volume.
	hresult_t ( __stdcall * getDesc )(
		d3d9_volume_t      * p,
		d3d9_volume_desc_t * pDesc );
	
	//! LockBox locks a box on a volume resource.
	hresult_t ( __stdcall * lockBox )(
		d3d9_volume_t     * p,
		d3d9_locked_box_t * pLockedVolume,
		const d3d9_box_t  * pBox,
		u32                 aFlags );
	
	//! UnlockBox unlocks a box on a volume resource.
	hresult_t ( __stdcall * unlockBox )( d3d9_volume_t * p );
#endif
}
d3d9_volume_vtbl_t;

//! The VTable of IDirect3DQuery9.
typedef struct D3D9_QUERY_VTBL_T
{
#if 1 // IUnknown functions
	//! IUnknown method that is never used.
	hresult_t ( __stdcall * queryInterface )(
		d3d9_query_t               * p,
		d3d9_guid_t                * riid,
		void                      ** ppvObj );
	
	//! (IUnknown) Increments the refcount for an interface on an object.
	//! This method should be called for every new copy
	//! of a pointer to an interface on an object.
	u32 ( __stdcall * addRef  )( d3d9_query_t * p );
	
	//! (IUnknown) Release has to be called when finished
	//! using the object to free its associated resources.
	u32 ( __stdcall * release )( d3d9_query_t * p );
#endif
#if 1 // IDirect3DQuery9 functions
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t ( __stdcall * getDevice )(
		d3d9_query_t              * p,
		d3d9_device_t            ** ppDevice );
	
	//! Get the query type.
	d3d9_querytype_t ( __stdcall * getType )(
		d3d9_query_t              * p );
	
	//! Get the number of bytes in the query data.
	u32 ( __stdcall * getDataSize )( d3d9_query_t * p );
	
	//! Issue a query.
	hresult_t ( __stdcall * issue   )( d3d9_query_t * p, u32 dwIssueFlags );
	
	//! Poll a queried resource to get the query state or a query result.
	hresult_t ( __stdcall * getData )(
		d3d9_query_t              * p,
		void                      * pData,
		u32                         dwSize,
		u32                         dwGetDataFlags );
#endif
}
d3d9_query_vtbl_t;


//-----------------------------------------------------------------------------
// THIS IS A STAGING AREA FOR A FUTURE V-TABLE, ALTHOUGH THAT MAY BE UNLIKELY.
//-----------------------------------------------------------------------------
#if 0

/*
#define STDMETHOD(method)       HRESULT (STDMETHODCALLTYPE * method)
#define STDMETHOD_(type,method) type (STDMETHODCALLTYPE * method)
#define STDMETHODCALLTYPE       __stdcall
#define THIS_                   INTERFACE FAR* This,
#define THIS                    INTERFACE FAR* This
#define REFIID                  const IID * __MIDL_CONST
#define REFGUID                 const GUID * __MIDL_CONST
#define __MIDL_CONST            const
typedef __success(return >= 0) long HRESULT;
*/
#undef INTERFACE
#define INTERFACE IDirect3DPixelShader9

//! The VTable of .
typedef struct D3D9____VTBL_T
{
	//! [!> EXAMPLE FUNCTION <!]
	//! GetDevice retrieves the associated device.
	//! Call Release on the returned device when finished using it.
	hresult_t ( __stdcall * getDevice )(
		d3d9_state_block_t * p,
		d3d9_device_t     ** ppDevice );
}
d3d9____vtbl_t;

#endif
//-----------------------------------------------------------------------------


#endif /* HEADER_D3D9VTBL_H_ */


