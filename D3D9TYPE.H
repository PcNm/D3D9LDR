/*
 * D3D9TYPE.H : Types For Direct3D9, Version 9.0c.
 *
 *  Created on: 23 sep. 2019
 *      Author: Martin Andreasson
 */

#ifndef HEADER_D3D9TYPE_H_
#define HEADER_D3D9TYPE_H_

#include "ENGINE/DIRECT3D/D3D9ENUM.H"


#ifndef WIN32_API_TYPES
#define WIN32_API_TYPES
typedef s32      hresult_t  ;//!< Error Value returned by most D3D9 calls
typedef hf_addr  handle_t   ;//!< A uintptr type used as a handle in D3D9
typedef hf_addr  hwnd_t     ;//!< A window handle
typedef hf_addr  hmonitor_t ;//!< A monitor handle
typedef hf_addr  hdc_t      ;//!< A device context handle
#endif // WIN32_API_TYPES


//! a globally unique identifier
typedef struct D3D9_GUID_T
{
	u32 data1      ;//!< ?
	u16 data2      ;//!< ?
	u16 data3      ;//!< ?
	u08 data4[ 8 ] ;//!< ?
}
d3d9_guid_t; //<! a globally unique identifier

//! A d3d9_refguid_t represents a REFGUID type (a D3D9 parameter type)
typedef const d3d9_guid_t * const d3d9_refguid_t;


//! LUID is a 64-bit value guaranteed to be unique only on the system
//! on which it was generated. The uniqueness of a locally unique
//! identifier (LUID) is guaranteed only until the system is restarted
typedef struct D3D9_LUID_T
{
	u32 LowPart  ;//!< Low Part
	s32 HighPart ;//!< High Part
}
d3d9_luid_t; //!< A "Locally Unique Identifier" (O'RLY ?)

//! A d3d9_refiid_t represents a REFIID type (const IID *const)
//! This is an "interface identifier" gimmick used in win32api.
//typedef const d3d9_luid_t * const d3d9_refiid_t;


//! defines a range
typedef struct D3D9_RANGE_T
{
	u32 Offset ;//!< Offset
	u32 Size   ;//!< Size
}
d3d9_range_t; //!< defines a range


//! describes a 2D point
typedef struct D3D9_POINT_T
{
	s32 x; //!< X
	s32 y; //!< Y
}
d3d9_point_t; //!< describes a 2D point


//! defines a 3D vector
typedef struct D3D9_VECTOR_T
{
	f32 x; //!< X
	f32 y; //!< Y
	f32 z; //!< Z
}
d3d9_vector_t; //!< defines a 3D vector


//! describes a matrix
typedef f32 d3d9_matrix_t[ 16 ];


//! defines window dimensions of a render-target
//! surface onto which a 3D volume projects...
typedef struct D3D9_VIEWPORT_T
{
	u32 x      ; //!< X
	u32 y      ; //!< Y
	u32 width  ; //!< Width
	u32 height ; //!< Height
	f32 minz   ; //!< Min Z
	f32 maxz   ; //!< Max Z
}
d3d9_viewport_t; //!< Dimensions of RT Surface, onto which, shit is projected.


//! describes the current clip status
typedef struct D3D9_CLIPSTATUS_T
{
	u32 clipUnion        ;//!< Clip Union
	u32 clipIntersection ;//!< Clip Intersection
}
d3d9_clipstatus_t; //!< describes the current clip status


//! specifies the color and usage of an entry in a logical palette
typedef struct D3D9_PALETTEENTRY_T
{
	u08 peRed   ; //!< Byte
	u08 peGreen ; //!< Byte
	u08 peBlue  ; //!< Byte
	u08 peFlags ; //!< Byte
}
d3d9_paletteentry_t ; //!< color and usage of an entry in a logical palette


//! Helps define the vertex data layout. (Each vertex can contain one or
//! more data types, and each data type is described by a vertex element)
typedef struct D3D9_VERTEXELEMENT_T
{
	/**
	 * Stream number that this element resides in.
	 */
	u16               stream     ;
	
	/**
	 * Offset from the beginning of the vertex data.
	 * Get this by adding up the size of the types defined before this element.
	 */
	u16               offset     ;
	
	/**
	 * The data type (i.e. D3DDECLTYPE_FLOAT3 a.k.a. e_d3d9_decltype_float3).
	 */
	d3d9_decltype_t   type       ;
	
	/**
	 * Method. Use D3DDECLMETHOD_DEFAULT here. (e_d3d9_declmethod_default ?)
	 */
	d3d9_declmethod_t method     ;
	
	/**
	 * Defines what the data will be used for
	 * (this is the semantic in your shader - ie D3DDECLUSAGE_POSITION)
	 * 
	 * (D3DDECLUSAGE_TEXCOORD a.k.a. e_d3d9_declusage_texcoord) can be used
	 * for user-defined fields (which don't have an existing usage defined)
	 * 
	 */
	d3d9_declusage_t  usage      ;
	
	/**
	 * Usage Index
	 * 
	 * Modifies the usage data to allow the
	 * user to specify multiple usage types.
	 */
	u08               usageIndex ;
}
d3d9_vertexelement_t; //!< describes an element of a vertex buffer layout


//! describes color values
typedef struct D3D9_COLORVALUE_T
{
	f32 r ;//!<	Red
	f32 g ;//!<	Green
	f32 b ;//!<	Blue
	f32 a ;//!<	Alpha
}
d3d9_colorvalue_t; //!< describes color values


//! specifies material properties
typedef struct D3D9_MATERIAL_T
{
	d3d9_colorvalue_t diffuse  ;//!< Diffuse
	d3d9_colorvalue_t ambient  ;//!< Ambient
	d3d9_colorvalue_t specular ;//!< Specular
	d3d9_colorvalue_t emissive ;//!< Emissive
	f32               power    ;//!< Power
}
d3d9_material_t; //!< specifies material properties


//! defines a set of lighting properties
typedef struct D3D9_LIGHT_T
{
	d3d9_lighttype_t  type         ;//!< Type
	d3d9_colorvalue_t diffuse      ;//!< Diffuse
	d3d9_colorvalue_t specular     ;//!< Specular
	d3d9_colorvalue_t ambient      ;//!< Ambient
	d3d9_vector_t     position     ;//!< Position
	d3d9_vector_t     direction    ;//!< Direction
	f32               range        ;//!< Range
	f32               falloff      ;//!< Falloff
	f32               attenuation0 ;//!< Attenuation0
	f32               attenuation1 ;//!< Attenuation1
	f32               attenuation2 ;//!< Attenuation2
	f32               theta        ;//!< Theta
	f32               phi          ;//!< Phi
}
d3d9_light_t; //!< defines a set of lighting properties


//! describes a rectangle
typedef struct D3D9_RECT_T
{
	s32 left   ;//!< Left
	s32 top    ;//!< Top
	s32 right  ;//!< Right
	s32 bottom ;//!< Bottom
}
d3d9_rect_t; //!< describes a rectangle


//! describes a locked rectangular region
typedef struct D3D9_LOCKED_RECT_T
{
	s32     pitch ;//!< Pitch
	hf_addr pBits ;//!< P-Bits
}
d3d9_locked_rect_t; //!< describes a locked rectangular region


//! defines a volume
typedef struct D3D9_BOX_T
{
	u32 left   ;//!< Left  
	u32 top    ;//!< Top   
	u32 right  ;//!< Right 
	u32 bottom ;//!< Bottom
	u32 front  ;//!< Front 
	u32 back   ;//!< Back  
}
d3d9_box_t; //!< defines a volume


//! describes a locked box (volume)
typedef struct D3D9_LOCKED_BOX_T
{
	s32        rowPitch   ;//!< Row Pitch
	s32        slicePitch ;//!< Slice Pitch
	hf_addr    pBits      ;//!< P-Bits
}
d3d9_locked_box_t; //!< describes a locked box (volume)


//! describes a vertex buffer
typedef struct D3D9_VERTEXBUFFER_DESC_T
{
	d3d9_format_t       format ;//!< Format
	d3d9_resourcetype_t type   ;//!< Resource Type
	u32                 usage  ;//!< Usage
	d3d9_pool_t         pool   ;//!< Pool
	u32                 size   ;//!< Size
	u32                 fvf    ;//!< FVF
}
d3d9_vertexbuffer_desc_t; //!< describes a vertex buffer


//! describes an index buffer
typedef struct D3D9_INDEXBUFFER_DESC_T
{
	d3d9_format_t       format ;//!< Format
	d3d9_resourcetype_t type   ;//!< Resource Type
	u32                 usage  ;//!< Usage
	d3d9_pool_t         pool   ;//!< Pool
	u32                 size   ;//!< Size
}
d3d9_indexbuffer_desc_t; //!< describes an index buffer


//! describes a surface
typedef struct D3D9_SURFACE_DESC_T
{
	d3d9_format_t           format             ;//!< Format
	d3d9_resourcetype_t     type               ;//!< Resource Type
	u32                     usage              ;//!< Usage
	d3d9_pool_t             pool               ;//!< Pool
	d3d9_multisample_type_t multiSampleType    ;//!< Multisample Type
	u32                     multiSampleQuality ;//!< Multisample Quality
	u32                     width              ;//!< Width
	u32                     height             ;//!< Height
}
d3d9_surface_desc_t; //!< describes a surface


//! describes a volume
typedef struct D3D9_VOLUME_DESC_T
{
	d3d9_format_t       format ;//!< Format
	d3d9_resourcetype_t type   ;//!< Type  
	u32                 usage  ;//!< Usage 
	d3d9_pool_t         pool   ;//!< Pool  
	u32                 width  ;//!< Width 
	u32                 height ;//!< Height
	u32                 depth  ;//!< Depth 
}
d3d9_volume_desc_t;


//! describes a rectangular high-order patch
typedef struct D3D9_RECTPATCH_INFO_T
{
	u32               startVertexOffsetWidth  ;//!< Start Vertex Offset Width
	u32               startVertexOffsetHeight ;//!< Start Vertex Offset Height
	u32               width                   ;//!< Width
	u32               height                  ;//!< Height
	u32               stride                  ;//!< Stride
	d3d9_basistype_t  basis                   ;//!< Basis
	d3d9_degreetype_t degree                  ;//!< Degree
}
d3d9_rectpatch_info_t; //!< describes a rectangular high-order patch


//! describes a triangular high-order patch
typedef struct D3D9_TRIPATCH_INFO_T
{
	u32               startVertexOffset ;//!< Start Vertex Offset
	u32               numVertices       ;//!< Number of vertices
	d3d9_basistype_t  basis             ;//!< Basis
	d3d9_degreetype_t degree            ;//!< Degree
}
d3d9_tripatch_info_t; //!< describes a triangular high-order patch


//! describes region data
typedef struct D3D9_RGNDATAHEADER_T
{
	u32         dwSize   ;//!< ?
	u32         iType    ;//!< ?
	u32         nCount   ;//!< ?
	u32         nRgnSize ;//!< ?
	d3d9_rect_t rcBound  ;//!< ?
}
d3d9_rgndataheader_t; //!< describes region data


//! contains region data
typedef struct D3D9_RGNDATA_T
{
	d3d9_rgndataheader_t rdh       ;//!< Header
	u08                  buffer[1] ;//!< Buffer
}
d3d9_rgndata_t; //!< contains region data


//! contains red, green, and blue ramp data
typedef struct D3D9_GAMMARAMP_T
{
	u16 red   [256] ;//!< Red
	u16 green [256] ;//!< Green
	u16 blue  [256] ;//!< Blue
}
d3d9_gammaramp_t; //!< contains red, green, and blue ramp data


//! a display mode
typedef struct D3D9_DISPLAYMODE_T
{
	u32           width       ;//!< ?
	u32           height      ;//!< ?
	u32           refreshRate ;//!< ?
	d3d9_format_t format      ;//!< ?
}
d3d9_displaymode_t; //!< a display mode


//! contains throughput metrics for help in
//! understanding the performance of an app
typedef struct D3D9_DEVINFO_D3D9BANDWIDTHTIMINGS_T
{
	f32 maxBandwidthUtilized                ;//!< Bandwidth
	f32 frontEndUploadMemoryUtilizedPercent ;//!< Frontend Upload
	f32 vertexRateUtilizedPercent           ;//!< Vertexrate
	f32 triangleSetupRateUtilizedPercent    ;//!< Triangle Setuprate
	f32 fillRateUtilizedPercent             ;//!< Fillrate
}
d3d9_devinfo_d3d9bandwidthtimings_t; //!< performance of a d3d9 application...


//! measure cache hit rate performance
//! for textures and indexed vertices
typedef struct D3D9_DEVINFO_D3D9CACHEUTILIZATION_T
{
	f32 textureCacheHitRate            ;//!< Texture Cache Hit Rate
	f32 postTransformVertexCacheHitRate;//!< Post-Xform Vertex Cache Hit Rate
}
d3d9_devinfo_d3d9cacheutilization_t; //!< performance of a d3d9 application...


//! contains the percent of time processing data
//! in the driver.  These statistics may help identify
//! cases when the driver is waiting for other resources
typedef struct D3D9_DEVINFO_D3D9INTERFACETIMINGS_T
{
	f32 waitingForGPUToUseApplicationResourceTimePercent ;//!< 
	f32 waitingForGPUToAcceptMoreCommandsTimePercent     ;//!< 
	f32 waitingForGPUToStayWithinLatencyTimePercent      ;//!< 
	f32 waitingForGPUExclusiveResourceTimePercent        ;//!< 
	f32 waitingForGPUOtherTimePercent                    ;//!< 
}
d3d9_devinfo_d3d9interfacetimings_t; //!< D3D9 Driver interface timings


//! contains the percent of time processing data in the pipeline
typedef struct D3D9_DEVINFO_D3D9PIPELINETIMINGS_T
{
	f32 vertexProcessingTimePercent   ;//!< Vertex Processing
	f32 pixelProcessingTimePercent    ;//!< Pixel Processing
	f32 otherGPUProcessingTimePercent ;//!< Other Processing (GPU)
	f32 gpuIdleTimePercent            ;//!< GPU Idle
}
d3d9_devinfo_d3d9pipelinetimings_t; //!< portion spent processing the pipeline


//! reports the number of triangles that have been processed
//! and clipped by the runtime's software vertex processing
typedef struct D3D9_DEVINFO_D3DVERTEXSTATS_T
{
	u32 numRenderedTriangles      ;//!< Number of rendered triangles
	u32 numExtraClippingTriangles ;//!< Number of extra clipping triangles
}
d3d9_devinfo_d3dvertexstats_t; //!< triangles processed & clipped by software


//! contains the percent of time spent processing shader data
typedef struct D3D9_DEVINFO_D3D9STAGETIMINGS_T
{
	f32 memoryProcessingPercent      ;//!< Memory
	f32 computationProcessingPercent ;//!< Computation
}
d3d9_devinfo_d3d9stagetimings_t; //!< percent of time processing shader data


//! contains vertex cache optimization hints
typedef struct D3D9_DEVINFO_VCACHE_T
{
	u32 pattern     ;//!< Pattern    
	u32 optMethod   ;//!< Method  
	u32 cacheSize   ;//!< Cache Size  
	u32 magicNumber ;//!< Magic Number
}
d3d9_devinfo_vcache_t; //!< contains vertex cache optimization hints


//! contains resource statistics gathered by "DEVINFO_ResourceManager"
//! when using the asynchronous query mechanism
typedef struct D3D9_RESOURCESTATS_T
{
	u32 bThrashing            ;//!< 
	u32 approxBytesDownloaded ;//!< 
	u32 numEvicts             ;//!< 
	u32 numVidCreates         ;//!< 
	u32 lastPri               ;//!< 
	u32 numUsed               ;//!< 
	u32 numUsedInVidMem       ;//!< 
	u32 workingSet            ;//!< 
	u32 workingSetBytes       ;//!< 
	u32 totalManaged          ;//!< 
	u32 totalBytes            ;//!< 
}
d3d9_resourcestats_t; //!< asynchronous query mechanism resource statistics


//! describes creation params for a device
typedef struct D3D9_DEVICE_CREATION_PARAMETERS_T
{
	u32            adapterOrdinal ;//!< Adapter Ordinal
	d3d9_devtype_t deviceType     ;//!< Device Type
	hwnd_t         hFocusWindow   ;//!< ?
	u32            behaviorFlags  ;//!< Behavior Flags
}
d3d9_device_creation_parameters_t; //!< describes creation params for a device


//! contains information identifying the adapter
typedef struct D3D9_ADAPTER_IDENTIFIER_T
{
	//! Driver
	u08         driver      [ D3D9_MAX_DEVICE_IDENTIFIER_STRING ] ;

	//! Description
	u08         description [ D3D9_MAX_DEVICE_IDENTIFIER_STRING ] ;

	u08         deviceName  [ 32 ] ;//!< Device Name
	s64         driverVersion      ;//!< Driver Version
	u32         vendorId           ;//!< Vendor Id
	u32         deviceId           ;//!< Device Id
	u32         subSysId           ;//!< SubSys Id
	u32         revision           ;//!< Revision
	d3d9_guid_t deviceIdentifier   ;//!< Device Identifier
	u32         whqlLevel          ;//!< WHQL Level
}
d3d9_adapter_identifier_t; //!< contains information identifying the adapter


//! describes vertex shader caps
typedef struct D3D9_VSHADERCAPS20_T
{
	u32 caps                    ;//!< ?
	s32 dynamicFlowControlDepth ;//!< ?
	s32 numTemps                ;//!< ?
	s32 staticFlowControlDepth  ;//!< ?
}
d3d9_vshadercaps20_t; //!< describes vertex shader caps


//! describes pixel shader caps
typedef struct D3D9_PSHADERCAPS20_T
{
	u32 caps                    ;//!< ?
	s32 dynamicFlowControlDepth ;//!< ?
	s32 numTemps                ;//!< ?
	s32 staticFlowControlDepth  ;//!< ?
	s32 numInstructionSlots     ;//!< ?
}
d3d9_pshadercaps20_t; //!< describes pixel shader caps


//! PRESENT_PARAMETERS describes the presentation parameters.
typedef struct D3D9_PRESENT_PARAMETERS_T
{
u32                     backBufferWidth            ;//!< ?
u32                     backBufferHeight           ;//!< ?
d3d9_format_t           backBufferFormat           ;//!< ?
u32                     backBufferCount            ;//!< ?
d3d9_multisample_type_t multiSampleType            ;//!< ?
u32                     multiSampleQuality         ;//!< ?
d3d9_swapeffect_t       swapEffect                 ;//!< ?
hwnd_t                  hDeviceWindow              ;//!< ?
s32                     windowed                   ;//!< ?
s32                     enableAutoDepthStencil     ;//!< ?
d3d9_format_t           autoDepthStencilFormat     ;//!< ?
u32                     flags                      ;//!< ?
u32                     fullScreen_RefreshRateInHz ;//!< ?
u32                     presentationInterval       ;//!< ?
}
d3d9_present_parameters_t;


//! describes the raster status.
typedef struct D3D9_RASTER_STATUS_T
{
	s32 inVBlank ;//!< ? In VBlank
	u32 scanLine ;//!< ? Scan-Line
}
d3d9_raster_status_t;


//! CAPS represents the capabilities of the
//! HW exposed through the Direct3D object.
typedef struct D3D9_CAPS_T
{
	d3d9_devtype_t       deviceType                        ;
	u32                  adapterOrdinal                    ;
	u32                  caps                              ;
	u32                  caps2                             ;
	u32                  caps3                             ;
	u32                  presentationIntervals             ;
	u32                  cursorCaps                        ;
	u32                  devCaps                           ;
	u32                  primitiveMiscCaps                 ;
	u32                  rasterCaps                        ;
	u32                  zCmpCaps                          ;
	u32                  srcBlendCaps                      ;
	u32                  destBlendCaps                     ;
	u32                  alphaCmpCaps                      ;
	u32                  shadeCaps                         ;
	u32                  textureCaps                       ;
	u32                  textureFilterCaps                 ;
	u32                  cubeTextureFilterCaps             ;
	u32                  volumeTextureFilterCaps           ;
	u32                  textureAddressCaps                ;
	u32                  volumeTextureAddressCaps          ;
	u32                  lineCaps                          ;
	u32                  maxTextureWidth                   ;
	u32                  maxTextureHeight                  ;
	u32                  maxVolumeExtent                   ;
	u32                  maxTextureRepeat                  ;
	u32                  maxTextureAspectRatio             ;
	u32                  maxAnisotropy                     ;
	f32                  maxVertexW                        ;
	f32                  guardBandLeft                     ;
	f32                  guardBandTop                      ;
	f32                  guardBandRight                    ;
	f32                  guardBandBottom                   ;
	f32                  extentsAdjust                     ;
	u32                  stencilCaps                       ;
	u32                  fVFCaps                           ;
	u32                  textureOpCaps                     ;
	u32                  maxTextureBlendStages             ;
	u32                  maxSimultaneousTextures           ;
	u32                  vertexProcessingCaps              ;
	u32                  maxActiveLights                   ;
	u32                  maxUserClipPlanes                 ;
	u32                  maxVertexBlendMatrices            ;
	u32                  maxVertexBlendMatrixIndex         ;
	f32                  maxPointSize                      ;
	u32                  maxPrimitiveCount                 ;
	u32                  maxVertexIndex                    ;
	u32                  maxStreams                        ;
	u32                  maxStreamStride                   ;
	u32                  vertexShaderVersion               ;
	u32                  maxVertexShaderConst              ;
	u32                  pixelShaderVersion                ;
	f32                  pixelShader1xMaxValue             ;
	u32                  devCaps2                          ;
	u32                  masterAdapterOrdinal              ;
	u32                  adapterOrdinalInGroup             ;
	u32                  numberOfAdaptersInGroup           ;
	u32                  declTypes                         ;
	u32                  numSimultaneousRTs                ;
	u32                  stretchRectFilterCaps             ;
	d3d9_vshadercaps20_t vS20Caps                          ;
	d3d9_pshadercaps20_t pS20Caps                          ;
	u32                  vertexTextureFilterCaps           ;
	u32                  maxVShaderInstructionsExecuted    ;
	u32                  maxPShaderInstructionsExecuted    ;
	u32                  maxVertexShader30InstructionSlots ;
	u32                  maxPixelShader30InstructionSlots  ;
}
d3d9_caps_t;


//! COLOR represents a color with red, green, blue and alpha
//! channels, 8 bits each, in a 32 bit unsigned integer.
typedef u32 d3d9_color_t;


#endif /* HEADER_D3D9TYPE_H_ */


