/*
 * D3D9ENUM.H : Enumerations of Direct3D9, Version 9.0c.
 *
 * Created on: 22 sep 2019
 * Updated on: 10 may 2020
 *     Author: Martin Andreasson
 *    Version: 1.0
 *    License: Mozilla Public License Version 2.0
 */

#ifndef HEADER_D3D9ENUM_H_
#define HEADER_D3D9ENUM_H_

#include "HARDFORM.H"

enum d3d9_e
{
	//! SDK_VERSION must be used as the argument to Create.
	D3D9_SDK_VERSION = 32,

	//! ADAPTER_DEFAULT is used to specify the primary display adapter.
	D3D9_ADAPTER_DEFAULT = 0,

	//! DP_MAXTEXCOORD is the maximum number of texture coordinates.
	D3D9_DP_MAXTEXCOORD = 8,

	//! DMAPSAMPLER is 256, which is the maximum number of texture samplers.
	D3D9_DMAPSAMPLER = 256,
};
enum d3d9_max_e
{
	D3D9_MAX_DEVICE_IDENTIFIER_STRING = 512, //!< Device identifier string

	//! MAX_SIMULTANEOUS_RENDERTARGETS is the maximum number of rendertargets.
	D3D9_MAX_SIMULTANEOUS_RENDERTARGETS = 4,

	//! MAXD3DDECLLENGTH is the maximum number of elements in a vertex
	//! declaration (does not include "end" marker vertex element).
	D3D9_MAXD3DDECLLENGTH = 64, /* +end marker */

	//! MAXD3DDECLUSAGEINDEX is the maximum index (0-15)
	//! that can be used in a vertex declaration.
	D3D9_MAXD3DDECLUSAGEINDEX = 15,
};
enum d3d9_caps_e
{
	//! CAPS_READ_SCANLINE means the display hardware
	//! is capable of returning the current scan line.
	D3D9_CAPS_READ_SCANLINE = 0x20000,
};
enum d3d9_caps2_e
{
	//! CAPS2_CANAUTOGENMIPMAP indicates that the driver
	//! is capable of automatically generating mipmaps.
	D3D9_CAPS2_CANAUTOGENMIPMAP = 0x40000000,

	//! CAPS2_CANCALIBRATEGAMMA indicates that the system has a calibrator
	//! installed that can automatically adjust the gamma ramp so that the
	//! result is identical on all systems that have a calibrator. To invoke
	//! the calibrator when setting new gamma levels, use the SGR_CALIBRATE
	//! flag when calling SetGammaRamp. Calibrating gamma ramps incurs some
	//! processing overhead and should not be used frequently.
	D3D9_CAPS2_CANCALIBRATEGAMMA = 0x00100000,

	//! CAPS2_CANMANAGERESOURCE indicates that the driver
	//! is capable of managing resources. On such drivers,
	//! POOL_MANAGED resources will be managed by the driver. To have D3D
	//! override the driver so that Direct3D manages resources, use the
	//! CREATE_DISABLE_DRIVER_MANAGEMENT flag when calling CreateDevice.
	D3D9_CAPS2_CANMANAGERESOURCE = 0x10000000,

	//! CAPS2_DYNAMICTEXTURES indicates that
	//! the driver supports dynamic textures
	D3D9_CAPS2_DYNAMICTEXTURES = 0x20000000,

	//! CAPS2_FULLSCREENGAMMA indicates that the driver supports
	//! dynamic gamma ramp adjustment in full-screen mode.
	D3D9_CAPS2_FULLSCREENGAMMA = 0x00020000,
};
enum d3d9_caps3_e
{
	//! CAPS3_ALPHA_FULLSCREEN_FLIP_OR_DISCARD indicates that the device can
	//! respect the RS_ALPHABLENDENABLE render state in full-screen mode while
	//! using the FLIP or DISCARD swap effect. This only applies when the
	//! RS_SRCBLEND or RS_DESTBLEND states are set to one of the following:
	//! BLEND_DESTALPHA, BLEND_INVDESTALPHA,
	//! BLEND_DESTCOLOR, BLEND_INVDESTCOLOR.
	D3D9_CAPS3_ALPHA_FULLSCREEN_FLIP_OR_DISCARD = 0x00000020,

	//! CAPS3_COPY_TO_VIDMEM indicates that the device can accelerate a memory
	//! copy from system memory to local video memory. The cap guarantees that
	//! UpdateSurface and UpdateTexture calls will be hardware accelerated.
	//! If this cap is absent, these calls will succeed but will be slower.
	D3D9_CAPS3_COPY_TO_VIDMEM = 0x00000100,

	//! CAPS3_COPY_TO_SYSTEMMEM indicates that the device can accelerate a
	//! memory copy from local video memory to system memory. This cap
	//! guarantees that GetRenderTargetData calls will be HW-Accelerated.
	//! If this cap is absent, this call will succeed but will be slower.
	D3D9_CAPS3_COPY_TO_SYSTEMMEM = 0x00000200,

	//! CAPS3_LINEAR_TO_SRGB_PRESENTATION indicates that the device
	//! can perform gamma correction from a windowed back buffer
	//! (containing linear content) to an sRGB desktop.
	D3D9_CAPS3_LINEAR_TO_SRGB_PRESENTATION = 0x00000080,
};
enum d3d9_clear_e
{
	//! CLEAR_STENCIL clears the stencil buffer.
	D3D9_CLEAR_STENCIL = 0x00000004,

	//! CLEAR_TARGET clears a render target,
	//! or all targets in a multiple render target.
	D3D9_CLEAR_TARGET = 0x00000001,

	//! CLEAR_ZBUFFER clears the depth buffer.
	D3D9_CLEAR_ZBUFFER = 0x00000002,
};
enum d3d9_create_e
{
	//! CREATE_ADAPTERGROUP_DEVICE asks the device to drive all the heads that
	//! this master adapter owns. The flag is illegal on nonmaster adapters.
	//! If this flag is set, the presentation params passed to CreateDevice
	//! should point to an array of PRESENT_PARAMETERS. The number of elements
	//! in PRESENT_PARAMETERS should equal the num. of adapters defined by the
	//! NumberOfAdaptersInGroup member of the CAPS9 structure. The DirectX
	//! runtime will assign each element to each head in the numerical order
	//! specified by the AdapterOrdinalInGroup member of CAPS9.
	D3D9_CREATE_ADAPTERGROUP_DEVICE = 0x00000200,

	//! CREATE_DISABLE_DRIVER_MANAGEMENT instructs Direct3D to manage
	//! resources instead of the driver. Direct3D calls will not fail
	//! for resource errors such as insufficient video memory.
	D3D9_CREATE_DISABLE_DRIVER_MANAGEMENT = 0x00000400,

	//! CREATE_DISABLE_DRIVER_MANAGEMENT_EX instructs Direct3D to manage
	//! resources instead of the driver. Unlike
	//! CREATE_DISABLE_DRIVER_MANAGEMENT, CREATE_DISABLE_DRIVER_MANAGEMENT_EX
	//! will return errors for conditions such as insufficient video memory.
	D3D9_CREATE_DISABLE_DRIVER_MANAGEMENT_EX = 0x00000400,

	//! CREATE_DISABLE_PRINTSCREEN causes the runtime not register
	//! hotkeys for Printscreen, Ctrl-Printscreen and Alt-Printscreen
	//! to capture the desktop or window content.
	//! This flag is available in Direct3D 9Ex only.
	D3D9_CREATE_DISABLE_PRINTSCREEN = 0x00008000,

	//! CREATE_DISABLE_PSGP_THREADING restricts computation to the main
	//! application thread. If the flag is not set, the runtime may perform
	//! software vertex processing and other computations in worker thread to
	//! improve performance on multi-processor systems. Differences between
	//! Windows XP and Windows Vista: This flag is available on Windows Vista,
	//! Windows Server 2008, and Windows 7.
	D3D9_CREATE_DISABLE_PSGP_THREADING = 0x00002000,

	//! CREATE_ENABLE_PRESENTSTATS enables the gathering of present statistics
	//! on the device. Calls to GetPresentStatistics will return valid data.
	//! This flag is available in Direct3D 9Ex only.
	D3D9_CREATE_ENABLE_PRESENTSTATS = 0x00004000,

	//! CREATE_FPU_PRESERVE sets the precision for Direct3D floating-point
	//! calculations to the precision used by the calling thread. If you
	//! do not specify this flag, Direct3D defaults to single-precision
	//! round-to-nearest mode for two reasons:
	//! 1) Double-precision mode will reduce Direct3D performance.
	//! 2) Portions of Direct3D assume floating-point unit exceptions are
	//! masked; unmasking these exceptions may result in undefined behavior.
	D3D9_CREATE_FPU_PRESERVE = 0x00000002,

	//! CREATE_HARDWARE_VERTEXPROCESSING specifies hardware vertex processing.
	D3D9_CREATE_HARDWARE_VERTEXPROCESSING = 0x00000040,

	//! CREATE_MIXED_VERTEXPROCESSING specifies mixed
	//! (both software and hardware) vertex processing.
	D3D9_CREATE_MIXED_VERTEXPROCESSING = 0x00000080,

	//! CREATE_MULTITHREADED indicates that the application requests Direct3D
	//! to be multithread safe. This makes a Direct3D thread take ownership
	//! of its global critical section more frequently, which can degrade
	//! performance. If an application processes window messages
	//! in one thread while making Direct3D API calls in another,
	//! the application must use this flag when creating the device.
	//! This window must also be destroyed before unloading d3d9.dll.
	D3D9_CREATE_MULTITHREADED = 0x00000004,

	//! CREATE_NOWINDOWCHANGES indicates that Direct3D
	//! must not alter the focus window in any way.
	//! Note: If this flag is set, the application must fully support all
	//! focus management events, such as ALT+TAB and mouse click events.
	D3D9_CREATE_NOWINDOWCHANGES = 0x00000800,

	//! CREATE_PUREDEVICE specifies that Direct3D does not support 'Get*'
	//! calls for anything that can be stored in state blocks. It also tells
	//! Direct3D not to provide any emulation services for vertex processing.
	//! This means that if the device does not support vertex processing,
	//! then the application can use only post-transformed vertices.
	D3D9_CREATE_PUREDEVICE = 0x00000010,

	//! CREATE_SCREENSAVER allows screensaver during a fullscreen application.
	//! Without this flag, Direct3D will disable screensavers for as long as
	//! the calling application is fullscreen. If the calling application is
	//! already a screensaver, this flag has no effect.
	//! This flag is available in Direct3D 9Ex only.
	D3D9_CREATE_SCREENSAVER = 0x10000000,

	//! CREATE_SOFTWARE_VERTEXPROCESSING specifies software vertex processing.
	D3D9_CREATE_SOFTWARE_VERTEXPROCESSING = 0x00000020,
};
enum d3d9_cs_e
{
	//! CS_ALL is a combination of all clip flags.
	D3D9_CS_ALL = 0xFFF,

	//! CS_LEFT means all vertices are clipped
	//! by the left plane of the viewing frustum.
	D3D9_CS_LEFT = 0x001,

	//! CS_RIGHT means all vertices are clipped
	//! by the right plane of the viewing frustum.
	D3D9_CS_RIGHT = 0x002,

	//! CS_TOP means all vertices are clipped
	//! by the top plane of the viewing frustum.
	D3D9_CS_TOP = 0x004,

	//! CS_BOTTOM means all vertices are clipped
	//! by the bottom plane of the viewing frustum.
	D3D9_CS_BOTTOM = 0x008,

	//! CS_FRONT means all vertices are clipped
	//! by the front plane of the viewing frustum.
	D3D9_CS_FRONT = 0x010,

	//! CS_BACK means all vertices are clipped
	//! by the back plane of the viewing frustum.
	D3D9_CS_BACK = 0x020,

	//! CS_PLANE0 uses application-defined clipping planes.
	D3D9_CS_PLANE0 = 0x040,

	//! CS_PLANE1 uses application-defined clipping planes.
	D3D9_CS_PLANE1 = 0x080,

	//! CS_PLANE2 uses application-defined clipping planes.
	D3D9_CS_PLANE2 = 0x100,

	//! CS_PLANE3 uses application-defined clipping planes.
	D3D9_CS_PLANE3 = 0x200,

	//! CS_PLANE4 uses application-defined clipping planes.
	D3D9_CS_PLANE4 = 0x400,

	//! CS_PLANE5 uses application-defined clipping planes.
	D3D9_CS_PLANE5 = 0x800,
};
enum d3d9_cursorcaps_e
{
	//! CURSORCAPS_COLOR indicates that the driver supports hardware
	//! color cursor in at least high resolution modes (height >= 400).
	D3D9_CURSORCAPS_COLOR = 1,

	//! CURSORCAPS_LOWRES indicates that the driver supports hardware
	//! color cursor in low resolution modes (height < 400).
	D3D9_CURSORCAPS_LOWRES = 2,
};
enum d3d9_devcaps_e
{
	//! DEVCAPS_CANBLTSYSTONONLOCAL means the device supports blits
	//! from system-memory textures to nonlocal video-memory textures.
	D3D9_DEVCAPS_CANBLTSYSTONONLOCAL = 0x0020000,

	//! DEVCAPS_CANRENDERAFTERFLIP means the device can queue render commands
	//! after a page flip. Applications do not change their behavior if this
	//! flag is set; This capability means that the device is relatively fast.
	D3D9_DEVCAPS_CANRENDERAFTERFLIP = 0x0000800,

	//! DEVCAPS_DRAWPRIMITIVES2 means the device can
	//! support at least a DirectX 5-compliant driver.
	D3D9_DEVCAPS_DRAWPRIMITIVES2 = 0x0002000,

	//! DEVCAPS_DRAWPRIMITIVES2EX means the device can
	//! support at least a DirectX 7-compliant driver.
	D3D9_DEVCAPS_DRAWPRIMITIVES2EX = 0x0008000,

	//! DEVCAPS_DRAWPRIMTLVERTEX means the device
	//! exports an IDirect3DDevice9::DrawPrimitive-aware HAL.
	D3D9_DEVCAPS_DRAWPRIMTLVERTEX = 0x0000400,

	//! DEVCAPS_EXECUTESYSTEMMEMORY means the device
	//! can use execute buffers from system memory.
	D3D9_DEVCAPS_EXECUTESYSTEMMEMORY = 0x0000010,

	//! DEVCAPS_EXECUTEVIDEOMEMORY means the device
	//! can use execute buffers from video memory.
	D3D9_DEVCAPS_EXECUTEVIDEOMEMORY = 0x0000020,

	//! DEVCAPS_HWRASTERIZATION means the device
	//! has hardware acceleration for scene rasterization.
	D3D9_DEVCAPS_HWRASTERIZATION = 0x0080000,

	//! DEVCAPS_HWTRANSFORMANDLIGHT means the device
	//! can support transformation and lighting in hardware.
	D3D9_DEVCAPS_HWTRANSFORMANDLIGHT = 0x0010000,

	//! DEVCAPS_NPATCHES means the device supports N patches.
	D3D9_DEVCAPS_NPATCHES = 0x1000000,

	//! DEVCAPS_PUREDEVICE means the device can support rasterization,
	//! transform, lighting, and shading in hardware.
	D3D9_DEVCAPS_PUREDEVICE = 0x0100000,

	//! DEVCAPS_QUINTICRTPATCHES means the device supports quintic B�zier
	//! curves and B-splines.
	D3D9_DEVCAPS_QUINTICRTPATCHES = 0x0200000,

	//! DEVCAPS_RTPATCHES means the device supports rectangular and triangular
	//! patches.
	D3D9_DEVCAPS_RTPATCHES = 0x0400000,

	//! DEVCAPS_RTPATCHHANDLEZERO means the hardware architecture does not
	//! require caching of any information, and uncached patches (handle zero)
	//! will be drawn as efficiently as cached ones. Note that setting
	//! DEVCAPS_RTPATCHHANDLEZERO does not mean that a patch with handle zero
	//! can be drawn. A handle-zero patch can always be drawn whether this cap
	//! is set or not.
	D3D9_DEVCAPS_RTPATCHHANDLEZERO = 0x0800000,

	//! DEVCAPS_SEPARATETEXTUREMEMORIES means the device
	//! is texturing from separate memory pools.
	D3D9_DEVCAPS_SEPARATETEXTUREMEMORIES = 0x0004000,

	//! DEVCAPS_TEXTURENONLOCALVIDMEM means the device
	//! can retrieve textures from non-local video memory.
	D3D9_DEVCAPS_TEXTURENONLOCALVIDMEM = 0x0001000,

	//! DEVCAPS_TEXTURESYSTEMMEMORY means the device
	//! can retrieve textures from system memory.
	D3D9_DEVCAPS_TEXTURESYSTEMMEMORY = 0x0000100,

	//! DEVCAPS_TEXTUREVIDEOMEMORY means the device
	//! can retrieve textures from device memory.
	D3D9_DEVCAPS_TEXTUREVIDEOMEMORY = 0x0000200,

	//! DEVCAPS_TLVERTEXSYSTEMMEMORY means the device
	//! can use buffers from system memory for transformed and lit vertices.
	D3D9_DEVCAPS_TLVERTEXSYSTEMMEMORY = 0x0000040,

	//! DEVCAPS_TLVERTEXVIDEOMEMORY means the device
	//! can use buffers from video memory for transformed and lit vertices.
	D3D9_DEVCAPS_TLVERTEXVIDEOMEMORY = 0x0000080,
};
enum d3d9_devcaps2_e
{
	//! DEVCAPS2_ADAPTIVETESSRTPATCH indicates that the device
	//! supports adaptive tessellation of RT-patches
	D3D9_DEVCAPS2_ADAPTIVETESSRTPATCH = 0x00000004,

	//! DEVCAPS2_ADAPTIVETESSNPATCH indicates that the device
	//! supports adaptive tessellation of N-patches.
	D3D9_DEVCAPS2_ADAPTIVETESSNPATCH = 0x00000008,

	// DEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES indicates that the device
	// supports StretchRect using a texture as the source.
	D3D9_DEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES = 0x00000010,

	//! DEVCAPS2_DMAPNPATCH indicates that the device
	//! supports displacement maps for N-patches.
	D3D9_DEVCAPS2_DMAPNPATCH = 0x00000002,

	//! DEVCAPS2_PRESAMPLEDDMAPNPATCH indicates that the device
	//! supports presampled displacement maps for N-patches.
	D3D9_DEVCAPS2_PRESAMPLEDDMAPNPATCH = 0x00000020,

	//! DEVCAPS2_STREAMOFFSET indicates that the device
	//! supports stream offsets.
	D3D9_DEVCAPS2_STREAMOFFSET = 0x00000001,

	//! DEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET means that multiple
	//! vertex elements can share the same offset in a stream if
	//! DEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET is set by a device and the
	//! vertex declaration does not have an element with DECLUSAGE_POSITIONT0.
	D3D9_DEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET = 0x00000040,
};
enum d3d9_dtcaps_e
{
	//! DTCAPS_UBYTE4 is a 4D unsigned byte.
	D3D9_DTCAPS_UBYTE4 = 0x00000001,

	//! DTCAPS_UBYTE4N is a normalized, 4D unsigned byte.
	//! Each of the four bytes is normalized by dividing to 255.0.
	D3D9_DTCAPS_UBYTE4N = 0x00000002,

	//! DTCAPS_SHORT2N is a normalized, 2D signed short, expanded to
	//! (first byte/32767.0, second byte/32767.0, 0, 1).
	D3D9_DTCAPS_SHORT2N = 0x00000004,

	//! DTCAPS_SHORT4N is a normalized, 4D signed short, expanded to
	//! (first byte/32767.0, second byte/32767.0, third byte/32767.0,
	//! fourth byte/32767.0).
	D3D9_DTCAPS_SHORT4N = 0x00000008,

	//! DTCAPS_USHORT2N is a normalized, 2D unsigned short, expanded to
	//! (first byte/65535.0, second byte/65535.0, 0, 1).
	D3D9_DTCAPS_USHORT2N = 0x00000010,

	//! DTCAPS_USHORT4N is a normalized 4D unsigned short, expanded to
	//! (first byte/65535.0, second byte/65535.0, third byte/65535.0,
	//! fourth byte/65535.0).
	D3D9_DTCAPS_USHORT4N = 0x00000020,

	//! DTCAPS_UDEC3 is a 3D unsigned 10 10 10 format
	//! expanded to (value, value, value, 1).
	D3D9_DTCAPS_UDEC3 = 0x00000040,

	//! DTCAPS_DEC3N is a 3D signed 10 10 10 format normalized
	//! and expanded to (v[0]/511.0, v[1]/511.0, v[2]/511.0, 1).
	D3D9_DTCAPS_DEC3N = 0x00000080,

	//! DTCAPS_FLOAT16_2 is a 2D 16-bit floating point numbers.
	D3D9_DTCAPS_FLOAT16_2 = 0x00000100,

	//! DTCAPS_FLOAT16_4 is a 4D 16-bit floating point numbers.
	D3D9_DTCAPS_FLOAT16_4 = 0x00000200,
};
enum d3d9_ok_e
{
	D3D9_S_OK = 0, //!< S_OK indicates that no error occurred.
	D3D9_OK   = 0, //!<   OK indicates that no error occurred.
};
enum d3d9_err_not_e
{
	//! ERR_NOTAVAILABLE indicates that this device
	//! does not support the queried technique.
	D3D9_ERR_NOTAVAILABLE = -2005530518,

	//! ERR_NOTFOUND indicates that the requested item was not found.
	D3D9_ERR_NOTFOUND = -2005530522,
};
enum d3d9_err_device_e
{
	//! ERR_DEVICEHUNG indicates that the device that returned this
	//! code caused the hardware adapter to be reset by the OS.
	//! Most applications should destroy the device and quit.
	//! Applications that must continue should destroy all
	//! video memory objects (surfaces, textures, state blocks, etc.)
	//! and call Reset() to put the device in a default state.
	//! If the application then continues rendering in the same way,
	//! the device will return to this state. Applies to Direct3D 9Ex only.
	D3D9_ERR_DEVICEHUNG = -2005530508,

	//! ERR_DEVICELOST indicates that the device has been lost but cannot be
	//! reset at this time. Therefore, rendering is not possible. A Direct3D
	//! device object other than the one that returned this code caused the
	//! hardware adapter to be reset by the OS. Delete all video memory
	//! objects (surfaces, textures, state blocks) and call Reset()
	//! to return the device to a default state. If the application
	//! continues rendering without a reset, the rendering calls will succeed.
	D3D9_ERR_DEVICELOST = -2005530520,

	//! ERR_DEVICENOTRESET indicates that the device
	//! has been lost but can be reset at this time.
	D3D9_ERR_DEVICENOTRESET = -2005530519,

	//! ERR_DEVICEREMOVED indicates that he hardware adapter has been removed.
	//! Application must destroy the device, do enumeration of adapters and
	//! create another Direct3D device. If application continues rendering
	//! without calling Reset, the rendering calls will succeed.
	//! Applies to Direct3D 9Ex only.
	D3D9_ERR_DEVICEREMOVED = -2005530512,
};
enum d3d9_err_driver_e
{
	//! ERR_DRIVERINTERNALERROR Internal driver error. Applications
	//! should destroy and recreate the device when receiving this error.
	D3D9_ERR_DRIVERINTERNALERROR = -2005530585,

	//! ERR_DRIVERINVALIDCALL is not used.
	D3D9_ERR_DRIVERINVALIDCALL = -2005530515,
};
enum d3d9_err_invalid_e
{
	//! ERR_INVALIDCALL indicates that the method call is invalid.
	//! For example, a method's parameter may not be an invalid pointer.
	D3D9_ERR_INVALIDCALL = -2005530516,

	//! ERR_INVALIDDEVICE indicates that the requested device type is invalid.
	D3D9_ERR_INVALIDDEVICE = -2005530517,
};
enum d3d9_err_conflict_e
{
	//! ERR_CONFLICTINGRENDERSTATE indicates that
	//! the currently set render states cannot be used together.
	D3D9_ERR_CONFLICTINGRENDERSTATE = -2005530591,

	//! ERR_CONFLICTINGTEXTUREFILTER indicates that
	//! the current texture filters cannot be used together.
	D3D9_ERR_CONFLICTINGTEXTUREFILTER = -2005530594,

	//! ERR_CONFLICTINGTEXTUREPALETTE indicates that
	//! the current textures cannot be used simultaneously.
	D3D9_ERR_CONFLICTINGTEXTUREPALETTE = -2005530586,
};
enum d3d9_err_unsupported_e
{
	//! ERR_UNSUPPORTEDALPHAARG indicates that the device does not
	//! support a specified texture-blending argument for the alpha channel.
	D3D9_ERR_UNSUPPORTEDALPHAARG = -2005530596,

	//! ERR_UNSUPPORTEDALPHAOPERATION indicates that the device does not
	//! support a specified texture-blending operation for the alpha channel.
	D3D9_ERR_UNSUPPORTEDALPHAOPERATION = -2005530597,

	//! ERR_UNSUPPORTEDCOLORARG indicates that the device does not
	//! support a specified texture-blending argument for color values.
	D3D9_ERR_UNSUPPORTEDCOLORARG = -2005530598,

	//! ERR_UNSUPPORTEDCOLOROPERATION indicates that the device does not
	//! support a specified texture-blending operation for color values.
	D3D9_ERR_UNSUPPORTEDCOLOROPERATION = -2005530599,

	//! ERR_UNSUPPORTEDFACTORVALUE indicates that the device does not support
	//! the specified texture factor value. Not used; provided only to support
	//! older drivers.
	D3D9_ERR_UNSUPPORTEDFACTORVALUE = -2005530593,

	//! ERR_UNSUPPORTEDTEXTUREFILTER indicates that the
	//! device does not support the specified texture filter.
	D3D9_ERR_UNSUPPORTEDTEXTUREFILTER = -2005530590,
};
enum d3d9_err_e
{
	//! OK_NOAUTOGEN is a success code. However, the autogeneration of mipmaps
	//! is not supported for this format. This means that resource creation
	//! will succeed but the mipmap levels will not be auto-generated.
	D3D9_OK_NOAUTOGEN = 141953135,

	//! ERR_MOREDATA indicates that there is more data available
	//! than the specified buffer size can hold.
	D3D9_ERR_MOREDATA = -2005530521,

	//! ERR_OUTOFVIDEOMEMORY indicates that Direct3D does not have enough
	//! display memory to perform the operation. The device is using more
	//! resources in a single scene than can fit simultaneously into video
	//! memory. Present, PresentEx, or CheckDeviceState can return this error.
	//! Recovery is similar to ERR_DEVICEHUNG, though the application may want
	//! to reduce its per-frame memory usage as well to avoid having the error
	//! recur.
	D3D9_ERR_OUTOFVIDEOMEMORY = -2005532292,

	//! ERR_TOOMANYOPERATIONS indicates that the application is requesting
	//! more texture-filtering operations than the device supports.
	D3D9_ERR_TOOMANYOPERATIONS = -2005530595,

	//! ERR_WASSTILLDRAWING indicates that the previous blit operation that
	//! is transferring information to or from this surface is incomplete.
	D3D9_ERR_WASSTILLDRAWING = -2005532132,

	//! ERR_WRONGTEXTUREFORMAT indicates that the pixel
	//! format of the texture surface is not valid.
	D3D9_ERR_WRONGTEXTUREFORMAT = -2005530600,
};
enum d3d9_e_e
{
	//! E_FAIL indicates that an undetermined error
	//! occurred inside the Direct3D subsystem.
	D3D9_E_FAIL = -2147467259,

	//! E_INVALIDARG indicates that an invalid parameter
	//! was passed to the returning function.
	D3D9_E_INVALIDARG = -2147024809,

	//! E_NOINTERFACE indicates that no object interface is available.
	D3D9_E_NOINTERFACE = -2147467262,

	//! E_NOTIMPL indicates that a method is not implemented.
	D3D9_E_NOTIMPL = -2147467263,

	//! E_OUTOFMEMORY indicates that Direct3D could not
	//! allocate sufficient memory to complete the call.
	D3D9_E_OUTOFMEMORY = -2147024882,
};
enum d3d9_s_e
{
	//! S_NOT_RESIDENT indicates that at least one allocation that
	//! comprises the resources is on disk. Direct3D 9Ex only.
	D3D9_S_NOT_RESIDENT = 141953141,

	//! S_RESIDENT_IN_SHARED_MEMORY indicates that no allocations that
	//! comprise the resources are on disk. However, at least one
	//! allocation is not in GPU-accessible memory. Direct3D 9Ex only.
	D3D9_S_RESIDENT_IN_SHARED_MEMORY = 141953142,
};
enum d3d9_err_d3d9ex_e
{
	//! ERR_UNSUPPORTEDOVERLAY indicates that the device does not
	//! support overlay for the specified size or display mode.
	//! Direct3D 9Ex under Windows 7 only.
	D3D9_ERR_UNSUPPORTEDOVERLAY = -2005530501,

	//! ERR_UNSUPPORTEDOVERLAYFORMAT indicates that the device
	//! does not support overlay for the specified surface format.
	//! Direct3D 9Ex under Windows 7 only.
	D3D9_ERR_UNSUPPORTEDOVERLAYFORMAT = -2005530500,

	//! ERR_CANNOTPROTECTCONTENT indicates that the
	//! specified content cannot be protected.
	//! Direct3D 9Ex under Windows 7 only.
	D3D9_ERR_CANNOTPROTECTCONTENT = -2005530499,

	//! ERR_UNSUPPORTEDCRYPTO indicates that the specified
	//! cryptographic algorithm is not supported.
	//! Direct3D 9Ex under Windows 7 only.
	D3D9_ERR_UNSUPPORTEDCRYPTO = -2005530498,
};
enum d3d9_fvfcaps_e
{
	//! FVFCAPS_DONOTSTRIPELEMENTS means it is preferable that vertex elements
	//! not be stripped. That is, if the vertex format contains elements that
	//! are not used with the current render states, there is no need to
	//! regenerate the vertices. If this capability flag is not present,
	//! stripping extraneous elements from the vertex format provides better
	//! performance.
	D3D9_FVFCAPS_DONOTSTRIPELEMENTS = 0x080000,

	//! FVFCAPS_PSIZE means the point size is determined by either the render
	//! state or the vertex data. If an FVF is used, point size can come from
	//! point size data in the vertex declaration. Otherwise, point size is
	//! determined by the render state RS_POINTSIZE. If the app provides
	//! point size in both (the render state and the vertex declaration),
	//! the vertex data overrides the render-state data.
	D3D9_FVFCAPS_PSIZE = 0x100000,

	//! FVFCAPS_TEXCOORDCOUNTMASK masks the low WORD of FVFCaps. These bits,
	//! cast to the WORD data type, describe the total number of texture
	//! coordinate sets that the device can simultaneously use for multiple
	//! texture blending. (You can use up to eight texture coordinate sets
	//! for any vertex, but the device can blend using only the specified
	//! number of texture coordinate sets.)
	D3D9_FVFCAPS_TEXCOORDCOUNTMASK = 0x00FFFF,
};
enum d3d9_fvf_e
{
	//! FVF_DIFFUSE means: Vertex format includes a diffuse color component.
	//! It is a COLOR in ARGB order.
	D3D9_FVF_DIFFUSE = 0x0040,

	//! FVF_NORMAL means: Vertex format includes a vertex normal vector.
	//! This flag cannot be used with the FVF_XYZRHW flag.
	//! The normal consists of three f32.
	D3D9_FVF_NORMAL = 0x0010,

	//! FVF_PSIZE means vertex format specified in point size. This size is
	//! expressed in camera space units for vertices that are not transformed
	//! and lit, and in device-space units for transformed and lit vertices.
	D3D9_FVF_PSIZE = 0x0020,

	//! FVF_SPECULAR means: Vertex format includes a specular color component.
	D3D9_FVF_SPECULAR = 0x0080,

	//! FVF_POSITION_MASK means the format has a mask for position bits.
	D3D9_FVF_POSITION_MASK = 0x400E,

	//! FVF_LASTBETA_D3DCOLOR means the last beta field in the vertex position
	//! data will be of type COLOR. The data in the beta fields are used with
	//! matrix palette skinning to specify matrix indices.
	D3D9_FVF_LASTBETA_D3DCOLOR = 0x8000,

	//! FVF_LASTBETA_UBYTE4 means the last beta field in the vertex position
	//! data will be of type UBYTE4. The data in the beta fields are used with
	//! matrix palette skinning to specify matrix indices.
	D3D9_FVF_LASTBETA_UBYTE4 = 0x1000,
};
enum d3d9_fvf_xyz_e
{
	//! FVF_XYZ means: Vertex format includes the position of an untransformed
	//! vertex. This flag cannot be used with the FVF_XYZRHW flag.
	D3D9_FVF_XYZ = 0x0002,

	//! FVF_XYZRHW means the vertex format includes the position of a
	//! transformed vertex. This flag cannot be used with the FVF_XYZ
	//! or FVF_NORMAL flags.
	D3D9_FVF_XYZRHW = 0x0004,

	//! FVF_XYZB1 means the vertex format contains position data, and 1
	//! weighting (beta) value to use for multimatrix vertex blending
	//! operations. Currently, Direct3D can blend with up to three
	//! weighting values and four blending matrices.
	D3D9_FVF_XYZB1 = 0x0006,

	//! FVF_XYZB2 means the vertex format contains position data, and 2
	//! weighting (beta) values to use for multimatrix vertex blending
	//! operations. Currently, Direct3D can blend with up to three
	//! weighting values and four blending matrices.
	D3D9_FVF_XYZB2 = 0x0008,

	//! FVF_XYZB3 means the vertex format contains position data, and 3
	//! weighting (beta) values to use for multimatrix vertex blending
	//! operations. Currently, Direct3D can blend with up to three
	//! weighting values and four blending matrices.
	D3D9_FVF_XYZB3 = 0x000a,

	//! FVF_XYZB4 means the vertex format contains position data, and 4
	//! weighting (beta) values to use for multimatrix vertex blending
	//! operations. Currently, Direct3D can blend with up to three
	//! weighting values and four blending matrices.
	D3D9_FVF_XYZB4 = 0x000c,

	//! FVF_XYZB5 means the vertex format contains position data, and 5
	//! weighting (beta) values to use for multimatrix vertex blending
	//! operations. Currently, Direct3D can blend with up to three
	//! weighting values and four blending matrices.
	D3D9_FVF_XYZB5 = 0x000e,

	//! FVF_XYZW means the vertex format contains transformed and clipped
	//! (x, y, z, w) data. ProcessVertices does not invoke the clipper,
	//! instead outputting data in clip coordinates. This constant is designed
	//! for, and can only be used with, the programmable vertex pipeline.
	D3D9_FVF_XYZW = 0x4002,
};
enum d3d9_fvf_tex_e
{
	//! FVF_TEX0 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX0 = 0x0000,

	//! FVF_TEX1 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX1 = 0x0100,

	//! FVF_TEX2 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX2 = 0x0200,

	//! FVF_TEX3 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX3 = 0x0300,

	//! FVF_TEX4 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX4 = 0x0400,

	//! FVF_TEX5 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX5 = 0x0500,

	//! FVF_TEX6 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX6 = 0x0600,

	//! FVF_TEX7 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX7 = 0x0700,

	//! FVF_TEX8 is the number of texture coordinate sets for this vertex.
	//! The actual values for these flags are not sequential.
	D3D9_FVF_TEX8 = 0x0800,
};
enum d3d9_fvf_textureformat_e
{
	//! FVF_TEXTUREFORMAT1 means 1 floating point value.
	D3D9_FVF_TEXTUREFORMAT1 = 3,

	//! FVF_TEXTUREFORMAT2 means 2 floating point value.
	D3D9_FVF_TEXTUREFORMAT2 = 0,

	//! FVF_TEXTUREFORMAT3 means 3 floating point value.
	D3D9_FVF_TEXTUREFORMAT3 = 1,

	//! FVF_TEXTUREFORMAT4 means 4 floating point value.
	D3D9_FVF_TEXTUREFORMAT4 = 2,
};
enum d3d9_fvf_texcount_e
{
	//! FVF_TEXCOUNT_MASK means the format has
	//! a mask value for texture flag bits.
	D3D9_FVF_TEXCOUNT_MASK = 0x0f00,

	//! FVF_TEXCOUNT_SHIFT is the number of bits by which to shift an integer
	//! value that identifies the number of texture coordinates for a vertex.
	D3D9_FVF_TEXCOUNT_SHIFT = 8,
};
enum d3d9_linecaps_e
{
	//! LINECAPS_ALPHACMP means it supports alpha-test comparisons.
	D3D9_LINECAPS_ALPHACMP = 0x08,

	//! LINECAPS_ANTIALIAS means antialiased lines are supported.
	D3D9_LINECAPS_ANTIALIAS = 0x20,

	//! LINECAPS_BLEND means it supports source-blending.
	D3D9_LINECAPS_BLEND = 0x04,

	//! LINECAPS_FOG means it supports fog.
	D3D9_LINECAPS_FOG = 0x10,

	//! LINECAPS_TEXTURE means it supports texture-mapping.
	D3D9_LINECAPS_TEXTURE = 0x01,

	//! LINECAPS_ZTEST means it supports z-buffer comparisons.
	D3D9_LINECAPS_ZTEST = 0x02,
};
enum d3d9_lock_e
{
	//! LOCK_DISCARD instructs the application to discard all memory
	//! within the locked region. For vertex and index buffers,
	//! the entire buffer will be discarded. This option is only
	//! valid when the resource is created with dynamic usage.
	D3D9_LOCK_DISCARD = 0x2000,

	//! LOCK_DONOTWAIT allows an application to gain back CPU cycles if the
	//! driver cannot lock the surface immediately. If the flag is set and the
	//! driver cannot lock the surface immediately, the lock call will return
	//! ERR_WASSTILLDRAWING. This flag can only be used when locking a surface
	//! created using CreateOffscreenPlainSurface, CreateRenderTarget, or
	//! CreateDepthStencilSurface. This flag can also be used with backbuffer.
	D3D9_LOCK_DONOTWAIT = 0x4000,

	//! LOCK_NO_DIRTY_UPDATE by default, a lock on a resource adds a dirty
	//! region to that resource. This option prevents any changes to the dirty
	//! state of the resource. Applications should use this option when they
	//! have additional information about the set of regions changed during
	//! the lock operation.
	D3D9_LOCK_NO_DIRTY_UPDATE = 0x8000,

	//! LOCK_NOOVERWRITE indicates that memory that was referred to in a
	//! drawing call since the last lock without this flag won't be modified
	//! during the lock. This can enable optimizations when the application
	//! is appending data to a resource. Specifying this flag enables the
	//! driver to return immediately if the resource is in use, otherwise, the
	//! driver must finish using the resource before returning from locking.
	D3D9_LOCK_NOOVERWRITE = 0x1000,

	//! LOCK_NOSYSLOCK the default behavior of a video memory lock is
	//! to reserve a system-wide critical section, guaranteeing that no
	//! display mode changes will occur for the duration of the lock.
	//! This option causes the system-wide critical section
	//! not to be held for the duration of the lock. The lock operation
	//! is time consuming, but can enable the system to perform other
	//! duties, such as moving the mouse cursor. This option is useful for
	//! long-duration locks, such as the lock of the back buffer for software
	//! rendering that would otherwise adversely affect system responsiveness.
	D3D9_LOCK_NOSYSLOCK = 0x0800,

	//! LOCK_READONLY means the application will not write to the buffer.
	//! This enables resources stored in non-native formats
	//! to save the recompression step when unlocking.
	D3D9_LOCK_READONLY = 0x0010,
};
enum d3d9_pblendcaps_e
{
	//! PBLENDCAPS_BLENDFACTOR means the driver supports
	//! both BLEND_BLENDFACTOR and BLEND_INVBLENDFACTOR.
	D3D9_PBLENDCAPS_BLENDFACTOR = 0x00002000,

	//! PBLENDCAPS_BOTHINVSRCALPHA means the source blend factor is
	//! (1 - As, 1 - As, 1 - As, 1 - As) and destination blend factor is
	//! (As, As, As, As); the destination blend selection is overridden.
	D3D9_PBLENDCAPS_BOTHINVSRCALPHA = 0x00001000,

	//! PBLENDCAPS_BOTHSRCALPHA means the driver supports
	//! the BLEND_BOTHSRCALPHA blend mode. (This blend mode is obsolete.)
	D3D9_PBLENDCAPS_BOTHSRCALPHA = 0x00000800,

	//! PBLENDCAPS_DESTALPHA means the blend factor is (Ad, Ad, Ad, Ad).
	D3D9_PBLENDCAPS_DESTALPHA = 0x00000040,

	//! PBLENDCAPS_DESTCOLOR means the blend factor is (Rd, Gd, Bd, Ad).
	D3D9_PBLENDCAPS_DESTCOLOR = 0x00000100,

	//! PBLENDCAPS_INVDESTALPHA means the blend factor is
	//! (1 - Ad, 1 - Ad, 1 - Ad, 1 - Ad).
	D3D9_PBLENDCAPS_INVDESTALPHA = 0x00000080,

	//! PBLENDCAPS_INVDESTCOLOR means the blend factor is
	//! (1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad).
	D3D9_PBLENDCAPS_INVDESTCOLOR = 0x00000200,

	//! PBLENDCAPS_INVSRCALPHA means the blend factor is
	//! (1 - As, 1 - As, 1 - As, 1 - As).
	D3D9_PBLENDCAPS_INVSRCALPHA = 0x00000020,

	//! PBLENDCAPS_INVSRCCOLOR means the blend factor is
	//! (1 - Rs, 1 - Gs, 1 - Bs, 1 - As).
	D3D9_PBLENDCAPS_INVSRCCOLOR = 0x00000008,

	//! PBLENDCAPS_ONE means the blend factor is (1, 1, 1, 1).
	D3D9_PBLENDCAPS_ONE = 0x00000002,

	//! PBLENDCAPS_SRCALPHA means the blend factor is (As, As, As, As).
	D3D9_PBLENDCAPS_SRCALPHA = 0x00000010,

	//! PBLENDCAPS_SRCALPHASAT means the blend factor is
	//! (f, f, f, 1); f = min(As, 1 - Ad).
	D3D9_PBLENDCAPS_SRCALPHASAT = 0x00000400,

	//! PBLENDCAPS_SRCCOLOR means the blend factor is (Rs, Gs, Bs, As).
	D3D9_PBLENDCAPS_SRCCOLOR = 0x00000004,

	//! PBLENDCAPS_ZERO means the blend factor is (0, 0, 0, 0).
	D3D9_PBLENDCAPS_ZERO = 0x00000001,
};
enum d3d9_pcmpcaps_e
{
	//! PCMPCAPS_ALWAYS always passes the z-test.
	D3D9_PCMPCAPS_ALWAYS = 0x80,

	//! PCMPCAPS_EQUAL passes the z-test if the new z equals the current z.
	D3D9_PCMPCAPS_EQUAL = 0x04,

	//! PCMPCAPS_GREATER passes the z-test if
	//! the new z is greater than the current z.
	D3D9_PCMPCAPS_GREATER = 0x10,

	//! PCMPCAPS_GREATEREQUAL passes the z-test if
	//! the new z is greater than or equal to the current z.
	D3D9_PCMPCAPS_GREATEREQUAL = 0x40,

	//! PCMPCAPS_LESS passes the z-test if
	//! the new z is less than the current z.
	D3D9_PCMPCAPS_LESS = 0x02,

	//! PCMPCAPS_LESSEQUAL passes the z-test if
	//! the new z is less than or equal to the current z.
	D3D9_PCMPCAPS_LESSEQUAL = 0x08,

	// PCMPCAPS_NEVER always fails the z-test.
	D3D9_PCMPCAPS_NEVER = 0x01,

	//! PCMPCAPS_NOTEQUAL passes the z-test if
	//! the new z does not equal the current z.
	D3D9_PCMPCAPS_NOTEQUAL = 0x20,
};
enum d3d9_pmisccaps_e
{
	//! PMISCCAPS_MASKZ means the device can enable and disable
	//! modification of the depth buffer on pixel operations.
	D3D9_PMISCCAPS_MASKZ = 0x00000002,

	//! PMISCCAPS_CULLNONE means the driver does not perform triangle culling.
	//! This corresponds to the CULL_NONE member of the CULL enumerated type.
	D3D9_PMISCCAPS_CULLNONE = 0x00000010,

	//! PMISCCAPS_CULLCW means the driver supports clockwise triangle culling
	//! through the RS_CULLMODE state. (This applies only to triangle
	//! primitives.) This flag corresponds to the CULL_CW member of the CULL
	//! enumerated type.
	D3D9_PMISCCAPS_CULLCW = 0x00000020,

	//! PMISCCAPS_CULLCCW means the driver supports counterclockwise culling
	//! through the RS_CULLMODE state. (This applies only to triangle
	//! primitives.) This flag corresponds to the CULL_CCW member of the CULL
	//! enumerated type.
	D3D9_PMISCCAPS_CULLCCW = 0x00000040,

	//! PMISCCAPS_COLORWRITEENABLE means device supports per-channel writes
	//! for the render-target color buffer through RS_COLORWRITEENABLE state.
	D3D9_PMISCCAPS_COLORWRITEENABLE = 0x00000080,

	//! PMISCCAPS_CLIPPLANESCALEDPOINTS means device correctly clips scaled
	//! points of size greater than 1.0 to user-defined clipping planes.
	D3D9_PMISCCAPS_CLIPPLANESCALEDPOINTS = 0x00000100,

	//! PMISCCAPS_CLIPTLVERTS means the device clips post-transformed vertex
	//! primitives.
	//! Specify USAGE_DONOTCLIP when the pipeline should not do any clipping.
	//! For this case, additional software clipping may need to be performed
	//! at draw time, requiring the vertex buffer to be in system memory.
	D3D9_PMISCCAPS_CLIPTLVERTS = 0x00000200,

	//! PMISCCAPS_TSSARGTEMP means device supports TA for temporary register.
	D3D9_PMISCCAPS_TSSARGTEMP = 0x00000400,

	//! PMISCCAPS_BLENDOP means the device supports
	//! alpha-blending operations other than BLENDOP_ADD.
	D3D9_PMISCCAPS_BLENDOP = 0x00000800,

	//! PMISCCAPS_NULLREFERENCE is a reference device that does not render.
	D3D9_PMISCCAPS_NULLREFERENCE = 0x00001000,

	//! PMISCCAPS_INDEPENDENTWRITEMASKS means the device supports independent
	//! write masks for multiple element textures or multiple render targets.
	D3D9_PMISCCAPS_INDEPENDENTWRITEMASKS = 0x00004000,

	//! PMISCCAPS_PERSTAGECONSTANT means the device supports per-stage
	//! constants. See TSS_CONSTANT in TEXTURESTAGESTATETYPE.
	D3D9_PMISCCAPS_PERSTAGECONSTANT = 0x00008000,

	//! PMISCCAPS_FOGANDSPECULARALPHA means the device supports
	//! separate fog and specular alpha. Many devices use the
	//! specular alpha channel to store the fog factor.
	D3D9_PMISCCAPS_FOGANDSPECULARALPHA = 0x00010000,

	//! PMISCCAPS_SEPARATEALPHABLEND means the device supports
	//! separate blend settings for the alpha channel.
	D3D9_PMISCCAPS_SEPARATEALPHABLEND = 0x00020000,

	//! PMISCCAPS_MRTINDEPENDENTBITDEPTHS means the device
	//! supports different bit depths for multiple render targets.
	D3D9_PMISCCAPS_MRTINDEPENDENTBITDEPTHS = 0x00040000,

	//! PMISCCAPS_MRTPOSTPIXELSHADERBLENDING means the device supports
	//! post-pixel shader operations for multiple render targets.
	D3D9_PMISCCAPS_MRTPOSTPIXELSHADERBLENDING = 0x00080000,

	//! PMISCCAPS_FOGVERTEXCLAMPED means that the device
	//! clamps fog blend factor per vertex.
	D3D9_PMISCCAPS_FOGVERTEXCLAMPED = 0x00100000,
};
enum d3d9_prastercaps_e
{
	//! PRASTERCAPS_ANISOTROPY means device supports anisotropic filtering.
	D3D9_PRASTERCAPS_ANISOTROPY = 0x00020000,

	//! PRASTERCAPS_COLORPERSPECTIVE means that the device
	//! iterates colors perspective correctly.
	D3D9_PRASTERCAPS_COLORPERSPECTIVE = 0x00400000,

	//! PRASTERCAPS_DITHER means that the device
	//! can dither to improve color resolution.
	D3D9_PRASTERCAPS_DITHER = 0x00000001,

	//! PRASTERCAPS_DEPTHBIAS means that a device supports legacy depth bias.
	//! For true depth bias, see PRASTERCAPS_SLOPESCALEDEPTHBIAS.
	D3D9_PRASTERCAPS_DEPTHBIAS = 0x04000000,

	//! PRASTERCAPS_FOGRANGE means the device supports range-based fog.
	//! In range-based fog, the distance of an object from the viewer
	//! is used to compute fog effects, not the depth of the object
	//! (that is, the z-coordinate) in the scene.
	D3D9_PRASTERCAPS_FOGRANGE = 0x00010000,

	//! PRASTERCAPS_FOGTABLE means the device calculates the
	//! fog value by referring to a lookup table containing
	//! fog values that are indexed to the depth of a given pixel.
	D3D9_PRASTERCAPS_FOGTABLE = 0x00000100,

	//! PRASTERCAPS_FOGVERTEX means the device calculates the fog value
	//! during the lighting operation and interpolates the fog value
	//! during rasterization.
	D3D9_PRASTERCAPS_FOGVERTEX = 0x00000080,

	//! PRASTERCAPS_MIPMAPLODBIAS means the device supports level-of-detail
	//! bias adjustments. These bias adjustments enable an application to
	//! make a mipmap appear crisper or less sharp than it normally would.
	//! For more information about level-of-detail bias in mipmaps, see
	//! SAMP_MIPMAPLODBIAS.
	D3D9_PRASTERCAPS_MIPMAPLODBIAS = 0x00002000,

	//! PRASTERCAPS_MULTISAMPLE_TOGGLE means the device supports toggling
	//! multisampling on and off between Device.BeginScene
	//! and Device.EndScene (using RS_MULTISAMPLEANTIALIAS).
	D3D9_PRASTERCAPS_MULTISAMPLE_TOGGLE = 0x08000000,

	//! PRASTERCAPS_SCISSORTEST means the device supports scissor test.
	D3D9_PRASTERCAPS_SCISSORTEST = 0x01000000,

	//! PRASTERCAPS_SLOPESCALEDEPTHBIAS means the device performs true
	//! slope-scale based depth bias. This is in contrast to the legacy style
	//! depth bias.
	D3D9_PRASTERCAPS_SLOPESCALEDEPTHBIAS = 0x02000000,

	//! PRASTERCAPS_WBUFFER means the device supports depth buffering using w.
	D3D9_PRASTERCAPS_WBUFFER = 0x00040000,

	//! PRASTERCAPS_WFOG means the device supports w-based fog. W-based fog
	//! is used when a perspective projection matrix is specified, but affine
	//! projections still use z-based fog. The system considers a projection
	//! matrix that contains a nonzero value in the [3][4] element to be a
	//! perspective projection matrix.
	D3D9_PRASTERCAPS_WFOG = 0x00100000,

	//! PRASTERCAPS_ZBUFFERLESSHSR means the device can perform hidden-surface
	//! removal (HSR) without requiring the application to sort polygons and
	//! without requiring the allocation of a depth-buffer. This leaves more
	//! video memory for textures. The method used to perform HSR is
	//! hardware-dependent and is transparent to the application.
	//! Z-bufferless HSR is performed if no depth-buffer surface is associated
	//! with the rendering-target surface and the depth-buffer comparison test
	//! is enabled (that is, when the state value associated with
	//! the RS_ZENABLE enumeration constant is set to TRUE).
	D3D9_PRASTERCAPS_ZBUFFERLESSHSR = 0x00008000,

	//! PRASTERCAPS_ZFOG means the device supports z-based fog.
	D3D9_PRASTERCAPS_ZFOG = 0x00200000,

	//! PRASTERCAPS_ZTEST means the device can perform z-test operations. This
	//! effectively renders a primitive and indicates whether any z pixels have
	//! been rendered.
	D3D9_PRASTERCAPS_ZTEST = 0x00000010,
};
enum d3d9_present_interval_e
{
	//! PRESENT_INTERVAL_DEFAULT is nearly equivalent to PRESENT_INTERVAL_ONE.
	D3D9_PRESENT_INTERVAL_DEFAULT = 0x00000000,

	//! PRESENT_INTERVAL_ONE means the driver will wait for the vertical
	//! retrace period (the runtime will "beam follow" to prevent tearing).
	//! Present operations will not be affected more frequently than the
	//! screen refresh; the runtime will complete at most one Present
	//! operation per adapter refresh period. This is equivalent to using
	//! SWAPEFFECT_COPYVSYNC in DirectX 8.1. This option is always available
	//! for both windowed and full-screen swap chains.
	D3D9_PRESENT_INTERVAL_ONE = 0x00000001,

	//! PRESENT_INTERVAL_TWO means the driver will wait for the vertical
	//! retrace period. Present operations won't be affected more frequently
	//! than every second screen refresh. Check the PresentationIntervals cap
	//! (see CAPS) to see if PRESENT_INTERVAL_TWO is supported by the driver.
	D3D9_PRESENT_INTERVAL_TWO = 0x00000002,

	//! PRESENT_INTERVAL_THREE means the driver will wait for the vertical
	//! retrace period. Present operations won't be affected more frequently
	//! than every third screen refresh. Check the PresentationIntervals cap
	//! (see CAPS) to see if PRESENT_INTERVAL_THREE is supported by a driver.
	D3D9_PRESENT_INTERVAL_THREE = 0x00000004,

	//! PRESENT_INTERVAL_FOUR means the driver will wait for the vert-retrace
	//! period. Present operations won't be affected more frequently than
	//! every fourth screen refresh. Check the PresentationIntervals member
	//! (see CAPS) to see if PRESENT_INTERVAL_FOUR is supported by the driver.
	D3D9_PRESENT_INTERVAL_FOUR = 0x00000008,

	//! PRESENT_INTERVAL_IMMEDIATE means the runtime updates the window client
	//! area immediately and might do so more than once during the adapter
	//! refresh period. This is equivalent to using SWAPEFFECT_COPY in DirectX
	//! 8. Present operations might be affected immediately. This option is
	//! always available for both windowed and full-screen swap chains.
	D3D9_PRESENT_INTERVAL_IMMEDIATE = 0x80000000,

	//! PRESENT_BACK_BUFFERS_MAX is the maximum
	//! number of back buffers supported in Direct3D 9.
	D3D9_PRESENT_BACK_BUFFERS_MAX = 3,
};
enum d3d9_presentflag_e
{
	//! PRESENTFLAG_DEVICECLIP clips a windowed Present blit into the window
	//! client area, within the monitor screen area of the video adapter that
	//! created the Direct3D device. PRESENTFLAG_DEVICECLIP is not valid with
	//! SWAPEFFECT_FLIPEX.
	//! NOTE: Clip the window blited into the client area 2k + xp only
	D3D9_PRESENTFLAG_DEVICECLIP = 0x00000004,

	//! PRESENTFLAG_DISCARD_DEPTHSTENCIL set this flag when the device or swap
	//! chain is created to enable z-buffer discarding. If this flag is set,
	//! the contents of the depth stencil buffer will be invalid after calling
	//! either Present OR SetDepthStencilSurface w/ a different depth surface.
	//! Discarding z-buffer data can increase performance and is driver
	//! dependent. The debug runtime will enforce discarding by clearing the
	//! z-buffer to some constant value after calling either Present, or
	//! SetDepthStencilSurface with a different depth surface.
	//! Discarding z-buffer data is illegal for all lockable formats,
	//! FMT_D16_LOCKABLE and FMT_D32F_LOCKABLE. Any use of CreateDevice
	//! specifying a lockable format and z-buffer discarding will fail.
	D3D9_PRESENTFLAG_DISCARD_DEPTHSTENCIL = 0x00000002, /* Discard Z buffer */

	//! PRESENTFLAG_LOCKABLE_BACKBUFFER set this flag if the application
	//! requires the ability to lock the back buffer directly.
	//! Note that back buffers are not lockable unless the application
	//! specifies PRESENTFLAG_LOCKABLE_BACKBUFFER when calling
	//! CreateDevice or Reset. Lockable back buffers incur
	//! a performance cost on some graphics hardware configurations.
	//! Performing a lock operation (or using UpdateSurface to write) on the
	//! lockable back buffer decreases performance on many cards. In this
	//! case, consider using textured triangles to move data to back buffer.
	D3D9_PRESENTFLAG_LOCKABLE_BACKBUFFER = 0x00000001,

	//! PRESENTFLAG_VIDEO is a hint to the driver that the back buffers will
	//! contain video data. (backbuffer 'may' contain video data)
	D3D9_PRESENTFLAG_VIDEO = 0x00000010,
};
enum d3d9_pshadecaps_e
{
	//! PSHADECAPS_ALPHAGOURAUDBLEND means the device can support an alpha
	//! component for Gouraud-blended transparency (the SHADE_GOURAUD state
	//! for the SHADEMODE enumerated type). In this mode, the alpha color
	//! component of a primitive is provided at vertices and interpolated
	//! across a face along with the other color components.
	D3D9_PSHADECAPS_ALPHAGOURAUDBLEND = 0x04000,

	//! PSHADECAPS_COLORGOURAUDRGB means the device can support colored
	//! Gouraud shading. In this mode, the per-vertex color components
	//! (red, green, and blue) are interpolated across a triangle face.
	D3D9_PSHADECAPS_COLORGOURAUDRGB = 0x00008,

	// PSHADECAPS_FOGGOURAUD means that the device
	// can support fog in the Gouraud shading mode.
	D3D9_PSHADECAPS_FOGGOURAUD = 0x80000,

	//! PSHADECAPS_SPECULARGOURAUDRGB means the device
	//! supports Gouraud shading of specular highlights.
	D3D9_PSHADECAPS_SPECULARGOURAUDRGB = 0x00200,
};
enum d3d9_ps20_e
{
	//! PS20_MAX_DYNAMICFLOWCONTROLDEPTH is the maximum level of
	//! nesting of dynamic flow control instructions (break, breakc, ifc).
	D3D9_PS20_MAX_DYNAMICFLOWCONTROLDEPTH = 24,

	//! PS20_MIN_DYNAMICFLOWCONTROLDEPTH is the minimum level of
	//! nesting of dynamic flow control instructions (break, breakc, ifc).
	D3D9_PS20_MIN_DYNAMICFLOWCONTROLDEPTH = 0,

	//! PS20_MAX_NUMTEMPS is the maximum number of supported temp. registers.
	D3D9_PS20_MAX_NUMTEMPS = 32,

	//! PS20_MIN_NUMTEMPS is the minimum number of supported temp. registers.
	D3D9_PS20_MIN_NUMTEMPS = 12,

	//! PS20_MAX_STATICFLOWCONTROLDEPTH is the maximum depth of nesting of
	//! the loop - vs/rep - vs and call - vs/callnz bool - vs instructions.
	D3D9_PS20_MAX_STATICFLOWCONTROLDEPTH = 4,

	//! PS20_MIN_STATICFLOWCONTROLDEPTH is the minimum depth of nesting of
	//! the loop - vs/rep - vs and call - vs/callnz bool - vs instructions.
	D3D9_PS20_MIN_STATICFLOWCONTROLDEPTH = 0,

	//! PS20_MAX_NUMINSTRUCTIONSLOTS is the
	//! maximum number of supported instructions.
	D3D9_PS20_MAX_NUMINSTRUCTIONSLOTS = 512,

	//! PS20_MIN_NUMINSTRUCTIONSLOTS is the
	//! minimum number of supported instructions.
	D3D9_PS20_MIN_NUMINSTRUCTIONSLOTS = 96,
};
enum d3d9_ptaddresscaps_e
{
	//! PTADDRESSCAPS_BORDER means the device supports setting coordinates
	//! outside the range [0.0, 1.0] to the border color, as specified by
	//! the SAMP_BORDERCOLOR texture-stage state.
	D3D9_PTADDRESSCAPS_BORDER = 0x08,

	//! PTADDRESSCAPS_CLAMP means the device can clamp textures to addresses.
	D3D9_PTADDRESSCAPS_CLAMP = 0x04,

	//! PTADDRESSCAPS_INDEPENDENTUV means the device can separate the
	//! texture-addressing modes of the u and v coordinates of the texture.
	//! This ability corresponds to the SAMP_ADDRESSU and SAMP_ADDRESSV
	//! render-state values.
	D3D9_PTADDRESSCAPS_INDEPENDENTUV = 0x10,

	//! PTADDRESSCAPS_MIRROR means device can mirror textures to addresses.
	D3D9_PTADDRESSCAPS_MIRROR = 0x02,

	//! PTADDRESSCAPS_MIRRORONCE means the device can
	//! take the absolute value of the texture coordinate
	//! (thus, mirroring around 0) and then clamp to the max. value.
	D3D9_PTADDRESSCAPS_MIRRORONCE = 0x20,

	//! PTADDRESSCAPS_WRAP means the device can wrap textures to addresses.
	D3D9_PTADDRESSCAPS_WRAP = 0x01,
};
enum d3d9_ptexturecaps_e
{
	//! PTEXTURECAPS_ALPHA means alpha in texture pixels is supported.
	D3D9_PTEXTURECAPS_ALPHA = 0x00000004,

	//! PTEXTURECAPS_ALPHAPALETTE means the device
	//! can draw alpha from texture palettes.
	D3D9_PTEXTURECAPS_ALPHAPALETTE = 0x00000080,

	//! PTEXTURECAPS_CUBEMAP means the device upports cube textures.
	D3D9_PTEXTURECAPS_CUBEMAP = 0x00000800,

	//! PTEXTURECAPS_CUBEMAP_POW2 means the device requires that
	//! cube texture maps have dimensions specified as powers of two.
	D3D9_PTEXTURECAPS_CUBEMAP_POW2 = 0x00020000,

	//! PTEXTURECAPS_MIPCUBEMAP means the device
	//! supports mipmapped cube textures.
	D3D9_PTEXTURECAPS_MIPCUBEMAP = 0x00010000,

	//! PTEXTURECAPS_MIPMAP means the device supports mipmapped textures.
	D3D9_PTEXTURECAPS_MIPMAP = 0x00004000,

	//! PTEXTURECAPS_MIPVOLUMEMAP means the device
	//! supports mipmapped volume textures.
	D3D9_PTEXTURECAPS_MIPVOLUMEMAP = 0x00008000,

	//! PTEXTURECAPS_NONPOW2CONDITIONAL means PTEXTURECAPS_POW2 is also set,
	//! conditionally supports the use of 2D textures with dimensions that
	//! are not powers of two. A device that exposes this capability can use
	//! such a texture if all of the following requirements are met.
	//! - The texture addressing mode for the texture stage is set to
	//! TADDRESS_CLAMP.
	//! - Texture wrapping for the texture stage is disabled
	//! (RS_WRAP n set to 0).
	//! - Mipmapping is not in use (use magnification filter only).
	//! - Texture formats must not be FMT_DXT1 through FMT_DXT5.
	//! If this flag is not set, and PTEXTURECAPS_POW2 is also not set,
	//! then unconditional support is provided for 2D textures
	//! with dimensions that are not powers of two.
	//! A texture that is not a power of two cannot be set at a stage that
	//! will be read based on a shader computation (such as the bem - ps and
	//! texm3x3 - ps instructions in pixel shaders versions 1_0 to 1_3).
	//! For example, these textures can be used to store bumps that will be
	//! fed into texture reads, but not the environment maps that are used in
	//! texbem - ps, texbeml - ps, and texm3x3spec - ps. This means that a
	//! texture with dimensions that are not powers of two cannot be addressed
	//! or sampled using texture coordinates computed within the shader.
	//! This type of operation is known as a dependent read
	//! and cannot be performed on these types of textures.
	D3D9_PTEXTURECAPS_NONPOW2CONDITIONAL = 0x00000100,

	//! PTEXTURECAPS_NOPROJECTEDBUMPENV means the device
	//! does not support a projected bump-environment loopkup
	//! operation in programmable and fixed function shaders.
	D3D9_PTEXTURECAPS_NOPROJECTEDBUMPENV = 0x00200000,

	//! PTEXTURECAPS_PERSPECTIVE means perspective
	//! correction texturing is supported.
	D3D9_PTEXTURECAPS_PERSPECTIVE = 0x00000001,

	//! PTEXTURECAPS_POW2 means that if PTEXTURECAPS_NONPOW2CONDITIONAL is not
	//! set, all textures must have widths and heights specified as powers of
	//! two. This requirement does not apply to either cube textures or volume
	//! textures.
	//! If PTEXTURECAPS_NONPOW2CONDITIONAL is also set, conditionally supports
	//! the use of 2D textures with dimensions that are not powers of two. See
	//! PTEXTURECAPS_NONPOW2CONDITIONAL description.
	//! If this flag is not set, and PTEXTURECAPS_NONPOW2CONDITIONAL is also
	//! not set, then unconditional support is provided for 2D textures with
	//! dimensions that are not powers of two.
	D3D9_PTEXTURECAPS_POW2 = 0x00000002,

	//! PTEXTURECAPS_PROJECTED means the device supports the TTFF_PROJECTED
	//! texture transformation flag. When applied, the device divides
	//! transformed texture coordinates by the last texture coordinate.
	//! If this capability is present, then the projective divide occurs
	//! per pixel. If this capability is not present, but the projective
	//! divide needs to occur anyway, then it is performed
	//! on a per-vertex basis by the Direct3D runtime.
	D3D9_PTEXTURECAPS_PROJECTED = 0x00000400,

	//! PTEXTURECAPS_SQUAREONLY means all textures must be square.
	D3D9_PTEXTURECAPS_SQUAREONLY = 0x00000020,

	//! PTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE means texture indices are not
	//! scaled by the texture size prior to interpolation.
	D3D9_PTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE = 0x00000040,

	//! PTEXTURECAPS_VOLUMEMAP means the device supports volume textures.
	D3D9_PTEXTURECAPS_VOLUMEMAP = 0x00002000,

	//! PTEXTURECAPS_VOLUMEMAP_POW2 means the device requires that volume
	//! texture maps have dimensions specified as powers of two.
	D3D9_PTEXTURECAPS_VOLUMEMAP_POW2 = 0x00040000,
};
enum d3d9_ptfiltercaps_e
{
	//! PTFILTERCAPS_MAGFPOINT means the device supports per-stage
	//! point-sample filtering for magnifying textures.
	//! The point-sample magnification filter is represented by the
	//! TEXF_POINT member of the TEXTUREFILTERTYPE enumerated type.
	D3D9_PTFILTERCAPS_MAGFPOINT = 0x01000000,

	//! PTFILTERCAPS_MAGFLINEAR means the device supports per-stage bilinear
	//! interpolation filtering for magnifying mipmaps. The bilinear
	//! interpolation mipmapping filter is represented by the
	//! TEXF_LINEAR member of the TEXTUREFILTERTYPE enumerated type.
	D3D9_PTFILTERCAPS_MAGFLINEAR = 0x02000000,

	//! PTFILTERCAPS_MAGFANISOTROPIC means the device supports per-stage
	//! anisotropic filtering for magnifying textures. The anisotropic
	//! magnification filter is represented by the
	//! TEXF_ANISOTROPIC member of the TEXTUREFILTERTYPE enumerated type.
	D3D9_PTFILTERCAPS_MAGFANISOTROPIC = 0x04000000,

	//! PTFILTERCAPS_MAGFPYRAMIDALQUAD means the device supports per-stage
	//! pyramidal sample filtering for magnifying textures. The pyramidal
	//! magnifying filter is represented by the
	//! TEXF_PYRAMIDALQUAD member of the TEXTUREFILTERTYPE enumerated type.
	D3D9_PTFILTERCAPS_MAGFPYRAMIDALQUAD = 0x08000000,

	//! PTFILTERCAPS_MAGFGAUSSIANQUAD means the device supports
	//! per-stage Gaussian quad filtering for magnifying textures.
	D3D9_PTFILTERCAPS_MAGFGAUSSIANQUAD = 0x10000000,

	//! PTFILTERCAPS_MINFPOINT means the device supports
	//! per-stage point-sample filtering for minifying textures.
	//! The point-sample minification filter is represented by the
	//! TEXF_POINT member of the TEXTUREFILTERTYPE enumerated type.
	D3D9_PTFILTERCAPS_MINFPOINT = 0x00000100,

	//! PTFILTERCAPS_MINFLINEAR means the device supports per-stage linear
	//! filtering for minifying textures. The linear minification filter
	//! is represented by the TEXF_LINEAR member of the TEXTUREFILTERTYPE
	//! enumerated type.
	D3D9_PTFILTERCAPS_MINFLINEAR = 0x00000200,

	//! PTFILTERCAPS_MINFANISOTROPIC means the device supports
	//! per-stage anisotropic filtering for minifying textures.
	//! The anisotropic minification filter is represented by the
	//! TEXF_ANISOTROPIC member of the TEXTUREFILTERTYPE enumerated type.
	D3D9_PTFILTERCAPS_MINFANISOTROPIC = 0x00000400,

	//! PTFILTERCAPS_MINFPYRAMIDALQUAD means the device supports
	//! per-stage pyramidal sample filtering for minifying textures.
	D3D9_PTFILTERCAPS_MINFPYRAMIDALQUAD = 0x00000800,

	//! PTFILTERCAPS_MINFGAUSSIANQUAD means the device supports
	//! per-stage Gaussian quad filtering for minifying textures.
	D3D9_PTFILTERCAPS_MINFGAUSSIANQUAD = 0x00001000,

	//! PTFILTERCAPS_MIPFPOINT means the device supports
	//! per-stage point-sample filtering for mipmaps.
	//! The point-sample mipmapping filter is represented by the
	//! TEXF_POINT member of the TEXTUREFILTERTYPE enumerated type.
	D3D9_PTFILTERCAPS_MIPFPOINT = 0x00010000,

	//! PTFILTERCAPS_MIPFLINEAR means the device supports per-stage bilinear
	//! interpolation filtering for mipmaps. The bilinear interpolation
	//! mipmapping filter is represented by the TEXF_LINEAR member of the
	//! TEXTUREFILTERTYPE enumerated type.
	D3D9_PTFILTERCAPS_MIPFLINEAR = 0x00020000,
};
enum d3d9_spd_e
{
	//! SPD_IUNKNOWN is used in Resource.SetPrivateData. The data at is a
	//! pointer to an IUnknown interface. The size parameter must be set
	//! to the size of a pointer to IUnknown. Direct3D automatically calls
	//! IUnknown through the data pointer when the private data is destroyed.
	//! Private data will be destroyed by a subsequent call to
	//! Resource.SetPrivateData with the same GUID, a subsequent call to
	//! Resource.FreePrivateData, or when the Direct3D object is released.
	D3D9_SPD_IUNKNOWN = 0x00000001,
};
enum d3d9_stencilcaps_e
{
	//! STENCILCAPS_KEEP does not update the entry in the stencil buffer.
	//! This is the default value.
	D3D9_STENCILCAPS_KEEP = 0x01,

	//! STENCILCAPS_ZERO sets the stencil-buffer entry to 0.
	D3D9_STENCILCAPS_ZERO = 0x02,

	//! STENCILCAPS_REPLACE replaces the stencil-buffer entry,
	//! with reference value.
	D3D9_STENCILCAPS_REPLACE = 0x04,

	//! STENCILCAPS_INCRSAT increments the stencil-buffer entry,
	//! clamping to the maximum value.
	D3D9_STENCILCAPS_INCRSAT = 0x08,

	//! STENCILCAPS_DECRSAT decrements the stencil-buffer entry,
	//! clamping to zero.
	D3D9_STENCILCAPS_DECRSAT = 0x10,

	//! STENCILCAPS_INVERT inverts the bits in the stencil-buffer entry.
	D3D9_STENCILCAPS_INVERT = 0x20,

	//! STENCILCAPS_INCR increments the stencil-buffer entry,
	//! wrapping to zero if the new value exceeds the maximum value.
	D3D9_STENCILCAPS_INCR = 0x40,

	//! STENCILCAPS_DECR decrements the stencil-buffer entry,
	//! wrapping to the maximum value if the new value is less than zero.
	D3D9_STENCILCAPS_DECR = 0x80,

	//! STENCILCAPS_TWOSIDED means the device supports two-sided stencil.
	D3D9_STENCILCAPS_TWOSIDED = 0x100,
};
enum d3d9_ta_e
{
	//! TA_CONSTANT selects a constant from a texture stage.
	//! The default value is 0xFFFFFFFF.
	D3D9_TA_CONSTANT = 0x00000006,

	//! TA_CURRENT means the texture argument is the result of the previous
	//! blending stage. In the first texture stage (stage 0), this argument
	//! is equivalent to TA_DIFFUSE. If the previous blending stage uses a
	//! bump-map texture (the TOP_BUMPENVMAP operation), the system chooses
	//! the texture from the stage before the bump-map texture.
	//! If s represents the current texture stage and s - 1 contains
	//! a bump-map texture, this argument becomes the result output
	//! by texture stage s - 2. Permissions are read/write.
	D3D9_TA_CURRENT = 0x00000001,

	//! TA_DIFFUSE means the texture argument is the diffuse color
	//! interpolated from vertex components during Gouraud shading.
	//! If the vertex does not contain a diffuse color,
	//! the default color is 0xFFFFFFFF. Permissions are read-only.
	D3D9_TA_DIFFUSE = 0x00000000,

	//! TA_SELECTMASK is a mask value for all arguments;
	//! not used when setting texture arguments.
	D3D9_TA_SELECTMASK = 0x0000000f,

	//! TA_SPECULAR means the texture argument is the specular color
	//! interpolated from vertex components during Gouraud shading.
	//! If the vertex does not contain a specular color,
	//! the default color is 0xFFFFFFFF. Permissions are read-only.
	D3D9_TA_SPECULAR = 0x00000004,

	//! TA_TEMP means the texture argument is a temporary register color for
	//! read or write. TA_TEMP is supported if the PMISCCAPS_TSSARGTEMP
	//! device capability is present. The default value for the register
	//! is (0.0, 0.0, 0.0, 0.0). Permissions are read/write.
	D3D9_TA_TEMP = 0x00000005,

	//! TA_TEXTURE means the texture argument is the texture color
	//! for this texture stage. Permissions are read-only.
	D3D9_TA_TEXTURE = 0x00000002,

	//! TA_TFACTOR means the texture argument is the texture factor set in a
	//! previous call to the SetRenderState with the RS_TEXTUREFACTOR
	//! render-state value. Permissions are read-only.
	D3D9_TA_TFACTOR = 0x00000003,

	//! TA_ALPHAREPLICATE replicates the alpha information to all color
	//! channels before the operation completes. This is a read modifier.
	D3D9_TA_ALPHAREPLICATE = 0x00000020,

	//! TA_COMPLEMENT takes the complement of the argument x, (1.0 - x).
	//! This is a read modifier.
	D3D9_TA_COMPLEMENT = 0x00000010,
};
enum d3d9_texopcaps_e
{
	//! TEXOPCAPS_ADD means 'TOP_ADD' texture-blending operation is supported.
	D3D9_TEXOPCAPS_ADD = 0x0000040,

	//! TEXOPCAPS_ADDSIGNED means the TOP_ADDSIGNED
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_ADDSIGNED = 0x0000080,

	//! TEXOPCAPS_ADDSIGNED2X means the TOP_ADDSIGNED2X
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_ADDSIGNED2X = 0x0000100,

	//! TEXOPCAPS_ADDSMOOTH means the TOP_ADDSMOOTH
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_ADDSMOOTH = 0x0000400,

	//! TEXOPCAPS_BLENDCURRENTALPHA means the TOP_BLENDCURRENTALPHA
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_BLENDCURRENTALPHA = 0x0008000,

	//! TEXOPCAPS_BLENDDIFFUSEALPHA means the TOP_BLENDDIFFUSEALPHA
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_BLENDDIFFUSEALPHA = 0x0000800,

	//! TEXOPCAPS_BLENDFACTORALPHA means the TOP_BLENDFACTORALPHA
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_BLENDFACTORALPHA = 0x0002000,

	//! TEXOPCAPS_BLENDTEXTUREALPHA means the TOP_BLENDTEXTUREALPHA
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_BLENDTEXTUREALPHA = 0x0001000,

	//! TEXOPCAPS_BLENDTEXTUREALPHAPM means the TOP_BLENDTEXTUREALPHAPM
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_BLENDTEXTUREALPHAPM = 0x0004000,

	//! TEXOPCAPS_BUMPENVMAP means the TOP_BUMPENVMAP
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_BUMPENVMAP = 0x0200000,

	//! TEXOPCAPS_BUMPENVMAPLUMINANCE means the TOP_BUMPENVMAPLUMINANCE
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_BUMPENVMAPLUMINANCE = 0x0400000,

	//! TEXOPCAPS_DISABLE means the TOP_DISABLE
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_DISABLE = 0x0000001,

	//! TEXOPCAPS_DOTPRODUCT3 means the TOP_DOTPRODUCT3
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_DOTPRODUCT3 = 0x0800000,

	//! TEXOPCAPS_LERP means the TOP_LERP
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_LERP = 0x2000000,

	//! TEXOPCAPS_MODULATE means the TOP_MODULATE
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_MODULATE = 0x0000008,

	//! TEXOPCAPS_MODULATE2X means the TOP_MODULATE2X
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_MODULATE2X = 0x0000010,

	//! TEXOPCAPS_MODULATE4X means the TOP_MODULATE4X
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_MODULATE4X = 0x0000020,

	//! TEXOPCAPS_MODULATEALPHA_ADDCOLOR means the TOP_MODULATEALPHA_ADDCOLOR
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_MODULATEALPHA_ADDCOLOR = 0x0020000,

	//! TEXOPCAPS_MODULATECOLOR_ADDALPHA means the TOP_MODULATECOLOR_ADDALPHA
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_MODULATECOLOR_ADDALPHA = 0x0040000,

	//! TEXOPCAPS_MODULATEINVALPHA_ADDCOLOR means the
	//! TOP_MODULATEINVALPHA_ADDCOLOR texture-blending operation is supported.
	D3D9_TEXOPCAPS_MODULATEINVALPHA_ADDCOLOR = 0x0080000,

	//! TEXOPCAPS_MODULATEINVCOLOR_ADDALPHA means the
	//! TOP_MODULATEINVCOLOR_ADDALPHA texture-blending operation is supported.
	D3D9_TEXOPCAPS_MODULATEINVCOLOR_ADDALPHA = 0x0100000,

	//! TEXOPCAPS_MULTIPLYADD means the TOP_MULTIPLYADD
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_MULTIPLYADD = 0x1000000,

	//! TEXOPCAPS_PREMODULATE means the TOP_PREMODULATE
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_PREMODULATE = 0x0010000,

	//! TEXOPCAPS_SELECTARG1 means the TOP_SELECTARG1
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_SELECTARG1 = 0x0000002,

	//! TEXOPCAPS_SELECTARG2 means the TOP_SELECTARG2
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_SELECTARG2 = 0x0000004,

	//! TEXOPCAPS_SUBTRACT means the TOP_SUBTRACT
	//! texture-blending operation is supported.
	D3D9_TEXOPCAPS_SUBTRACT = 0x0000200,
};
enum d3d9_tss_tci_e
{
	//! TSS_TCI_PASSTHRU uses the specified texture coordinates
	//! contained within the vertex format. This value resolves to zero.
	D3D9_TSS_TCI_PASSTHRU = 0x00000,

	//! TSS_TCI_CAMERASPACENORMAL uses the vertex normal, transformed to
	//! camera space, as the input texture coordinates for this stage's
	//! texture transformation.
	D3D9_TSS_TCI_CAMERASPACENORMAL = 0x10000,

	//! TSS_TCI_CAMERASPACEPOSITION uses the vertex position, transformed
	//! to camera space, as the input texture coordinates for this stage's
	//! texture transformation.
	D3D9_TSS_TCI_CAMERASPACEPOSITION = 0x20000,

	//! TSS_TCI_CAMERASPACEREFLECTIONVECTOR uses the reflection vector,
	//! transformed to camera space, as the input texture coordinate for this
	//! stage's texture transformation. The reflection vector is computed from
	//! the input vertex position and normal vector.
	D3D9_TSS_TCI_CAMERASPACEREFLECTIONVECTOR = 0x30000,

	//! TSS_TCI_SPHEREMAP uses the specified texture coordinates for sphere
	//! mapping.
	D3D9_TSS_TCI_SPHEREMAP = 0x40000,
};
enum d3d9_usage_e
{
	//! USAGE_AUTOGENMIPMAP means the resource will automatically generate
	//! mipmaps. See Automatic Generation of Mipmaps (Direct3D 9). Automatic
	//! generation of mipmaps is not supported for volume textures and depth
	//! stencil surfaces/textures. This usage is not valid for a resource in
	//! system memory (POOL_SYSTEMMEM).
	D3D9_USAGE_AUTOGENMIPMAP = 0x00000400,

	//! USAGE_DEPTHSTENCIL means the resource will be a depth stencil buffer.
	//! USAGE_DEPTHSTENCIL can only be used with POOL_DEFAULT.
	D3D9_USAGE_DEPTHSTENCIL = 0x00000002,

	//! USAGE_DMAP means the resource will be a displacement map.
	D3D9_USAGE_DMAP = 0x00004000,

	//! USAGE_DONOTCLIP indicates that the vertex buffer content will never
	//! require clipping. When rendering with buffers that have this flag set,
	//! the RS_CLIPPING render state must be set to false.
	D3D9_USAGE_DONOTCLIP = 0x00000020,

	//! USAGE_DYNAMIC indicates that the vertex buffer requires dynamic memory
	//! use. This is useful for drivers because it enables them to decide
	//! where to place the buffer. In general, static vertex buffers are
	//! placed in video memory and dynamic vertex buffers are placed in AGP
	//! memory. Note that there's no separate static use. If you don't specify
	//! USAGE_DYNAMIC, the vertex buffer is made static. USAGE_DYNAMIC is
	//! strictly enforced through LOCK_DISCARD and LOCK_NOOVERWRITE locking
	//! flags. As a result, LOCK_DISCARD and LOCK_NOOVERWRITE are valid only
	//! on vertex buffers created with USAGE_DYNAMIC.
	//! They are not valid flags on static vertex buffers.
	//! USAGE_DYNAMIC and POOL_MANAGED are incompatible
	//! and should not be used together. Textures can specify USAGE_DYNAMIC.
	//! However, managed textures cannot use USAGE_DYNAMIC.
	D3D9_USAGE_DYNAMIC = 0x00000200,

	//! USAGE_NPATCHES indicates that the
	//! vertex buffer is to be used for drawing N-patches.
	D3D9_USAGE_NPATCHES = 0x00000100,

	//! USAGE_POINTS indicates that the vertex or index buffer will be used
	//! for drawing point sprites. The buffer will be loaded in system memory
	//! if software vertex processing is needed to emulate point sprites.
	D3D9_USAGE_POINTS = 0x00000040,

	//! USAGE_RENDERTARGET means the resource will be a render target.
	//! USAGE_RENDERTARGET can only be used with POOL_DEFAULT.
	D3D9_USAGE_RENDERTARGET = 0x00000001,

	//! USAGE_RTPATCHES indicates that the vertex buffer
	//! is to be used for drawing high-order primitives.
	D3D9_USAGE_RTPATCHES = 0x00000080,

	//! USAGE_SOFTWAREPROCESSING if this flag is used,
	//! vertex processing is done in software.
	//! If this flag is not used, vertex processing is done in hardware.
	//! The USAGE_SOFTWAREPROCESSING flag can be set when mixed-mode
	//! or software vertex processing (CREATE_MIXED_VERTEXPROCESSING /
	//! CREATE_SOFTWARE_VERTEXPROCESSING) is enabled for that device.
	//! USAGE_SOFTWAREPROCESSING must be set for buffers to be used with
	//! software vertex processing in mixed mode, but it should not be set for
	//! the best possible performance when using hardware index processing in
	//! mixed mode (CREATE_HARDWARE_VERTEXPROCESSING). However, setting
	//! USAGE_SOFTWAREPROCESSING is the only option when a single buffer is
	//! used with both hardware and software vertex processing.
	//! USAGE_SOFTWAREPROCESSING is allowed for mixed and software devices.
	//! USAGE_SOFTWAREPROCESSING is used with CheckDeviceFormat to find out
	//! if a particular texture format can be used as a vertex texture during
	//! software vertex processing. If it can, the texture must be created in
	//! POOL_SCRATCH.
	D3D9_USAGE_SOFTWAREPROCESSING = 0x00000010,

	//! USAGE_WRITEONLY informs the system that the application writes only to
	//! the vertex buffer. Using this flag enables the driver to choose the
	//! best memory location for efficient write operations and rendering.
	//! Attempts to read from a vertex buffer that is created with this
	//! capability will fail. Buffers created with POOL_DEFAULT that do
	//! not specify USAGE_WRITEONLY may suffer a severe performance penalty.
	//! USAGE_WRITEONLY only affects the performance of POOL_DEFAULT buffers.
	D3D9_USAGE_WRITEONLY = 0x00000008,
};
enum d3d9_usage_query_e
{
	//! USAGE_QUERY_FILTER queries the resource format to see if it supports
	//! texture filter types other than TEXF_POINT (which's always supported).
	D3D9_USAGE_QUERY_FILTER = 0x00020000,

	//! USAGE_QUERY_LEGACYBUMPMAP queries the resource about a legacy bumpmap.
	D3D9_USAGE_QUERY_LEGACYBUMPMAP = 0x00008000,

	//! USAGE_QUERY_POSTPIXELSHADER_BLENDING queries the resource to verify
	//! support for post pixel shader blending support. If CheckDeviceFormat
	//! fails with USAGE_QUERY_POSTPIXELSHADER_BLENDING, post pixel blending
	//! operations are not supported. These include alpha test, pixel fog,
	//! render-target blending, color write enable, and dithering.
	D3D9_USAGE_QUERY_POSTPIXELSHADER_BLENDING = 0x00080000,

	//! USAGE_QUERY_SRGBREAD queries the resource to verify if a
	//! texture supports gamma correction during a read operation.
	D3D9_USAGE_QUERY_SRGBREAD = 0x00010000,

	//! USAGE_QUERY_SRGBWRITE queries the resource to verify if a
	//! texture supports gamma correction during a write operation.
	D3D9_USAGE_QUERY_SRGBWRITE = 0x00040000,

	//! USAGE_QUERY_VERTEXTEXTURE queries the resource to
	//! verify support for vertex shader texture sampling.
	D3D9_USAGE_QUERY_VERTEXTEXTURE = 0x00100000,

	//! USAGE_QUERY_WRAPANDMIP queries the resource to
	//! verify support for texture wrapping and mip-mapping.
	D3D9_USAGE_QUERY_WRAPANDMIP = 0x00200000,
};
enum d3d9_vertextexturesampler_e
{
	//! VERTEXTEXTURESAMPLER0 identifies the
	//! texture sampler used by vertex shaders.
	D3D9_VERTEXTEXTURESAMPLER0 = ( D3D9_DMAPSAMPLER + 1 ),

	//! VERTEXTEXTURESAMPLER1 identifies the
	//! texture sampler used by vertex shaders.
	D3D9_VERTEXTEXTURESAMPLER1 = ( D3D9_DMAPSAMPLER + 2 ),

	//! VERTEXTEXTURESAMPLER2 identifies the
	//! texture sampler used by vertex shaders.
	D3D9_VERTEXTEXTURESAMPLER2 = ( D3D9_DMAPSAMPLER + 3 ),

	//! VERTEXTEXTURESAMPLER3 identifies the
	//! texture sampler used by vertex shaders.
	D3D9_VERTEXTEXTURESAMPLER3 = ( D3D9_DMAPSAMPLER + 4 ),
};
enum d3d9_vs20_e
{
	//! VS20CAPS_PREDICATION indicates that instruction
	//! predication is supported. See setp_comp - vs.
	D3D9_VS20CAPS_PREDICATION = ( 1 << 0 ),

	//! VS20_MAX_DYNAMICFLOWCONTROLDEPTH is the maximum level of nesting of
	//! dynamic flow control instructions (break - vs, break_comp - vs,
	//! breakp - vs, if_comp - vs, if_comp - vs, if pred - vs).
	D3D9_VS20_MAX_DYNAMICFLOWCONTROLDEPTH = 24,

	//! VS20_MIN_DYNAMICFLOWCONTROLDEPTH is the minimum level of nesting of
	//! dynamic flow control instructions (break - vs, break_comp - vs,
	//! breakp - vs, if_comp - vs, if_comp - vs, if pred - vs).
	D3D9_VS20_MIN_DYNAMICFLOWCONTROLDEPTH = 0,

	//! VS20_MAX_NUMTEMPS is the maximum number of temp. registers supported.
	D3D9_VS20_MAX_NUMTEMPS = 32,

	//! VS20_MIN_NUMTEMPS is the minimum number of temp. registers supported.
	D3D9_VS20_MIN_NUMTEMPS = 12,

	//! VS20_MAX_STATICFLOWCONTROLDEPTH is the maximum depth of nesting of
	//! the loop - vs/rep - vs and call - vs/callnz bool - vs instructions.
	D3D9_VS20_MAX_STATICFLOWCONTROLDEPTH = 4,

	//! VS20_MIN_STATICFLOWCONTROLDEPTH is the minimum depth of nesting of
	//! the loop - vs/rep - vs and call - vs/callnz bool - vs instructions.
	D3D9_VS20_MIN_STATICFLOWCONTROLDEPTH = 1,
};
enum d3d9_vtxpcaps_e
{
	//! VTXPCAPS_DIRECTIONALLIGHTS means the device can do directional lights.
	D3D9_VTXPCAPS_DIRECTIONALLIGHTS = 0x00000008,

	//! VTXPCAPS_LOCALVIEWER means the device can do local viewer.
	D3D9_VTXPCAPS_LOCALVIEWER = 0x00000020,

	//! VTXPCAPS_MATERIALSOURCE7 means the device supports the color material
	//! states: RS_AMBIENTMATERIALSOURCE, RS_DIFFUSEMATERIALSOURCE,
	//! RS_EMISSIVEMATERIALSOURCE, and RS_SPECULARMATERIALSOURCE.
	D3D9_VTXPCAPS_MATERIALSOURCE7 = 0x00000002,

	//! VTXPCAPS_NO_TEXGEN_NONLOCALVIEWER means the device does not support
	//! texture generation in non-local viewer mode.
	D3D9_VTXPCAPS_NO_TEXGEN_NONLOCALVIEWER = 0x00000200,

	//! VTXPCAPS_POSITIONALLIGHTS means the device can do positional lights
	//! (includes point and spot).
	D3D9_VTXPCAPS_POSITIONALLIGHTS = 0x00000010,

	//! VTXPCAPS_TEXGEN means the device can do texgen.
	D3D9_VTXPCAPS_TEXGEN = 0x00000001,

	//! VTXPCAPS_TEXGEN_SPHEREMAP means the device supports TSS_TCI_SPHEREMAP.
	D3D9_VTXPCAPS_TEXGEN_SPHEREMAP = 0x00000100,

	//! VTXPCAPS_TWEENING means the device can do vertex tweening.
	D3D9_VTXPCAPS_TWEENING = 0x00000040,
};
enum d3d9_s_present_e
{
	//! S_PRESENT_OCCLUDED indicates that the presentation area is occluded.
	//! Occlusion means that the presentation window is minimized or another
	//! device entered the fullscreen mode on the same monitor as the
	//! presentation window and the presentation window is completely on that
	//! monitor. Occlusion will not occur if the client area is covered by
	//! another Window.
	//! Occluded applications can continue rendering and all calls will
	//! succeed, but the occluded presentation window will not be updated.
	//! Preferably the application should stop rendering to the presentation
	//! window using the device and keep calling CheckDeviceState until S_OK
	//! or S_PRESENT_MODE_CHANGED returns.
	//! Direct3D 9Ex only.
	D3D9_S_PRESENT_OCCLUDED = 141953144,

	//! S_PRESENT_MODE_CHANGED indicates that the desktop displaymode has been
	//! changed. The application can continue rendering, but there might be
	//! color conversion/stretching. Pick a back buffer format similar to the
	//! current display mode, and call Reset to recreate the swap chains. The
	//! device will leave this state after a Reset is called.
	//! Direct3D 9Ex only.
	D3D9_S_PRESENT_MODE_CHANGED = 141953143,
};
enum d3d9_clipplane_e
{
	//! CLIPPLANE0 can be used to enable user-defined clipping plane 0.
	//! It is defined as a convenience when setting values for the
	//! RS_CLIPPLANEENABLE render state.
	D3D9_CLIPPLANE0 = ( 1 << 0 ),

	//! CLIPPLANE1 can be used to enable user-defined clipping plane 1.
	//! It is defined as a convenience when setting values for the
	//! RS_CLIPPLANEENABLE render state.
	D3D9_CLIPPLANE1 = ( 1 << 1 ),

	//! CLIPPLANE2 can be used to enable user-defined clipping plane 2.
	//! It is defined as a convenience when setting values for the
	//! RS_CLIPPLANEENABLE render state.
	D3D9_CLIPPLANE2 = ( 1 << 2 ),

	//! CLIPPLANE3 can be used to enable user-defined clipping plane 3.
	//! It is defined as a convenience when setting values for the
	//! RS_CLIPPLANEENABLE render state.
	D3D9_CLIPPLANE3 = ( 1 << 3 ),

	//! CLIPPLANE4 can be used to enable user-defined clipping plane 4.
	//! It is defined as a convenience when setting values for the
	//! RS_CLIPPLANEENABLE render state.
	D3D9_CLIPPLANE4 = ( 1 << 4 ),

	//! CLIPPLANE5 can be used to enable user-defined clipping plane 5.
	//! It is defined as a convenience when setting values for the
	//! RS_CLIPPLANEENABLE render state.
	D3D9_CLIPPLANE5 = ( 1 << 5 ),
};
enum d3d9_issue_e
{
	//! ISSUE_BEGIN is a value used by Issue to issue a query begin.
	D3D9_ISSUE_BEGIN = ( 1 << 1 ),

	//! ISSUE_END is a value used by Issue to issue a query end.
	D3D9_ISSUE_END = ( 1 << 0 ),
};
enum d3d9_getdata_e
{
	//! GETDATA_FLUSH is the value passed to GetData to flush query data.
	D3D9_GETDATA_FLUSH = ( 1 << 0 ),
};


//! BACKBUFFER_TYPE defines constants that describe the type of a back buffer
enum d3d9_backbuffer_type_e
{
	//! BACKBUFFER_TYPE_MONO specifies a nonstereo swap chain.
	e_d3d9_backbuffer_type_mono = 0,

	//! BACKBUFFER_TYPE_LEFT specifies the left
	//! side of a stereo pair in a swap chain.
	e_d3d9_backbuffer_type_left = 1,

	//! BACKBUFFER_TYPE_RIGHT specifies the right
	//! side of a stereo pair in a swap chain.
	e_d3d9_backbuffer_type_right = 2
};

//! ENUM 'e_d3d9_backbuffer_type_' describe the types of a back buffer
typedef u32 d3d9_backbuffer_type_t;


//! BASISTYPE define the basis type of a high-order patch surface
enum d3d9_basis_e
{
	//! BASIS_BEZIER means input vertices are treated as a series of B�zier
	//! patches. The number of vertices specified must be divisible by 4.
	//! Portions of the mesh beyond this criterion will not be rendered.
	//! Full continuity is assumed between sub-patches in the interior
	//! of the surface rendered by each call. Only the vertices at the corners
	//! of each sub-patch are guaranteed to lie on the resulting surface.
	e_d3d9_basis_bezier = 0,

	//! BASIS_BSPLINE means input vertices are treated as control points of a
	//! B-spline surface. The number of apertures rendered is two fewer than
	//! the number of apertures in that direction. In general, the generated
	//! surface does not contain the control vertices specified.
	e_d3d9_basis_bspline = 1,

	//! BASIS_CATMULL_ROM means an interpolating basis defines the surface
	//! so that the surface goes through all the input vertices specified.
	//! In DirectX 8, this was BASIS_INTERPOLATE.
	e_d3d9_basis_catmull_rom = 2,
};

//! ENUM 'e_d3d9_basis_' define the basis type of high-order patch surfaces
typedef u32 d3d9_basistype_t;


//! BLEND defines the supported blend mode
enum d3d9_blend_e
{
	//! BLEND_ZERO Blend factor is (0, 0, 0, 0).
	e_d3d9_blend_zero = 1,

	//! BLEND_ONE Blend factor is (1, 1, 1, 1).
	e_d3d9_blend_one = 2,

	//! BLEND_SRCCOLOR Blend factor is (Rs, Gs, Bs, As).
	e_d3d9_blend_srccolor = 3,

	//! BLEND_INVSRCCOLOR Blend factor is (1 - Rs, 1 - Gs, 1 - Bs, 1 - As).
	e_d3d9_blend_invsrccolor = 4,

	//! BLEND_SRCALPHA Blend factor is (As, As, As, As).
	e_d3d9_blend_srcalpha = 5,

	//! BLEND_INVSRCALPHA Blend factor is ( 1 - As, 1 - As, 1 - As, 1 - As).
	e_d3d9_blend_invsrcalpha = 6,

	//! BLEND_DESTALPHA Blend factor is (Ad, Ad, Ad, Ad).
	e_d3d9_blend_destalpha = 7,

	//! BLEND_INVDESTALPHA Blend factor is (1 - Ad, 1 - Ad, 1 - Ad, 1 - Ad).
	e_d3d9_blend_invdestalpha = 8,

	//! BLEND_DESTCOLOR Blend factor is (Rd, Gd, Bd, Ad).
	e_d3d9_blend_destcolor = 9,

	//! BLEND_INVDESTCOLOR Blend factor is (1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad).
	e_d3d9_blend_invdestcolor = 10,

	//! BLEND_SRCALPHASAT Blend factor is (f, f, f, 1);
	//! where f = min(As, 1 - Ad).
	e_d3d9_blend_srcalphasat = 11,

	//! BLEND_BOTHSRCALPHA is obsolete. Starting with DirectX 6, you can
	//! achieve the same effect by setting the source and destination blend
	//! factors to BLEND_SRCALPHA and BLEND_INVSRCALPHA in separate calls.
	e_d3d9_blend_bothsrcalpha = 12,

	//! BLEND_BOTHINVSRCALPHA is obsolete. Source blend factor is
	//! (1 - As, 1 - As, 1 - As, 1 - As), and destination blend factor is
	//! (As, As, As, As); the destination blend selection is overridden.
	//! This blend mode is supported only for the RS_SRCBLEND render state.
	e_d3d9_blend_bothinvsrcalpha = 13,

	//! BLEND_BLENDFACTOR is a constant color blending factor used by the
	//! frame-buffer blender. This blend mode is supported only if
	//! PBLENDCAPS_BLENDFACTOR is set in the SrcBlendCaps or DestBlendCaps
	//! members of CAPS.
	e_d3d9_blend_blendfactor = 14,

	//! BLEND_INVBLENDFACTOR is an inverted constant color-blending factor
	//! used by the frame-buffer blender. This blend mode is supported only
	//! if the PBLENDCAPS_BLENDFACTOR bit is set in the
	//! SrcBlendCaps or DestBlendCaps members of CAPS.
	e_d3d9_blend_invblendfactor = 15,
};

//! ENUM 'e_d3d9_blend_' define the supported blend modes
typedef u32 d3d9_blend_t;


//! BLENDOP defines the supported blend operations
enum d3d9_blendop_e
{
	//! BLENDOP_ADD means the result is the destination added to the source.
	//! Result = Source + Destination
	e_d3d9_blendop_add = 1,

	//! BLENDOP_SUBTRACT means the result is the destination
	//! subtracted from to the source. Result = Source - Destination
	e_d3d9_blendop_subtract = 2,

	//! BLENDOP_REVSUBTRACT means the result is the source
	//! subtracted from the destination. Result = Destination - Source
	e_d3d9_blendop_revsubtract = 3,

	//! BLENDOP_MIN means the result is the min. of the source
	//! and the destination. Result = MIN(Source, Destination)
	e_d3d9_blendop_min = 4,

	//! BLENDOP_MAX means the result is the max. of the source
	//! and the destination. Result = MAX(Source, Destination)
	e_d3d9_blendop_max = 5,
};

//! ENUM 'e_d3d9_blendop_' define the supported blend operations
typedef u32 d3d9_blendop_t;


//! CMPFUNC define the supported compare functions
enum d3d9_cmpfunc_e
{
	//! CMP_NEVER always fails the test.
	e_d3d9_cmp_never = 1,

	//! CMP_LESS accepts the new pixel if its value is less than
	//! the value of the current pixel.
	e_d3d9_cmp_less = 2,

	//! CMP_EQUAL accepts the new pixel if its value equals
	//! the value of the current pixel.
	e_d3d9_cmp_equal = 3,

	//! CMP_LESSEQUAL accepts the new pixel if its value is less than
	//! or equal to the value of the current pixel.
	e_d3d9_cmp_lessequal = 4,

	//! CMP_GREATER accepts the new pixel if its value is greater than
	//! the value of the current pixel.
	e_d3d9_cmp_greater = 5,

	//! CMP_NOTEQUAL accepts the new pixel if its value does not equal
	//! the value of the current pixel.
	e_d3d9_cmp_notequal = 6,

	//! CMP_GREATEREQUAL accepts the new pixel if its value is greater than
	//! or equal to the value of the current pixel.
	e_d3d9_cmp_greaterequal = 7,

	//! CMP_ALWAYS always passes the test.
	e_d3d9_cmp_always = 8,
};

//! ENUM 'e_d3d9_cmp_' define the supported blend operations
typedef u32 d3d9_cmpfunc_t;


//! CUBEMAP_FACES define the faces of a cubemap
enum d3d9_cubemap_faces_e
{
	//! CUBEMAP_FACE_POSITIVE_X is the positive x-face of the cubemap.
	e_d3d9_cubemap_face_positive_x = 0,

	//! CUBEMAP_FACE_NEGATIVE_X is the negative x-face of the cubemap.
	e_d3d9_cubemap_face_negative_x = 1,

	//! CUBEMAP_FACE_POSITIVE_Y is the positive y-face of the cubemap.
	e_d3d9_cubemap_face_positive_y = 2,

	//! CUBEMAP_FACE_NEGATIVE_Y is the negative y-face of the cubemap.
	e_d3d9_cubemap_face_negative_y = 3,

	//! CUBEMAP_FACE_POSITIVE_Z is the positive z-face of the cubemap.
	e_d3d9_cubemap_face_positive_z = 4,

	//! CUBEMAP_FACE_NEGATIVE_Z is the negative z-face of the cubemap.
	e_d3d9_cubemap_face_negative_z = 5,
};

//! ENUM 'e_d3d9_cubemap_face_' define the supported blend operations
typedef u32 d3d9_cubemap_faces_t;


//! CULL define the supported culling modes
enum d3d9_cull_e
{
	//! CULL_NONE does not cull back faces.
	e_d3d9_cull_none = 1,

	//! CULL_CW culls back faces with clockwise vertices.
	e_d3d9_cull_cw   = 2,

	//! CULL_CCW culls back faces with counterclockwise vertices.
	e_d3d9_cull_ccw  = 3,
};

//! ENUM 'e_d3d9_cull_' define the supported culling modes
typedef u32 d3d9_cull_t;


//! DEBUGMONITORTOKENS define debug monitor tokens
enum d3d9_debugmonitortokens_e
{
	//! DMT_ENABLE enables the debug monitor.
	e_d3d9_dmt_enable = 0,

	//! DMT_DISABLE disables the debug monitor.
	e_d3d9_dmt_disable = 1,
};

//! ENUM 'e_d3d9_dmt_' define debug monitor tokens
typedef u32 d3d9_debugmonitortokens_t;


//! DECLMETHOD defines the vertex declaration method which is a predefined
//! operation performed by the tessellator
//! (or any procedural geometry routine on vertex data during tessellation)
enum d3d9_declmethod_e
{
	//! DECLMETHOD_DEFAULT is the default value. The tessellator copies the
	//! vertex data (spline data for patches) as is, with no additional
	//! calculations. When the tessellator is used, this element is
	//! interpolated. Otherwise vertex data is copied into the input register.
	//! The input/output types can be any value, but are always the same type.
	e_d3d9_declmethod_default = 0,

	//! DECLMETHOD_PARTIALU computes the tangent at a point on the rectangle
	//! or triangle patch in the U direction. The input type can be one of
	//! the following: DECLTYPE_D3DCOLOR, DECLTYPE_FLOAT3, DECLTYPE_FLOAT4,
	//! DECLTYPE_SHORT4, DECLTYPE_UBYTE4.
	//! The output type is always DECLTYPE_FLOAT3.
	e_d3d9_declmethod_partialu = 1,

	//! DECLMETHOD_PARTIALV Computes the tangent at a point on the rectangle
	//! or triangle patch in the V direction. The input type can be one of
	//! the following: DECLTYPE_D3DCOLOR, DECLTYPE_FLOAT3, DECLTYPE_FLOAT4,
	//! DECLTYPE_SHORT4, DECLTYPE_UBYTE4.
	//! The output type is always DECLTYPE_FLOAT3.
	e_d3d9_declmethod_partialv = 2,

	//! DECLMETHOD_CROSSUV computes the normal at a point on the rectangle or
	//! triangle patch by taking the cross product of two tangents. The input
	//! type can be one of the following: DECLTYPE_D3DCOLOR, DECLTYPE_FLOAT3,
	//! DECLTYPE_FLOAT4, DECLTYPE_SHORT4, DECLTYPE_UBYTE4.
	//! The output type is always DECLTYPE_FLOAT3.
	e_d3d9_declmethod_crossuv = 3,

	//! DECLMETHOD_UV copies out the U, V values at a point on the rectangle
	//! or triangle patch. This results in a 2D float. The input type must be
	//! set to DECLTYPE_UNUSED. The output datatype is always DECLTYPE_FLOAT2.
	//! The input stream and offset are also unused (but must be set to 0).
	e_d3d9_declmethod_uv = 4,

	//! DECLMETHOD_LOOKUP looks up a displacement map. The input type can be
	//! one of these ones: DECLTYPE_FLOAT2, DECLTYPE_FLOAT3, DECLTYPE_FLOAT4.
	//! Only the X and Y components are used for the texture map lookup. The
	//! output type is always DECLTYPE_FLOAT1. The device must support
	//! displacement mapping. This constant is supported only by the
	//! programmable pipeline on N-patch data, if N-patches are enabled.
	e_d3d9_declmethod_lookup = 5,

	//! DECLMETHOD_LOOKUPPRESAMPLED looks up a presampled displacement map.
	//! The input type must be set to DECLTYPE_UNUSED; the stream index and
	//! the stream offset must be set to 0. The output type for this operation
	//! is always DECLTYPE_FLOAT1. A device must support displacement mapping.
	//! This constant is supported only by a programmable pipeline on N-patch
	//! data, if N-patches are enabled. This method can be used only with
	//! DECLUSAGE_SAMPLE.
	e_d3d9_declmethod_lookuppresampled = 6,
};

//! ENUM 'e_d3d9_declmethod_' define the vertex declaration method
//! which is a predefined operation performed by the tessellator
//! (or any procedural geometry routine on vertex data during tessellation)
typedef u08 d3d9_declmethod_t;


//! DECLTYPE defines a vertex declaration data type
enum d3d9_decltype_e
{
	//! DECLTYPE_FLOAT1 is a one-component float expanded to (float, 0, 0, 1).
	e_d3d9_decltype_float1 = 0,

	//! DECLTYPE_FLOAT2 is a two-component float expanded
	//! to (float, float, 0, 1).
	e_d3d9_decltype_float2 = 1,

	//! DECLTYPE_FLOAT3 is a three-component float expanded
	//! to (float, float, float, 1).
	e_d3d9_decltype_float3 = 2,

	//! DECLTYPE_FLOAT4 is a four-component float expanded
	//! to (float, float, float, float).
	e_d3d9_decltype_float4 = 3,

	//! DECLTYPE_D3DCOLOR is a four-component, packed, unsigned bytes mapped
	//! to 0 to 1 range. Input is a 'COLOR' and is expanded to 'RGBA' order.
	e_d3d9_decltype_d3dcolor = 4,

	//! DECLTYPE_UBYTE4 is a four-component, unsigned byte.
	e_d3d9_decltype_ubyte4 = 5,

	//! DECLTYPE_SHORT2 is a two-component, signed short expanded to
	//! (value, value, 0, 1).
	e_d3d9_decltype_short2 = 6,

	//! DECLTYPE_SHORT4 is a four-component, signed short expanded to
	//! (value, value, value, value).
	e_d3d9_decltype_short4 = 7,

	//! DECLTYPE_UBYTE4N is a four-component byte with each byte
	//! normalized by dividing with 255.0f.
	e_d3d9_decltype_ubyte4n = 8,

	//! DECLTYPE_SHORT2N is a normalized, two-component, signed short,
	//! expanded to (first short/32767.0, second short/32767.0, 0, 1).
	e_d3d9_decltype_short2n = 9,

	//! DECLTYPE_SHORT4N is a normalized, four-component, signed short,
	//! expanded to (first short/32767.0, second short/32767.0,
	//! third short/32767.0, fourth short/32767.0).
	e_d3d9_decltype_short4n = 10,

	//! DECLTYPE_USHORT2N is a normalized, two-component, unsigned short,
	//! expanded to (first short/65535.0, short short/65535.0, 0, 1).
	e_d3d9_decltype_ushort2n = 11,

	//! DECLTYPE_USHORT4N is a normalized, four-component, unsigned short,
	//! expanded to (first short/65535.0, second short/65535.0, third
	//! short/65535.0, fourth short/65535.0).
	e_d3d9_decltype_ushort4n = 12,

	//! DECLTYPE_UDEC3 is a three-component, unsigned, 10 10 10 format
	//! expanded to (value, value, value, 1).
	e_d3d9_decltype_udec3 = 13,

	//! DECLTYPE_DEC3N is a three-component, signed, 10 10 10 format
	//! normalized and expanded to (v[0]/511.0, v[1]/511.0, v[2]/511.0, 1).
	e_d3d9_decltype_dec3n = 14,

	//! DECLTYPE_FLOAT16_2 is a two-component, 16-bit,
	//! floating point expanded to (value, value, 0, 1).
	e_d3d9_decltype_float16_2 = 15,

	//! DECLTYPE_FLOAT16_4 is a four-component, 16-bit,
	//! floating point expanded to (value, value, value, value).
	e_d3d9_decltype_float16_4 = 16,

	//! DECLTYPE_UNUSED means the type field in a declaration is unused. This
	//! is designed for use w/ DECLMETHOD_UV and DECLMETHOD_LOOKUPPRESAMPLED.
	e_d3d9_decltype_unused = 17,
};

//! ENUM 'e_d3d9_decltype_' define a vertex declaration data type
typedef u08 d3d9_decltype_t;


//! DECLUSAGE identifies the intended use of vertex data
enum d3d9_declusage_e
{
	//! DECLUSAGE_POSITION means position data ranging from (-1,-1) to (1, 1).
	//! Use DECLUSAGE_POSITION w/ a usage index of 0 to specify untransformed
	//! pos. for fixed function vertex processing and the n-patch tessellator.
	//! Use DECLUSAGE_POSITION w/ a usage index of 1 to specify untransformed
	//! position in the fixed function vertex shader for vertex tweening.
	e_d3d9_declusage_position = 0,

	//! DECLUSAGE_BLENDWEIGHT means blending weight data. Use
	//! DECLUSAGE_BLENDWEIGHT with a usage index of 0 to specify the blend
	//! weights used in indexed and nonindexed vertex blending.
	e_d3d9_declusage_blendweight = 1,

	//! DECLUSAGE_BLENDINDICES means blending indices data.
	//! Use DECLUSAGE_BLENDINDICES with a usage index of 0 to
	//! specify matrix indices for indexed paletted skinning.
	e_d3d9_declusage_blendindices = 2,

	//! DECLUSAGE_NORMAL means vertex normal data. Use DECLUSAGE_NORMAL with a
	//! usage index of 0 to specify vertex normals for fixed function vertex
	//! processing and the n-patch tessellator. Use DECLUSAGE_NORMAL with a
	//! usage index of 1 to specify vertex normals for fixed function vertex
	//! processing for vertex tweening.
	e_d3d9_declusage_normal = 3,

	//! DECLUSAGE_PSIZE means point size data. Use DECLUSAGE_PSIZE
	//! with a usage index of 0 to specify the point-size attribute
	//! used by the setup engine of the rasterizer to expand a point
	//! into a quad for the point-sprite functionality.
	e_d3d9_declusage_psize = 4,

	//! DECLUSAGE_TEXCOORD means texture coordinate data. Use
	//! DECLUSAGE_TEXCOORD, n to specify texture coordinates in fixed function
	//! vertex processing and in pixel shaders prior to ps_3_0. These can be
	//! used to pass user defined data.
	e_d3d9_declusage_texcoord = 5,

	//! DECLUSAGE_TANGENT means vertex tangent data.
	e_d3d9_declusage_tangent = 6,

	//! DECLUSAGE_BINORMAL means vertex binormal data.
	e_d3d9_declusage_binormal = 7,

	//! DECLUSAGE_TESSFACTOR means a single positive floating point value. Use
	//! DECLUSAGE_TESSFACTOR with a usage index of 0 to specify a tessellation
	//! factor used in tessellation unit, to control the rate of tessellation.
	e_d3d9_declusage_tessfactor = 8,

	//! DECLUSAGE_POSITIONT means the vertex data contains transformed
	//! position data ranging from (0,0) to (viewport width, viewport height).
	//! Use DECLUSAGE_POSITIONT with a usage index of 0 to specify transformed
	//! position. When a declaration containing this is set, the pipeline does
	//! not perform vertex processing.
	e_d3d9_declusage_positiont = 9,

	//! DECLUSAGE_COLOR means the vertex data contains diffuse or specular
	//! color. Use DECLUSAGE_COLOR with a usage index of 0 to specify the
	//! diffuse color in the fixed function vertex shader and pixel shaders
	//! prior to ps_3_0. Use D3DDECLUSAGE_COLOR with a usage index of 1 to
	//! specify the specular color in the fixed function vertex shader and
	//! pixel shaders prior to ps_3_0.
	e_d3d9_declusage_color = 10,

	//! DECLUSAGE_FOG means vertex data contains fog data. Use DECLUSAGE_FOG
	//! with a usage index of 0 to specify a fog blend value used after pixel
	//! shading finishes. Applies to pixel shaders prior to version ps_3_0.
	e_d3d9_declusage_fog = 11,

	//! DECLUSAGE_DEPTH means the vertex data contains depth data.
	e_d3d9_declusage_depth = 12,

	//! DECLUSAGE_SAMPLE means the vertex data contains sampler data. Use
	//! DECLUSAGE_SAMPLE with a usage index of 0 to specify the displacement
	//! value to look up. It can be used only with
	//! DECLUSAGE_LOOKUPPRESAMPLED or DECLUSAGE_LOOKUP.
	e_d3d9_declusage_sample = 13,
};

//! ENUM 'e_d3d9_declusage_' identifies the intended use of vertex data
typedef u08 d3d9_declusage_t;


//! DEGREETYPE defines the degree of the variables
//! in the equation that describes a curve
enum d3d9_degreetype_e
{
	//! DEGREE_LINEAR means the curve is described by variables of 1st order.
	e_d3d9_degree_linear = 1,

	//! DEGREE_QUADRATIC means the curve is described by vars of 2nd order.
	e_d3d9_degree_quadratic = 2,

	//! DEGREE_CUBIC means the curve is described by variables of 3rd order.
	e_d3d9_degree_cubic = 3,

	//! DEGREE_QUINTIC means the curve is described by variables of 4th order.
	e_d3d9_degree_quintic = 5,
};

//! ENUM 'e_d3d9_degree_' define the degree of vars in equation of a curve
typedef u32 d3d9_degreetype_t;


//! DEVTYPE defines device types
enum d3d9_devtype_e
{
	//! DEVTYPE_HAL indicates hardware rasterization. Shading is done with
	//! software, hardware, or mixed transform and lighting.
	e_d3d9_devtype_hal = 1,

	//! DEVTYPE_REF means Direct3D features are implemented in software;
	//! however, the reference rasterizer does make use of special CPU
	//! instructions whenever it can.
	//! The reference device is installed by the Windows SDK 8.0 or later
	//! and is intended as an aid in debugging for development only.
	e_d3d9_devtype_ref = 2,

	//! DEVTYPE_SW is a pluggable software device that has been
	//! registered with Direct3D.RegisterSoftwareDevice.
	e_d3d9_devtype_sw = 3,

	//! DEVTYPE_NULLREF initializes Direct3D on a computer that
	//! has neither hardware nor reference rasterization available,
	//! and enable resources for 3D content creation.
	e_d3d9_devtype_nullref = 4,
};

//! ENUM 'e_d3d9_devtype_' define device types
typedef u32 d3d9_devtype_t;


//! FILLMODE defines constants describing the fill mode
enum d3d9_fillmode_e
{
	e_d3d9_fill_point     = 1, //!< FILL_POINT fills points
	e_d3d9_fill_wireframe = 2, //!< FILL_WIREFRAME fills wireframes
	e_d3d9_fill_solid     = 3, //!< FILL_SOLID fills solids
};

//! ENUM 'e_d3d9_fill_' are enumerants describing the fill mode
typedef u32 d3d9_fillmode_t;


//! FOGMODE defines constants that describe the fog mode
enum d3d9_fogmode_e
{
	//! FOG_NONE means no fog effect.
	e_d3d9_fog_none = 0,

	//! FOG_EXP means the fog effect intensifies exponentially,
	//! according to the following formula:
	//! f = 1/(e^(d*density))
	e_d3d9_fog_exp = 1,

	//! FOG_EXP2 means the fog effect intensifies exponentially with
	//! the square of the distance, according to the following formula:
	//! f = 1/(e^[(d*density)^2])
	e_d3d9_fog_exp2 = 2,

	//! FOG_LINEAR means the fog effect intensifies linearly between
	//! the start and end points, according to the following formula:
	//! f = (end - d)/(end - start)
	//! This is the only fog mode currently supported.
	e_d3d9_fog_linear = 3,
};

//! ENUM 'e_d3d9_fog_' are enumerants that describe the fog mode
typedef u32 d3d9_fogmode_t;


//! FORMAT defines the various types of surface formats
enum d3d9_fmt_e
{
	//! FMT_UNKNOWN means the surface format is unknown.
	e_d3d9_fmt_unknown = 0,

	//! FMT_R8G8B8 means 24-bit RGB pixel format with 8 bits per channel.
	e_d3d9_fmt_r8g8b8 = 20,

	//! FMT_A8R8G8B8 means 32-bit ARGB pixel format with alpha,
	//! using 8 bits per channel.
	e_d3d9_fmt_a8r8g8b8 = 21,

	//! FMT_X8R8G8B8 means 32-bit RGB pixel format,
	//! where 8 bits are reserved for each color.
	e_d3d9_fmt_x8r8g8b8 = 22,

	//! FMT_R5G6B5 means 16-bit RGB pixel format with 5 bits for red,
	//! 6 bits for green, and 5 bits for blue.
	e_d3d9_fmt_r5g6b5 = 23,

	//! FMT_X1R5G5B5 means 16-bit pixel format
	//! where 5 bits are reserved for each color.
	e_d3d9_fmt_x1r5g5b5 = 24,

	//! FMT_A1R5G5B5 means 16-bit pixel format where 5 bits
	//! are reserved for each color and 1 bit is reserved for alpha.
	e_d3d9_fmt_a1r5g5b5 = 25,

	//! FMT_A4R4G4B4 means 16-bit ARGB pixel format w/ 4 bits for each channel
	e_d3d9_fmt_a4r4g4b4 = 26,

	//! FMT_R3G3B2 means 8-bit RGB texture format using
	//! 3 bits for red, 3 bits for green, and 2 bits for blue.
	e_d3d9_fmt_r3g3b2 = 27,

	//! FMT_A8 means 8-bit alpha only.
	e_d3d9_fmt_a8 = 28,

	//! FMT_A8R3G3B2 means 16-bit ARGB texture format using 8 bits for alpha,
	//! 3 bits each for red and green, and 2 bits for blue.
	e_d3d9_fmt_a8r3g3b2 = 29,

	//! FMT_X4R4G4B4 means 16-bit RGB pixel format using 4 bits per color.
	e_d3d9_fmt_x4r4g4b4 = 30,

	//! FMT_A2B10G10R10 means 32-bit pixel format using
	//! 10 bits for each color and 2 bits for alpha.
	e_d3d9_fmt_a2b10g10r10 = 31,

	//! FMT_A8B8G8R8 means 32-bit ARGB pixel format with alpha,
	//! using 8 bits per channel.
	e_d3d9_fmt_a8b8g8r8 = 32,

	//! FMT_X8B8G8R8 means 32-bit RGB pixel format,
	//! where 8 bits are reserved for each color.
	e_d3d9_fmt_x8b8g8r8 = 33,

	//! FMT_G16R16 means 32-bit pixel format
	//! using 16 bits each for green and red.
	e_d3d9_fmt_g16r16 = 34,

	//! FMT_A2R10G10B10 means 32-bit pixel format
	//! using 10 bits each for red, green, and blue, and 2 bits for alpha.
	e_d3d9_fmt_a2r10g10b10 = 35,

	//! FMT_A16B16G16R16 means 64-bit pixel format
	//! using 16 bits for each component.
	e_d3d9_fmt_a16b16g16r16 = 36,

	//! FMT_A8P8 means 8-bit color indexed with 8 bits of alpha.
	e_d3d9_fmt_a8p8 = 40,

	//! FMT_P8 means 8-bit color indexed.
	e_d3d9_fmt_p8 = 41,

	//! FMT_L8 means 8-bit luminance only.
	e_d3d9_fmt_L8 = 50,

	//! FMT_A8L8 means 16-bit using 8 bits each for alpha and luminance.
	e_d3d9_fmt_A8L8 = 51,

	//! FMT_A4L4 means 8-bit using 4 bits each for alpha and luminance.
	e_d3d9_fmt_A4L4 = 52,

	//! FMT_V8U8 means 16-bit bump-map format using 8 bits each for u,v data.
	e_d3d9_fmt_v8u8 = 60,

	//! FMT_L6V5U5 means 16-bit bump-map format with luminance
	//! using 6 bits for luminance, and 5 bits each for v and u.
	e_d3d9_fmt_L6V5U5 = 61,

	//! FMT_X8L8V8U8 means 32-bit bump-map format with
	//! luminance using 8 bits for each channel.
	e_d3d9_fmt_x8l8v8u8 = 62,

	//! FMT_Q8W8V8U8 means 32-bit bump-map fmt using 8 bits for each channel.
	e_d3d9_fmt_q8w8v8u8 = 63,

	//! FMT_V16U16 means 32-bit bump-map fmt using 16 bits for each channel.
	e_d3d9_fmt_v16u16 = 64,

	//! FMT_A2W10V10U10 means 32-bit bump-map format using
	//! 2 bits for alpha and 10 bits each for w, v, and u.
	e_d3d9_fmt_a2w10v10u10 = 67,

	//! FMT_UYVY means UYVY format (PC98 compliance).
	e_d3d9_fmt_uyvy = 1498831189,

	//! FMT_R8G8_B8G8 is a 16-bit packed RGB format analogous to UYVY (U0Y0,
	//! V0Y1, U2Y2, and so on). It requires a pixel pair in order to properly
	//! represent the color value. The first pixel in the pair contains 8 bits
	//! of green (in the low 8 bits) and 8 bits of red (in the high 8 bits).
	//! The second pixel contains 8 bits of green (in the low 8 bits) and
	//! 8 bits of blue (in the high 8 bits). Together, the two pixels share
	//! the red and blue components, while each has a unique green component
	//! (R0G0, B0G1, R2G2, and so on). The texture sampler does not normalize
	//! the colors when looking up into a pixel shader; they remain in the
	//! range of 0.0f to 255.0f. This is true for all programmable pixel
	//! shader models. For the fixed function pixel shader, the hardware
	//! should normalize to the 0.f to 1.f range and essentially treat it
	//! as the YUY2 texture. Hardware that exposes this format must have
	//! PixelShader1xMaxValue member of CAPS set to a value capable of
	//! handling that range.
	e_d3d9_fmt_r8g8_b8g8 = 1195525970,

	//! FMT_YUY2 means YUY2 format (PC98 compliance).
	e_d3d9_fmt_yuy2 = 844715353,

	//! FMT_G8R8_G8B8 is a 16-bit packed RGB format analogous to YUY2 (Y0U0,
	//! Y1V0, Y2U2, and so on). It requires a pixel pair in order to properly
	//! represent the color value. The first pixel in the pair contains 8 bits
	//! of green (in the high 8 bits) and 8 bits of red (in the low 8 bits).
	//! The second pixel contains 8 bits of green (in the high 8 bits) and 8
	//! bits of blue (in the low 8 bits). Together, the two pixels share the
	//! red and blue components, while each has a unique green component
	//! (G0R0, G1B0, G2R2, and so on). The texture sampler does not normalize
	//! the colors when looking up into a pixel shader; they remain in the
	//! range of 0.0f to 255.0f. This is true for all programmable pixel
	//! shader models. For the fixed function pixel shader, the hardware
	//! should normalize to the 0.f to 1.f range and essentially treat it as
	//! the YUY2 texture. Hardware that exposes this format must have the
	//! PixelShader1xMaxValue member of CAPS
	//! set to a value capable of handling that range.
	e_d3d9_fmt_g8r8_g8b8 = 1111970375,

	//! FMT_DXT1 means DXT1 compression texture format.
	e_d3d9_fmt_dxt1 = 827611204,

	//! FMT_DXT2 means DXT2 compression texture format.
	e_d3d9_fmt_dxt2 = 844388420,

	//! FMT_DXT3 means DXT3 compression texture format.
	e_d3d9_fmt_dxt3 = 861165636,

	//! FMT_DXT4 means DXT4 compression texture format.
	e_d3d9_fmt_dxt4 = 877942852,

	//! FMT_DXT5 means DXT5 compression texture format.
	e_d3d9_fmt_dxt5 = 894720068,

	//! FMT_D16_LOCKABLE means 16-bit z-buffer bit depth.
	e_d3d9_fmt_d16_lockable = 70,

	//! FMT_D32 means 32-bit z-buffer bit depth.
	e_d3d9_fmt_d32 = 71,

	//! FMT_D15S1 means 16-bit z-buffer bit depth where 15 bits are reserved
	//! for the depth channel and 1 bit is reserved for the stencil channel.
	e_d3d9_fmt_d15s1 = 73,

	//! FMT_D24S8 means 32-bit z-buffer bit depth using
	//! 24 bits for the depth channel and 8 bits for the stencil channel.
	e_d3d9_fmt_d24s8 = 75,

	//! FMT_D24X8 means 32-bit z-buffer bit depth using
	//! 24 bits for the depth channel.
	e_d3d9_fmt_d24x8 = 77,

	//! FMT_D24X4S4 means 32-bit z-buffer bit depth using
	//! 24 bits for the depth channel and 4 bits for the stencil channel.
	e_d3d9_fmt_d24x4s4 = 79,

	//! FMT_D16 means 16-bit z-buffer bit depth.
	e_d3d9_fmt_d16 = 80,

	//! FMT_L16 means 16-bit luminance only.
	e_d3d9_fmt_L16 = 81,

	//! FMT_D32F_LOCKABLE is a lockable format where the depth value
	//! is represented as a standard IEEE floating-point number.
	e_d3d9_fmt_d32f_lockable = 82,

	//! FMT_D24FS8 is a non-lockable format that contains 24 bits of depth
	//! (in a 24-bit floating point format - 20e4) and 8 bits of stencil.
	e_d3d9_fmt_d24fs8 = 83,

	//! FMT_VERTEXDATA describes a vertex buffer surface.
	e_d3d9_fmt_vertexdata = 100,

	//! FMT_INDEX16 means 16-bit index buffer bit depth.
	e_d3d9_fmt_index16 = 101,

	//! FMT_INDEX32 means 32-bit index buffer bit depth.
	e_d3d9_fmt_index32 = 102,

	//! FMT_Q16W16V16U16 means 64-bit bump-map format
	//! using 16 bits for each component.
	e_d3d9_fmt_q16w16v16u16 = 110,

	//! FMT_MULTI2_ARGB8 means a multiElement texture (not compressed).
	e_d3d9_fmt_multi2_argb8 = 827606349,

	//! FMT_R16F means 16-bit float format using 16 bits for the red channel.
	e_d3d9_fmt_r16f = 111,

	//! FMT_G16R16F means 32-bit float format using 16 bits
	//! for the red channel and 16 bits for the green channel.
	e_d3d9_fmt_g16r16f = 112,

	//! FMT_A16B16G16R16F means 64-bit float format using
	//! 16 bits for the each channel (alpha, blue, green, red).
	e_d3d9_fmt_a16b16g16r16f = 113,

	//! FMT_R32F means 32-bit float format using 32 bits for the red channel.
	e_d3d9_fmt_r32f = 114,

	//! FMT_G32R32F means 64-bit float format using 32 bits
	//! for the red channel and 32 bits for the green channel.
	e_d3d9_fmt_g32r32f = 115,

	//! FMT_A32B32G32R32F means 128-bit float format using
	//! 32 bits for the each channel (alpha, blue, green, red).
	e_d3d9_fmt_a32b32g32r32f = 116,

	//! FMT_CxV8U8 means 16-bit normal compression format. The texture
	//! sampler computes the C channel from: C = sqrt(1 - U� - V�).
	e_d3d9_fmt_cxv8u8 = 117,
};

//! ENUM 'e_d3d9_fmt_' are surface format enumerants
typedef u32 d3d9_format_t;


//! LIGHTTYPE defines the light type
enum d3d9_lighttype_e
{
	//! LIGHT_POINT means the light is a point source.
	//! The light has a position and radiates light in all directions.
	e_d3d9_light_point = 1,

	//! LIGHT_SPOT means the light is a spotlight source. This light is
	//! like a point light, except that the illumination is limited to a cone.
	//! This light type has a direction and several other parameters
	//! that determine the shape of the cone it produces.
	e_d3d9_light_spot = 2,

	//! LIGHT_DIRECTIONAL means the light is a directional light source. This
	//! is equivalent to using a point light source at an infinite distance.
	e_d3d9_light_directional = 3,
};

//! ENUM 'e_d3d9_light_' are enumerants that define the light type
typedef u32 d3d9_lighttype_t;


//! MATERIALCOLORSOURCE defines the location at which a color or
//! color component must be accessed for lighting calculations.
enum d3d9_materialcolorsource_e
{
	//! MCS_MATERIAL uses the color from the current material.
	e_d3d9_mcs_material = 0,

	//! MCS_COLOR1 uses the diffuse vertex color.
	e_d3d9_mcs_color1 = 1,

	//! MCS_COLOR2 uses the specular vertex color.
	e_d3d9_mcs_color2 = 2,
};

//! MATERIALCOLORSOURCE defines the location at which a color or
//! color component must be accessed for lighting calculations.
//! ENUM 'e_d3d9_mcs_' enumerants define this.
typedef u32 d3d9_materialcolorsource_t;


//! MULTISAMPLE_TYPE defines the levels of
//! full-scene multisampling that a device can apply.
enum d3d9_multisample_type_e
{
	//! MULTISAMPLE_NONE means that no full-scene multisampling is available.
	e_d3d9_multisample_none = 0,

	//! MULTISAMPLE_NONMASKABLE enables the multisample quality value.
	e_d3d9_multisample_nonmaskable = 1,

	//! MULTISAMPLE_2_SAMPLES means 2 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_2_samples = 2,

	//! MULTISAMPLE_3_SAMPLES means 3 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_3_samples = 3,

	//! MULTISAMPLE_4_SAMPLES means 4 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_4_samples = 4,

	//! MULTISAMPLE_5_SAMPLES means 5 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_5_samples = 5,

	//! MULTISAMPLE_6_SAMPLES means 6 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_6_samples = 6,

	//! MULTISAMPLE_7_SAMPLES means 7 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_7_samples = 7,

	//! MULTISAMPLE_8_SAMPLES means 8 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_8_samples = 8,

	//! MULTISAMPLE_9_SAMPLES means 9 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_9_samples = 9,

	//! MULTISAMPLE_10_SAMPLES means 10 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_10_samples = 10,

	//! MULTISAMPLE_11_SAMPLES means 11 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_11_samples = 11,

	//! MULTISAMPLE_12_SAMPLES means 12 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_12_samples = 12,

	//! MULTISAMPLE_13_SAMPLES means 13 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_13_samples = 13,

	//! MULTISAMPLE_14_SAMPLES means 14 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_14_samples = 14,

	//! MULTISAMPLE_15_SAMPLES means 15 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_15_samples = 15,

	//! MULTISAMPLE_16_SAMPLES means 16 levels
	//! of full-scene multisampling available.
	e_d3d9_multisample_16_samples = 16,
};

//! MULTISAMPLE_TYPE defines the levels of
//! full-scene multisampling that a device can apply.
//! ENUM 'e_d3d9_multisample_' enumerants define this.
typedef u32 d3d9_multisample_type_t;


//! PATCHEDGESTYLE defines whether the current
//! tessellation mode is discrete or continuous
enum d3d9_patchedgestyle_e
{
	//! PATCHEDGE_DISCRETE means discrete edge style. In discrete mode, you
	//! can specify float tessellation but it will be truncated to integers.
	e_d3d9_patchedge_discrete = 0,

	//! PATCHEDGE_CONTINUOUS means continuous edge style. In continuous mode,
	//! tessellation is specified as float values that can be smoothly varied
	//! to reduce "popping" artifacts.
	e_d3d9_patchedge_continuous = 1,
};

//! PATCHEDGESTYLE defines whether the current
//! tessellation mode is discrete or continuous
//! ENUM 'e_d3d9_patchedge_' enumerants define this.
typedef u32 d3d9_patchedgestyle_t;


//! POOL defines the memory class that holds the buffers for a resource
enum d3d9_pool_e
{
	//! POOL_DEFAULT means resources are placed in the memory pool most
	//! appropriate for the set of usages requested for the given resource.
	//! This is usually video memory, including both local video memory and
	//! AGP memory. The POOL_DEFAULT pool is separate from POOL_MANAGED and
	//! POOL_SYSTEMMEM, and it specifies that the resource is placed in the
	//! preferred memory for device access. Note that POOL_DEFAULT never
	//! indicates that either POOL_MANAGED or POOL_SYSTEMMEM should be chosen
	//! as the memory pool type for this resource. Textures placed in the
	//! POOL_DEFAULT pool cannot be locked unless they are dynamic textures
	//! or they are private, FOURCC, driver formats. To access unlockable
	//! textures, you must use functions such as Device.UpdateSurface,
	//! Device.UpdateTexture, Device.GetFrontBufferData, and
	//! Device.GetRenderTargetData. POOL_MANAGED is probably a better choice
	//! than POOL_DEFAULT for most applications. Note that some textures
	//! created in driver-proprietary pixel formats, unknown to the Direct3D
	//! runtime, can be locked. Also note that - unlike textures - swap chain
	//! back buffers, render targets, vertex buffers, and index buffers can
	//! be locked. When a device is lost, resources created using
	//! POOL_DEFAULT must be released before calling Device.Reset.
	//! When creating resources with POOL_DEFAULT, if video card memory is
	//! already committed, managed resources will be evicted to free enough
	//! memory to satisfy the request.
	e_d3d9_pool_default = 0,

	//! POOL_MANAGED means resources are copied automatically to
	//! device-accessible memory as needed. Managed resources are backed by
	//! system memory and do not need to be recreated when a device is lost.
	//! Managed resources can be locked. Only the system-memory copy is
	//! directly modified. Direct3D copies your changes to driver-accessible
	//! memory as needed.
	//! Differences between Direct3D 9 and Direct3D 9Ex: POOL_MANAGED is valid
	//! with Device; however, it is not valid with DeviceEx.
	e_d3d9_pool_managed = 1,

	//! POOL_SYSTEMMEM means resources are placed in memory that is not
	//! typically accessible by the Direct3D device. This memory allocation
	//! consumes system RAM but does not reduce pageable RAM. These resources
	//! do not need to be recreated when a device is lost. Resources in this
	//! pool can be locked and can be used as the source for a
	//! Device.UpdateSurface or Device.UpdateTexture operation
	//! to a memory resource created with POOL_DEFAULT.
	e_d3d9_pool_systemmem = 2,

	//! POOL_SCRATCH means resources are placed in system RAM
	//! and do not need to be recreated when a device is lost.
	//! These resources are not bound by device size or format restrictions.
	//! Because of this, these resources cannot be accessed by
	//! the Direct3D device nor set as textures or render targets.
	//! However, these resources can always be created, locked, and copied.
	e_d3d9_pool_scratch = 3,
};

//! POOL defines the memory class that holds the buffers for a resource
//! ENUM 'e_d3d9_pool_' enumerants define this.
typedef u32 d3d9_pool_t;


//! PRIMITIVETYPE defines the primitives supported by Direct3D
enum d3d9_primitivetype_e
{
	//! PT_POINTLIST renders the vertices as a collection of isolated points.
	//! This value is unsupported for indexed primitives.
	e_d3d9_pt_pointlist = 1,

	//! PT_LINELIST renders the vertices as a list of isolated straight line
	//! segments.
	e_d3d9_pt_linelist = 2,

	//! PT_LINESTRIP renders the vertices as a single polyline.
	e_d3d9_pt_linestrip = 3,

	//! PT_TRIANGLELIST renders specified vertices as a sequence of isolated
	//! triangles. Each group of three vertices defines a separate triangle.
	//! Back-face culling is affected by current winding-order render state.
	e_d3d9_pt_trianglelist = 4,

	//! PT_TRIANGLESTRIP renders the vertices as a triangle strip. The
	//! backface-culling flag is automatically flipped on even-numbered
	//! triangles.
	e_d3d9_pt_trianglestrip = 5,

	//! PT_TRIANGLEFAN renders the vertices as a triangle fan.
	e_d3d9_pt_trianglefan = 6,
};

//! PRIMITIVETYPE defines the primitives supported by Direct3D
//! ENUM 'e_d3d9_pt_' enumerants define this.
typedef u32 d3d9_primitivetype_t;


//! QUERYTYPE identifies the query type
enum d3d9_querytype_e
{
	//! QUERYTYPE_VCACHE queries for driver hints
	//! about data layout for vertex caching.
	e_d3d9_querytype_vcache = 4,

	//! QUERYTYPE_RESOURCEMANAGER queryies the resource manager.
	//! For this query, the device behavior flags must include
	//! CREATE_DISABLE_DRIVER_MANAGEMENT.
	e_d3d9_querytype_resourcemanager = 5,

	//! QUERYTYPE_VERTEXSTATS queries vertex statistics.
	e_d3d9_querytype_vertexstats = 6,

	//! QUERYTYPE_EVENT queries for any and all asynchronous
	//! events that have been issued from API calls.
	e_d3d9_querytype_event = 8,

	//! QUERYTYPE_OCCLUSION returns the num. of pixels that pass z-testing.
	//! These pixels are for primitives drawn between the issue of
	//! ISSUE_BEGIN and ISSUE_END. This enables an application to check the
	//! occlusion result against 0. Zero is fully occluded, which means
	//! the pixels are not visible from the current camera position.
	e_d3d9_querytype_occlusion = 9,

	//! QUERYTYPE_TIMESTAMP returns a 64-bit timestamp.
	e_d3d9_querytype_timestamp = 10,

	//! QUERYTYPE_TIMESTAMPDISJOINT notifies an application if the counter
	//! frequency has changed from the QUERYTYPE_TIMESTAMP.
	e_d3d9_querytype_timestampdisjoint = 11,

	//! QUERYTYPE_TIMESTAMPFREQ results in true if the values from
	//! QUERYTYPE_TIMESTAMP queries cannot be guaranteed to be continuous
	//! throughout the duration of the QUERYTYPE_TIMESTAMPDISJOINT query.
	//! Otherwise, the query result is false.
	e_d3d9_querytype_timestampfreq = 12,

	//! QUERYTYPE_PIPELINETIMINGS returns percent
	//! of time processing pipeline data.
	e_d3d9_querytype_pipelinetimings = 13,

	//! QUERYTYPE_INTERFACETIMINGS returns percent
	//! of time processing data in the driver.
	e_d3d9_querytype_interfacetimings = 14,

	//! QUERYTYPE_VERTEXTIMINGS returns percent
	//! of time processing vertex shader data.
	e_d3d9_querytype_vertextimings = 15,

	//! QUERYTYPE_PIXELTIMINGS returns percent
	//! of time processing pixel shader data.
	e_d3d9_querytype_pixeltimings = 16,

	//! QUERYTYPE_BANDWIDTHTIMINGS is for throughput measurement comparisons
	//! for help in understanding the performance of an application.
	e_d3d9_querytype_bandwidthtimings = 17,

	//! QUERYTYPE_CACHEUTILIZATION measures the cache hit-rate
	//! performance for textures and indexed vertices.
	e_d3d9_querytype_cacheutilization = 18,
};

//! QUERYTYPE identifies the query type
//! ENUM 'e_d3d9_querytype_' enumerants define this.
typedef u08 d3d9_querytype_t;


//! RENDERSTATETYPE defines set-up states for all kinds of vertex and pixel
//! processing. Some render states set up vertex processing, and some set up
//! pixel processing. Render states can be saved & restored using stateblocks.
enum d3d9_renderstatetype_e
{
	//! RS_ZENABLE is the depth-buffering state as one member of the
	//! ZBUFFERTYPE enumerated type. Set this state to ZB_TRUE to enable
	//! z-buffering, ZB_USEW to enable w-buffering, or ZB_FALSE to disable
	//! depth buffering. The default value for this render state is ZB_TRUE if
	//! a depth stencil was created along with
	//! the swap chain by setting the EnableAutoDepthStencil member
	//! of the PRESENT_PARAMETERS structure to true, and ZB_FALSE otherwise.
	e_d3d9_rs_zenable = 7,

	//! RS_FILLMODE expects one or more members of the
	//! D3DFILLMODE enumerated type. The default value is D3DFILL_SOLID.
	e_d3d9_rs_fillmode = 8,

	//! RS_SHADEMODE expects one or more members of the
	//! D3DSHADEMODE enumerated type. The default value is D3DSHADE_GOURAUD.
	e_d3d9_rs_shademode = 9,

	//! RS_ZWRITEENABLE can be set to true to enable the application to write
	//! to the depth buffer. The default value is true. This member enables an
	//! application to prevent the system from updating the depth buffer with
	//! new depth values. If false, depth comparisons are still made according
	//! to the render state RS_ZFUNC, assuming that depth buffering is taking
	//! place, but depth values are not written to the buffer.
	e_d3d9_rs_zwriteenable = 14,

	//! RS_ALPHATESTENABLE can be set to true to enable per pixel
	//! alpha testing. If the test passes, the pixel is processed
	//! by the frame buffer. Otherwise, all frame-buffer processing is skipped
	//! for the pixel. The test is done by comparing the incoming alpha value
	//! with the reference alpha value, using the comparison function provided
	//! by the RS_ALPHAFUNC render state. The reference alpha value
	//! is determined by the value set for RS_ALPHAREF.
	//! The default value of this parameter is false.
	e_d3d9_rs_alphatestenable = 15,

	//! RS_LASTPIXEL is true by default, which enables drawing of final pixel
	//! in a line. To prevent drawing of final pixel, set the value to false.
	e_d3d9_rs_lastpixel = 16,

	//! RS_SRCBLEND expectes one member of the BLEND enumerated type.
	//! The default value is BLEND_ONE.
	e_d3d9_rs_srcblend = 19,

	//! RS_DESTBLEND expectes one member of the BLEND enumerated type.
	//! The default value is BLEND_ZERO.
	e_d3d9_rs_destblend = 20,

	//! RS_CULLMODE specifies how back-facing triangles are culled, if at all.
	//! This can be set to one member of the CULL enumerated type.
	//! The default value is CULL_CCW.
	e_d3d9_rs_cullmode = 22,

	//! RS_ZFUNC expectes one member of the CMPFUNC enumerated type.
	//! The default value is CMP_LESSEQUAL. This member enables an application
	//! to accept or reject a pixel, based on its distance from the camera.
	//! The depth value of the pixel is compared with the depth-buffer value.
	//! If the depth value of the pixel passes the comparison function,
	//! the pixel is written.
	//! The depth value is written to the depth buffer
	//! only if the render state is true.
	//! Software rasterizers and many hardware accelerators work faster if the
	//! depth test fails, because there is no need to filter and modulate the
	//! texture if the pixel is not going to be rendered.
	e_d3d9_rs_zfunc = 23,

	//! RS_ALPHAREF expectes a value that specifies a reference alpha value
	//! against which pixels are tested when alpha testing is enabled. This is
	//! an 8-bit value placed in the low 8 bits of the render-state value.
	//! Values can range from 0x00000000 through 0x000000FF. The default value
	//! is 0.
	e_d3d9_rs_alpharef = 24,

	//! RS_ALPHAFUNC expectes one member of the CMPFUNC enumerated type.
	//! The default value is CMP_ALWAYS. This member enables an application
	//! to accept or reject a pixel, based on its alpha value.
	e_d3d9_rs_alphafunc = 25,

	//! RS_DITHERENABLE can be set to true to enable dithering. The default
	//! value is false.
	e_d3d9_rs_ditherenable = 26,

	//! RS_ALPHABLENDENABLE can be set to true to enable alpha-blended
	//! transparency. The default value is false.
	//! The type of alpha blending is determined by the RS_SRCBLEND and
	//! RS_DESTBLEND render states.
	e_d3d9_rs_alphablendenable = 27,

	//! RS_FOGENABLE can be set to true to enable fog blending.
	//! The default value is false.
	e_d3d9_rs_fogenable = 28,
	
	//! RS_SPECULARENABLE can be set to true to enable specular highlights.
	//! The default value is false.
	//! Specular highlights are calculated as though every vertex
	//! in the object being lit is at the object's origin. This gives the
	//! expected results as long as the object is modeled around the origin
	//! and the distance from the light to the object is relatively large.
	//! In other cases, the results as undefined.
	//! When this member is set to true, the specular color is added to
	//! the base color after the texture cascade but before alpha blending.
	e_d3d9_rs_specularenable = 29,
	
	//! RS_FOGCOLOR expectes a value whose type is COLOR.
	//! The default value is 0.
	e_d3d9_rs_fogcolor = 34,
	
	//! RS_FOGTABLEMODE is the fog formula to be used for pixel fog.
	//! Set to one of the members of the FOGMODE enumerated type.
	//! The default value is FOG_NONE.
	e_d3d9_rs_fogtablemode = 35,
	
	//! RS_FOGSTART is the depth at which pixel or vertex fog effects begin
	//! for linear fog mode. The default value is 0.0f. Depth is specified in
	//! world space for vertex fog and either device space [0.0, 1.0] or world
	//! space for pixel fog. For pixel fog, these values are in device space
	//! when the system uses z for fog calculations and world-world space when
	//! the system is using eye-relative fog (w-fog).
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_fogstart = 36,
	
	//! RS_FOGEND is the depth at which pixel or vertex fog effects end
	//! for linear fog mode. The default value is 1.0f. Depth is specified
	//! in world space for vertex fog and either device space [0.0, 1.0] or
	//! world space for pixel fog. For pixel fog, these values are in
	//! device space when the system uses z for fog calculations and
	//! in world space when the system is using eye-relative fog (w-fog).
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_fogend = 37,
	
	//! RS_FOGDENSITY is the fog density for pixel or vertex fog
	//! used in the exponential fog modes FOG_EXP and FOG_EXP2).
	//! Valid density values range from 0.0 through 1.0.
	//! The default value is 1.0.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_fogdensity = 38,
	
	//! RS_RANGEFOGENABLE can be set to true to enable range-based vertex fog.
	//! The default value is false, in which case the system uses depth-based
	//! fog. In range-based fog, the distance of an object from the viewer is
	//! used to compute fog effects, not the depth of the object (the z-coord)
	//! in the scene. In range-based fog, all fog methods work as usual,
	//! except that they use range instead of depth in the computations.
	//! Range is the correct factor to use for fog computations, but depth is
	//! commonly used instead because range is time-consuming to compute and
	//! depth is generally already available. Using depth to calculate fog has
	//! the undesirable effect of having the fogginess of peripheral objects
	//! change as the viewer's eye moves - in this case, the depth changes and
	//! the range remains constant.
	//! Because no hardware currently supports per-pixel range-based fog,
	//! range correction is offered only for vertex fog.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_rangefogenable = 48,

	//! RS_STENCILENABLE can be set to true to enable stenciling,
	//! or false to disable stenciling. The default value is false.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_stencilenable = 52,

	//! RS_STENCILFAIL is the stencil operation
	//! to perform if the stencil test fails.
	//! Values are from the STENCILOP enumerated type.
	//! The default value is STENCILOP_KEEP.
	e_d3d9_rs_stencilfail = 53,

	//! RS_STENCILZFAIL is the stencil operation to perform if the stencil
	//! test passes and the depth test (z-test) fails. Values are from the
	//! STENCILOP enumerated type. The default value is STENCILOP_KEEP.
	e_d3d9_rs_stencilzfail = 54,

	//! RS_STENCILPASS is the stencil operation to perform if both the stencil
	//! and the depth (z) tests pass. Values are from the STENCILOP enumerated
	//! type. The default value is STENCILOP_KEEP.
	e_d3d9_rs_stencilpass = 55,

	//! RS_STENCILFUNC is the comparison function for the stencil test.
	//! Values are from the CMPFUNC enumerated type. The default value
	//! is CMP_ALWAYS.  The comparison function is used to compare
	//! the reference value to a stencil buffer entry. This comparison applies
	//! only to the bits in the reference value and stencil buffer entry that
	//! are set in the stencil mask (set by the RS_STENCILMASK render state).
	//! If true, the stencil test passes.
	e_d3d9_rs_stencilfunc = 56,

	//! RS_STENCILREF is an int reference value for the stencil test.
	//! The default value is 0.
	e_d3d9_rs_stencilref = 57,

	//! RS_STENCILMASK is the mask applied to the reference value and
	//! each stencil buffer entry to determine the significant bits
	//! for the stencil test. The default mask is 0xFFFFFFFF.
	e_d3d9_rs_stencilmask = 58,

	//! RS_STENCILWRITEMASK is the write mask applied to values
	//! written into the stencil buffer. The default mask is 0xFFFFFFFF.
	e_d3d9_rs_stencilwritemask = 59,

	//! RS_TEXTUREFACTOR is the color used for multiple-texture blending with
	//! the TA_TFACTOR texture-blending argument or the TOP_BLENDFACTORALPHA
	//! texture-blending operation. The associated value is a COLOR variable.
	//! The default value is opaque white (0xFFFFFFFF).
	e_d3d9_rs_texturefactor = 60,

	//! RS_WRAP0 is the texture-wrapping behavior for multiple sets of texture
	//! coordinates. Valid values for this render state can be any combination
	//! of the WRAPCOORD_0 (or WRAP_U), WRAPCOORD_1 (or WRAP_V), WRAPCOORD_2
	//! (or WRAP_W), and WRAPCOORD_3 flags. These cause the system to wrap in
	//! the direction of the 1st, 2nd, 3rd, and 4th dimensions, sometimes
	//! referred to as the s, t, r, and q directions, for a given texture.
	//! The default value for this render state is 0
	//! (wrapping disabled in all directions).
	e_d3d9_rs_wrap0 = 128,
	e_d3d9_rs_wrap1 = 129, //!< RS_WRAP1: @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap2 = 130, //!< RS_WRAP2: @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap3 = 131, //!< RS_WRAP3: @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap4 = 132, //!< RS_WRAP4: @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap5 = 133, //!< RS_WRAP5: @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap6 = 134, //!< RS_WRAP6: @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap7 = 135, //!< RS_WRAP7: @see e_d3d9_rs_wrap0.

	//! RS_CLIPPING can be set to true to enable primitive clipping by
	//! Direct3D, or false to disable it. The default value is true.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_clipping = 136,

	//! RS_LIGHTING can be set to true to enable Direct3D lighting, or false
	//! to disable it. The default value is true. Only vertices that include
	//! a vertex normal are properly lit; vertices that do not contain a
	//! normal employ a dot product of 0 in all lighting calculations.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_lighting = 137,

	//! RS_AMBIENT is the ambient light color.
	//! This value is of type COLOR. The default value is 0.
	e_d3d9_rs_ambient = 139,

	//! RS_FOGVERTEXMODE is the fog formula to be used for vertex fog. Set to
	//! one member of FOGMODE enumerated type. The default value is FOG_NONE.
	e_d3d9_rs_fogvertexmode = 140,

	//! RS_COLORVERTEX can be set to true to enable per-vertex color or false
	//! to disable it. The default value is true. Enabling per-vertex color
	//! allows the system to include the color defined for
	//! individual vertices in its lighting calculations.
	//! For more information, see the following render states:
	//! e_d3d9_rs_diffusematerialsource, e_d3d9_rs_specularmaterialsource,
	//! e_d3d9_rs_ambientmaterialsource, e_d3d9_rs_emissivematerialsource.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_colorvertex = 141,

	//! RS_LOCALVIEWER can be set to true to enable camera-relative specular
	//! highlights, or false to use orthogonal specular highlights.
	//! The default value is true. Applications that use
	//! orthogonal projection should specify false.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_localviewer = 142,

	//! RS_NORMALIZENORMALS can be set to true to enable automatic
	//! normalization of vertex normals, or false to disable it. The default
	//! value is false. Enabling this feature causes the system to normalize
	//! the vertex normals for vertices after transforming them to camera
	//! space, which can be computationally time-consuming.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_normalizenormals = 143,

	//! RS_DIFFUSEMATERIALSOURCE is the diffuse color source for lighting
	//! calculations. Valid values are members of the MATERIALCOLORSOURCE
	//! enumerated type. The default value is MCS_COLOR1. The value for this
	//! render state is used only if the RS_COLORVERTEX render state is set
	//! to true.
	e_d3d9_rs_diffusematerialsource = 145,

	//! RS_SPECULARMATERIALSOURCE is the specular color source for lighting
	//! calculations. Valid values are members of the MATERIALCOLORSOURCE
	//! enumerated type. The default value is MCS_COLOR2.
	e_d3d9_rs_specularmaterialsource = 146,

	//! RS_AMBIENTMATERIALSOURCE is the ambient color source for lighting
	//! calculations. Valid values are members of the MATERIALCOLORSOURCE
	//! enumerated type. The default value is MCS_MATERIAL.
	e_d3d9_rs_ambientmaterialsource = 147,

	//! RS_EMISSIVEMATERIALSOURCE is the emissive color source for lighting
	//! calculations. Valid values are members of the MATERIALCOLORSOURCE
	//! enumerated type. The default value is MCS_MATERIAL.
	e_d3d9_rs_emissivematerialsource = 148,

	//! RS_VERTEXBLEND is the number of matrices to use to perform geometry
	//! blending, if any. Valid values are members of the VERTEXBLENDFLAGS
	//! enumerated type. The default value is VBF_DISABLE.
	e_d3d9_rs_vertexblend = 151,

	//! RS_CLIPPLANEENABLE enables or disables user-defined clipping planes.
	//! Valid values are any uint32 in which the status of each bit (set or
	//! not set) toggles the activation state of a corresponding user-defined
	//! clipping plane. The least significant bit (bit 0) controls the first
	//! clipping plane at index 0, and subsequent bits control the activation
	//! of clipping planes at higher indexes. If a bit is set, the system
	//! applies the appropriate clipping plane during scene rendering.
	//! The default value is 0.
	//! The CLIPPLANEn macros are defined to provide
	//! a convenient way to enable clipping planes.
	e_d3d9_rs_clipplaneenable = 152,

	//! RS_POINTSIZE is a float value that specifies the size to use for point
	//! size computation in cases where point size is not specified for each
	//! vertex. This value is not used when the vertex contains point size.
	//! This value is in screen space units if RS_POINTSCALEENABLE is false;
	//! otherwise this value is in world space units. The default value
	//! is the value a driver returns. If a driver returns 0 or 1,
	//! the default value is 64, which allows software point size emulation.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_pointsize = 154,

	//! RS_POINTSIZE_MIN is a float value that specifies the minimum size of
	//! point primitives. Point primitives are clamped to this size during
	//! rendering. Setting this to values smaller than 1.0 results in points
	//! dropping out when the point does not cover a pixel center and
	//! antialiasing is disabled or being rendered with reduced intensity when
	//! antialiasing is enabled. The default value is 1.0f. The range for this
	//! value is greater than or equal to 0.0f.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_pointsize_min = 155,

	//! RS_POINTSPRITEENABLE is a bool value. When true, texture coordinates
	//! of point primitives are set so that full textures are mapped on each
	//! point. When false, the vertex texture coordinates are used for the
	//! entire point. The default value is false. You can achieve DX7-style
	//! single-pixel points by setting RS_POINTSCALEENABLE to false and
	//! RS_POINTSIZE to 1.0, which are the default values.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_pointspriteenable = 156,

	//! RS_POINTSCALEENABLE is a bool value that controls computation of size
	//! for point primitives. When true, the point size is interpreted as a
	//! camera space value and is scaled by the distance function and the
	//! frustum to viewport y-axis scaling to compute the final screen-space
	//! point size. When false, the point size is interpreted as screen space
	//! and used directly. The default value is false.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_pointscaleenable = 157,

	//! RS_POINTSCALE_A is a float value that controls for
	//! distance-based size attenuation for point primitives. Active only when
	//! RS_POINTSCALEENABLE is true. The default value is 1.0f.
	//! The range for this value is greater than or equal to 0.0f.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_pointscale_a = 158,

	//! RS_POINTSCALE_B is a float value that controls for
	//! distance-based size attenuation for point primitives. Active only when
	//! RS_POINTSCALEENABLE is true. The default value is 0.0f.
	//! The range for this value is greater than or equal to 0.0f.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_pointscale_b = 159,

	//! RS_POINTSCALE_C is a float value that controls for
	//! distance-based size attenuation for point primitives. Active only when
	//! RS_POINTSCALEENABLE is true. The default value is 0.0f.
	//! The range for this value is greater than or equal to 0.0f.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_pointscale_c = 160,

	//! RS_MULTISAMPLEANTIALIAS is a bool value that determines how individual
	//! samples are computed when using a multisample render-target buffer.
	//! When set to true, the multiple samples are computed so that full-scene
	//! antialiasing is performed by sampling at different sample positions
	//! for each multiple sample. When set to false, the multiple samples are
	//! all written with the same sample value, sampled at the pixel center,
	//! which allows non-antialiased rendering to a multisample buffer. This
	//! render state has no effect when rendering to a single sample buffer.
	//! The default value is true.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_multisampleantialias = 161,

	//! RS_MULTISAMPLEMASK is a uint32 mask. Each bit in this mask, starting
	//! at the least significant bit (LSB), controls modification of one of
	//! the samples in a multisample render target. Thus, for an 8-sample
	//! render target, the low byte contains the eight write enables for each
	//! of the eight samples. This render state has no effect when rendering
	//! to a single sample buffer. The default value is 0xFFFFFFFF.
	//! This render state enables use of a multisample buffer as an
	//! accumulation buffer, doing multipass rendering of geometry
	//! where each pass updates a subset of samples.
	//! If there are n multisamples and k enabled samples,
	//! the resulting intensity of the rendered image should be k/n.
	//! Each component RGB of every pixel is factored by k/n.
	e_d3d9_rs_multisamplemask = 162,

	//! RS_PATCHEDGESTYLE sets whether patch edges will use float style
	//! tessellation. Possible values are defined by the PATCHEDGESTYLE
	//! enumerated type. The default value is PATCHEDGE_DISCRETE.
	e_d3d9_rs_patchedgestyle = 163,

	//! RS_DEBUGMONITORTOKEN is set only for debugging the monitor.
	//! Possible values are defined by the DEBUGMONITORTOKENS enumerated type.
	//! Note that if RS_DEBUGMONITORTOKEN is set, the call is treated as
	//! passing a token to the debug monitor. For example, if - after passing
	//! DMT_ENABLE or DMT_DISABLE to RS_DEBUGMONITORTOKEN - other token values
	//! are passed in, the state (enabled or disabled) of the debug monitor
	//! will still persist. This state is only useful for debug builds.
	//! The debug monitor defaults to DMT_ENABLE.
	e_d3d9_rs_debugmonitortoken = 165,

	//! RS_POINTSIZE_MAX is a float value that specifies the maximum size to
	//! which point sprites will be clamped. The value must be less than or
	//! equal to the MaxPointSize member of CAPS and greater than or equal to
	//! RS_POINTSIZE_MIN. The default value is 64.0.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_pointsize_max = 166,

	//! RS_INDEXEDVERTEXBLENDENABLE is a bool value that enables or disables
	//! indexed vertex blending. The default value is false. When set to true,
	//! indexed vertex blending is enabled. When set to false, indexed vertex
	//! blending is disabled. If this render state is enabled, the user must
	//! pass matrix indices as a packed DWORDwith every vertex. When the
	//! render state is disabled and vertex blending is enabled through
	//! the RS_VERTEXBLEND state, it is equivalent to having
	//! matrix indices 0, 1, 2, 3 in every vertex.
	//! Use Device.SetRenderStateBool to set this value.
	e_d3d9_rs_indexedvertexblendenable = 167,

	//! RS_COLORWRITEENABLE is a uint32 value that enables a per-channel write
	//! for the render-target color buffer. A set bit results in the color
	//! channel being updated during 3D rendering. A clear bit results in the
	//! color channel being unaffected. This functionality is available if the
	//! PMISCCAPS_COLORWRITEENABLE capabilities bit is set in the
	//! PrimitiveMiscCaps member of the CAPS structure for the device. This
	//! render state does not affect the clear operation. The default value is
	//! 0x0000000F.
	//! Valid values for this render state can be any combination of the
	//! COLORWRITEENABLE_ALPHA, COLORWRITEENABLE_BLUE, COLORWRITEENABLE_GREEN,
	//! or COLORWRITEENABLE_RED flags.
	e_d3d9_rs_colorwriteenable = 168,

	//! RS_TWEENFACTOR is a float value that controls the tween factor.
	//! The default value is 0.0f.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_tweenfactor = 170,

	//! RS_BLENDOP is used to select the arithmetic operation applied when
	//! the alpha blending render state, RS_ALPHABLENDENABLE, is set to true.
	//! Valid values are defined by the BLENDOP enumerated type.
	//! The default value is BLENDOP_ADD.
	//! If the PMISCCAPS_BLENDOP device capability is not supported,
	//! then BLENDOP_ADD is performed.
	e_d3d9_rs_blendop = 171,

	//! RS_POSITIONDEGREE is the N-patch position interpolation degree.
	//! The values can be DEGREE_CUBIC (default) or DEGREE_LINEAR.
	//! For more information, see DEGREETYPE.
	e_d3d9_rs_positiondegree = 172,

	//! RS_NORMALDEGREE is the N-patch normal interpolation degree.
	//! The values can be DEGREE_LINEAR (default) or DEGREE_QUADRATIC.
	//! For more information, see DEGREETYPE.
	e_d3d9_rs_normaldegree = 173,

	//! RS_SCISSORTESTENABLE can be set to true to enable
	//! scissor testing and false to disable it. The default value is false.
	e_d3d9_rs_scissortestenable = 174,

	//! RS_SLOPESCALEDEPTHBIAS is used to determine how much bias can be
	//! applied to co-planar primitives to reduce z-fighting.  Default is 0.
	//! bias = (max * RS_SLOPESCALEDEPTHBIAS) + RS_DEPTHBIAS.
	//! where max is the maximum depth slope of the triangle being rendered.
	e_d3d9_rs_slopescaledepthbias = 175,

	//! RS_ANTIALIASEDLINEENABLE can be set to true to enable
	//! line antialiasing, false to disable line antialiasing.
	//! The default value is false. When rendering to a multisample RT,
	//! RS_ANTIALIASEDLINEENABLE is ignored & all lines are rendered aliased.
	e_d3d9_rs_antialiasedlineenable = 176,

	//! RS_MINTESSELLATIONLEVEL is the minimum tessellation level.
	//! The default value is 1.0f.
	e_d3d9_rs_mintessellationlevel = 178,

	//! RS_MAXTESSELLATIONLEVEL is the maximum tessellation level.
	//! The default value is 1.0f.
	e_d3d9_rs_maxtessellationlevel = 179,

	//! RS_ADAPTIVETESS_X is the amount to adaptively tessellate,
	//! in the x direction. Default value is 0.0f.
	e_d3d9_rs_adaptivetess_x = 180,

	//! RS_ADAPTIVETESS_Y is the amount to adaptively tessellate,
	//! in the y direction. Default value is 0.0f.
	e_d3d9_rs_adaptivetess_y = 181,

	//! RS_ADAPTIVETESS_Z is the amount to adaptively tessellate,
	//! in the z direction. Default value is 1.0f.
	e_d3d9_rs_adaptivetess_z = 182,

	//! RS_ADAPTIVETESS_W is the amount to adaptively tessellate,
	//! in the w direction. Default value is 0.0f.
	e_d3d9_rs_adaptivetess_w = 183,

	//! RS_ENABLEADAPTIVETESSELLATION can be set to true to enable adaptive
	//! tessellation, false to disable it. The default value is false.
	e_d3d9_rs_enableadaptivetessellation = 184,

	//! RS_TWOSIDEDSTENCILMODE can be set to true to enable two-sided
	//! stenciling, false disables it. The default value is false. The
	//! application should set RS_CULLMODE to CULL_NONE to enable two-sided
	//! stencil mode. If the triangle winding order is clockwise, the
	//! RS_STENCIL* operations will be used. If the winding order is
	//! counterclockwise, the RS_CCW_STENCIL* operations will be used.
	//! To see if two-sided stencil is supported, check the StencilCaps
	//! member of CAPS for STENCILCAPS_TWOSIDED. See also STENCILCAPS.
	e_d3d9_rs_twosidedstencilmode = 185,

	//! RS_CCW_STENCILFAIL is the stencil operation to perform if CCW
	//! stencil test fails. Values are from the STENCILOP enumerated type.
	//! The default value is STENCILOP_KEEP.
	e_d3d9_rs_ccw_stencilfail = 186,

	//! RS_CCW_STENCILZFAIL is the stencil operation to perform if CCW stencil
	//! test passes and z-test fails. Values are from the STENCILOP enumerated
	//! type. The default value is STENCILOP_KEEP.
	e_d3d9_rs_ccw_stencilzfail = 187,

	//! RS_CCW_STENCILPASS is the stencil operation to perform if both CCW
	//! stencil and z-tests pass. Values are from the STENCILOP enumerated
	//! type. The default value is STENCILOP_KEEP.
	e_d3d9_rs_ccw_stencilpass = 188,

	//! RS_CCW_STENCILFUNC is the comparison function. CCW stencil test passes
	//! if ((ref & mask) stencil function (stencil & mask)) is true. Values
	//! are from the CMPFUNC enumerated type. The default value is CMP_ALWAYS.
	e_d3d9_rs_ccw_stencilfunc = 189,

	//! RS_COLORWRITEENABLE1 specifies additional ColorWriteEnable values for
	//! the devices. See RS_COLORWRITEENABLE. This functionality is available
	//! if the PMISCCAPS_INDEPENDENTWRITEMASKS capabilities bit is set in the
	//! PrimitiveMiscCaps member of the CAPS structure for the device.
	//! The default value is 0x0000000F.
	e_d3d9_rs_colorwriteenable1 = 190,

	//! RS_COLORWRITEENABLE2 specifies additional ColorWriteEnable values for
	//! the devices. See RS_COLORWRITEENABLE. This functionality is available
	//! if the PMISCCAPS_INDEPENDENTWRITEMASKS capabilities bit is set in the
	//! PrimitiveMiscCaps member of the CAPS structure for the device.
	//! The default value is 0x0000000F.
	e_d3d9_rs_colorwriteenable2 = 191,

	//! RS_COLORWRITEENABLE3 Additional ColorWriteEnable values for devices.
	//! See RS_COLORWRITEENABLE. This functionality is available if the
	//! PMISCCAPS_INDEPENDENTWRITEMASKS capabilities bit is set in the
	//! PrimitiveMiscCaps member of the CAPS structure for the device.
	//! The default value is 0x0000000F.
	e_d3d9_rs_colorwriteenable3 = 192,

	//! RS_BLENDFACTOR is a COLOR used for a constant blend-factor during alpha
	//! blending. This functionality is available if the PBLENDCAPS_BLENDFACTOR
	//! capabilities bit is set in the SrcBlendCaps member of CAPS or the
	//! DestBlendCaps member of CAPS. See RENDERSTATETYPE.
	//! The default value is 0xFFFFFFFF.
	e_d3d9_rs_blendfactor = 193,

	//! RS_SRGBWRITEENABLE enables render-target writes to be gamma corrected
	//! to sRGB. The format must expose USAGE_SRGBWRITE. The default value =0.
	e_d3d9_rs_srgbwriteenable = 194,

	//! RS_DEPTHBIAS is a floating-point value that is used for
	//! comparison of depth values.  The default value is 0.
	//! Use Device.SetRenderStateFloat to set this value.
	e_d3d9_rs_depthbias = 195,
	
	e_d3d9_rs_wrap8  = 198,	//!< RS_WRAP8  : @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap9  = 199,	//!< RS_WRAP9  : @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap10 = 200,	//!< RS_WRAP10 : @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap11 = 201,	//!< RS_WRAP11 : @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap12 = 202,	//!< RS_WRAP12 : @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap13 = 203,	//!< RS_WRAP13 : @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap14 = 204,	//!< RS_WRAP14 : @see e_d3d9_rs_wrap0.
	e_d3d9_rs_wrap15 = 205,	//!< RS_WRAP15 : @see e_d3d9_rs_wrap0.

	//! RS_SEPARATEALPHABLENDENABLE can be set to true to enable the separate
	//! blend mode for the alpha channel. The default value is false.
	//! When set to false, the render-target blending factors and operations
	//! applied to alpha are forced to be the same as those defined for color.
	//! This mode is effectively hardwired to false on implementations that
	//! don't set the cap PMISCCAPS_SEPARATEALPHABLEND. See PMISCCAPS.
	//! The type of separate alpha blending is determined by the
	//! RS_SRCBLENDALPHA and RS_DESTBLENDALPHA render states.
	e_d3d9_rs_separatealphablendenable = 206,

	//! RS_SRCBLENDALPHA is one member of the BLEND enumerated type.
	//! This value is ignored unless RS_SEPARATEALPHABLENDENABLE is true.
	//! The default value is BLEND_ONE.
	e_d3d9_rs_srcblendalpha = 207,

	//! RS_DESTBLENDALPHA is one member of the BLEND enumerated type.
	//! This value is ignored unless RS_SEPARATEALPHABLENDENABLE is true.
	//! The default value is BLEND_ZERO.
	e_d3d9_rs_destblendalpha = 208,

	//! RS_BLENDOPALPHA is a value used to select the arithmetic operation
	//! applied to separate alpha blending when the render state,
	//! RS_SEPARATEALPHABLENDENABLE, is set to true.
	//! Valid values are defined by the BLENDOP enumerated type.
	//! The default value is BLENDOP_ADD.
	//! If the PMISCCAPS_BLENDOP device capability is not supported,
	//! then BLENDOP_ADD is performed. See PMISCCAPS.
	e_d3d9_rs_blendopalpha = 209,
};

//! RENDERSTATETYPE defines set-up states for all kinds of vertex and pixel
//! processing. Some render states set up vertex processing, and some set up
//! pixel processing. Render states can be saved & restored using stateblocks.
//! ENUM 'e_d3d9_rs_' enumerants define this.
typedef u32 d3d9_renderstatetype_t;


//! RESOURCETYPE defines resource types
enum d3d9_resourcetype_e
{
	//! RTYPE_SURFACE is a surface resource.
	e_d3d9_rtype_surface = 1,

	//! RTYPE_VOLUME is a volume resource.
	e_d3d9_rtype_volume = 2,

	//! RTYPE_TEXTURE is a texture resource.
	e_d3d9_rtype_texture = 3,

	//! RTYPE_VOLUMETEXTURE is a volume texture resource.
	e_d3d9_rtype_volumetexture = 4,

	//! RTYPE_CUBETEXTURE is a cube texture resource.
	e_d3d9_rtype_cubetexture = 5,

	//! RTYPE_VERTEXBUFFER is a vertex buffer resource.
	e_d3d9_rtype_vertexbuffer = 6,

	//! RTYPE_INDEXBUFFER is an index buffer resource.
	e_d3d9_rtype_indexbuffer = 7,
};

//! RESOURCETYPE defines resource types
//! ENUM 'e_d3d9_rtype_' enumerants define this.
typedef u32 d3d9_resourcetype_t;


//! SAMPLER_TEXTURE_TYPE defines the sampler texture types for vertex shaders
enum d3d9_sampler_texture_type_e
{
	//! STT_UNKNOWN is an uninitialized value.
	//! The value of this element is SP_TEXTURETYPE_SHIFT.
	e_d3d9_stt_unknown = 0,

	//! STT_2D declars a 2D texture.
	//! The value of this element is SP_TEXTURETYPE_SHIFT * 4.
	e_d3d9_stt_2d = 268435456,

	//! STT_CUBE declars a cube texture.
	//! The value of this element is SP_TEXTURETYPE_SHIFT * 8.
	e_d3d9_stt_cube = 402653184,

	//! STT_VOLUME declars a volume texture.
	//! The value of this element is SP_TEXTURETYPE_SHIFT * 16.
	e_d3d9_stt_volume = 536870912,
};

//! SAMPLER_TEXTURE_TYPE defines the sampler texture types for vertex shaders
//! ENUM 'e_d3d9_stt_' enumerants define this.
typedef u32 d3d9_sampler_texture_type_t;


//! SAMPLERSTATETYPE defines texture sampling operations such as texture
//! addressing and texture filtering. Some sampler states set-up vertex
//! processing, and some set-up pixel processing. Sampler states can be
//! saved and restored using stateblocks.
enum d3d9_samplerstatetype_e
{
	//! SAMP_ADDRESSU specifies the texture-address mode for the u coordinate.
	//! The default is TADDRESS_WRAP. For more info, see TEXTUREADDRESS.
	e_d3d9_samp_addressu = 1,

	//! SAMP_ADDRESSV specifies the texture-address mode for the v coordinate.
	//! The default is TADDRESS_WRAP. For more info, see TEXTUREADDRESS.
	e_d3d9_samp_addressv = 2,

	//! SAMP_ADDRESSW specifies the texture-address mode for the w coordinate.
	//! The default is TADDRESS_WRAP. For more info, see TEXTUREADDRESS.
	e_d3d9_samp_addressw = 3,

	//! SAMP_BORDERCOLOR specifies the border color or type COLOR.
	//! The default color is 0x00000000.
	e_d3d9_samp_bordercolor = 4,

	//! SAMP_MAGFILTER specifies the magnification filter of type
	//! TEXTUREFILTERTYPE. The default value is TEXF_POINT.
	e_d3d9_samp_magfilter = 5,

	//! SAMP_MINFILTER specifies the minification filter of type
	//! TEXTUREFILTERTYPE. The default value is TEXF_POINT.
	e_d3d9_samp_minfilter = 6,

	//! SAMP_MIPFILTER specifies the mipmap filter to use during
	//! minification. See TEXTUREFILTERTYPE. The default value is TEXF_NONE.
	e_d3d9_samp_mipfilter = 7,

	//! SAMP_MIPMAPLODBIAS specifies the mipmap level-of-detail bias.
	//! The default value is zero.
	e_d3d9_samp_mipmaplodbias = 8,

	//! SAMP_MAXMIPLEVEL specifies the level-of-detail index of the largest
	//! map to use. Values range from 0 to (n - 1) where 0 is the largest.
	//! The default value is zero.
	e_d3d9_samp_maxmiplevel = 9,

	//! SAMP_MAXANISOTROPY specifies the maximum anisotropy. Values range
	//! from 1 to the value that is specified in the MaxAnisotropy member
	//! of the CAPS structure. The default value is 1.
	e_d3d9_samp_maxanisotropy = 10,

	//! SAMP_SRGBTEXTURE specifies the gamma correction value. The default
	//! value is 0, which means gamma is 1.0 and no correction is required.
	//! Otherwise, this value means that the sampler should assume gamma of
	//! 2.2 on the content and convert it to linear (gamma 1.0)
	//! before presenting it to the pixel shader.
	e_d3d9_samp_srgbtexture = 11,

	//! SAMP_ELEMENTINDEX indicates which element index to use, when a
	//! multielement texture is assigned to the sampler. The default is 0.
	e_d3d9_samp_elementindex = 12,

	//! SAMP_DMAPOFFSET specifies the vertex offset in the presampled
	//! displacement map. This is a constant used by the tessellator,
	//! its default value is 0.
	e_d3d9_samp_dmapoffset = 13,
};

//! SAMPLERSTATETYPE defines texture sampling operations such as texture
//! addressing and texture filtering. Some sampler states set-up vertex
//! processing, and some set-up pixel processing. Sampler states can be
//! saved and restored using stateblocks.
//! ENUM 'e_d3d9_samp_' enumerants define this.
typedef u32 d3d9_samplerstatetype_t;


//! SHADEMODE defines constants that describe the supported shading modes
enum d3d9_shademode_e
{
	//! SHADE_FLAT means flat shading mode. The color and specular component
	//! of the first vertex in the triangle are used to determine the color
	//! and specular component of the face. These colors remain constant
	//! across the triangle; that is, they are not interpolated.
	//! The specular alpha is interpolated.
	e_d3d9_shade_flat = 1,

	//! SHADE_GOURAUD means gouraud shading mode. The color and
	//! specular components of the face are determined by a linear
	//! interpolation between all three of the triangle's vertices.
	e_d3d9_shade_gouraud = 2,

	//! SHADE_PHONG is not supported.
	e_d3d9_shade_phong = 3,
};

//! SHADEMODE defines constants that describe the supported shading modes
//! ENUM 'e_d3d9_shade_' enumerants define this.
typedef u32 d3d9_shademode_t;


//! STATEBLOCKTYPE predefines sets of pipeline state used by state blocks
enum d3d9_stateblocktype_e
{
	//! SBT_ALL captures the current device state.
	e_d3d9_sbt_all = 1,

	//! SBT_PIXELSTATE capture the current pixel state.
	e_d3d9_sbt_pixelstate = 2,

	//! SBT_VERTEXSTATE capture the current vertex state.
	e_d3d9_sbt_vertexstate = 3,
};

//! STATEBLOCKTYPE predefines sets of pipeline state used by state blocks
//! ENUM 'e_d3d9_sbt_' enumerants define this.
typedef u32 d3d9_stateblocktype_t;


//! STENCILOP defines stencil-buffer operations
enum d3d9_stencilop_e
{
	//! STENCILOP_KEEP does not update the entry in the stencil buffer.
	//! This is the default value.
	e_d3d9_stencilop_keep = 1,

	//! STENCILOP_ZERO sets the stencil-buffer entry to 0.
	e_d3d9_stencilop_zero = 2,

	//! STENCILOP_REPLACE replaces the stencil-buffer
	//! entry with a reference value.
	e_d3d9_stencilop_replace = 3,

	//! STENCILOP_INCRSAT increments the stencil-buffer entry,
	//! clamping to the maximum value.
	e_d3d9_stencilop_incrsat = 4,

	//! STENCILOP_DECRSAT decrements the stencil-buffer entry, clamping to 0.
	e_d3d9_stencilop_decrsat = 5,

	//! STENCILOP_INVERT inverts the bits in the stencil-buffer entry.
	e_d3d9_stencilop_invert = 6,

	//! STENCILOP_INCR increments the stencil-buffer entry, wrapping
	//! to zero if the new value exceeds the maximum value.
	e_d3d9_stencilop_incr = 7,

	//! STENCILOP_DECR decrements the stencil-buffer entry, wrapping
	//! to the maximum value if the new value is less than zero.
	e_d3d9_stencilop_decr = 8,
};

//! STENCILOP defines stencil-buffer operations
//! ENUM 'e_d3d9_stencilop_' enumerants define this.
typedef u32 d3d9_stencilop_t;


//! SWAPEFFECT defines swap effects
enum d3d9_swapeffect_e
{
	//! SWAPEFFECT_DISCARD When a swap chain is created with a swap effect of
	//! SWAPEFFECT_FLIP or SWAPEFFECT_COPY, the runtime will guarantee that an
	//! Device.Present operation will not affect the content of any of the back
	//! buffers. Unfortunately, meeting this guarantee can involve substantial
	//! video memory or processing overheads, especially when implementing flip
	//! semantics for a windowed swap chain or copy semantics for a full-screen
	//! swap chain. An application may use the SWAPEFFECT_DISCARD swap effect to
	//! avoid these overheads and to enable the display driver to select the
	//! most efficient presentation technique for the swap chain. This is also
	//! the only swap effect that may be used when specifying a value other than
	//! MULTISAMPLE_NONE for the MultiSampleType member of PRESENT_PARAMETERS.
	//! Like a swap chain that uses SWAPEFFECT_FLIP, a swap chain that uses
	//! SWAPEFFECT_DISCARD might include more than one back buffer, any of which
	//! may be accessed using Device.GetBackBuffer or SwapChain.GetBackBuffer.
	//! The swap chain is best envisaged as a queue in which 0 always indexes
	//! the back buffer that will be displayed by the next Present operation and
	//! from which buffers are discarded when they have been displayed.
	//! An application that uses this swap effect cannot make any assumptions
	//! about the contents of a discarded back buffer and should therefore
	//! update an entire back buffer before invoking a Present operation that
	//! would display it. Although this is not enforced, the debug version of
	//! the runtime will overwrite the contents of discarded back buffers with
	//! random data to enable developers to verify that their applications are
	//! updating the entire back buffer surfaces correctly.
	e_d3d9_swapeffect_discard = 1,

	//! SWAPEFFECT_FLIP The swap chain might include multiple back buffers and
	//! is best envisaged as a circular queue that includes the front buffer.
	//! Within this queue, the back buffers are always numbered sequentially
	//! from 0 to (n - 1), where n is the number of back buffers, so that 0
	//! denotes the least recently presented buffer. When Present is invoked,
	//! the queue is "rotated" so that the front buffer becomes back buffer (n -
	//! 1), while the back buffer 0 becomes the new front buffer.
	e_d3d9_swapeffect_flip = 2,

	//! SWAPEFFECT_COPY This swap effect may be specified only for a swap chain
	//! comprising a single back buffer. Whether the swap chain is windowed or
	//! full-screen, the runtime will guarantee the semantics implied by a
	//! copy-based Present operation, namely that the operation leaves the
	//! content of the back buffer unchanged, instead of replacing it with the
	//! content of the front buffer as a flip-based Present operation would.
	//! For a full-screen swap chain, the runtime uses a combination of flip
	//! operations and copy operations, supported if necessary by hidden back
	//! buffers, to accomplish the Present operation. Accordingly, the
	//! presentation is synchronized with the display adapter's vertical retrace
	//! and its rate is constrained by the chosen presentation interval. A swap
	//! chain specified with the PRESENT_INTERVAL_IMMEDIATE flag is the only
	//! exception. (Refer to the description of the PresentationIntervals member
	//! of the PRESENT_PARAMETERS structure.) In this case, a Present operation
	//! copies the back buffer content directly to the front buffer without
	//! waiting for the vertical retrace.
	e_d3d9_swapeffect_copy = 3,
};

//! SWAPEFFECT defines swap effects
//! ENUM 'e_d3d9_swapeffect_' enumerants define this.
typedef u32 d3d9_swapeffect_t;


//! TEXTUREADDRESS defines constants that
//! describe supported texture-addressing modes
enum d3d9_textureaddress_e
{
	//! TADDRESS_WRAP tiles the texture at every integer junction. For example,
	//! for u values between 0 and 3, the texture is repeated three times; no
	//! mirroring is performed.
	e_d3d9_taddress_wrap = 1,

	//! TADDRESS_MIRROR is similar to TADDRESS_WRAP, except that the texture
	//! is flipped at every integer junction.   For u values between 0 and 1,
	//! for example, the texture is addressed normally;
	//! between 1 and 2, the texture is flipped (mirrored);
	//! between 2 and 3, the texture is normal again; and so on.
	e_d3d9_taddress_mirror = 2,

	//! TADDRESS_CLAMP means texture coordinates outside the range [0.0, 1.0]
	//! are set to the texture color at 0.0 or 1.0, respectively.
	e_d3d9_taddress_clamp = 3,

	//! TADDRESS_BORDER means texture coordinates outside the range [0.0, 1.0]
	//! are set to the border color.
	e_d3d9_taddress_border = 4,

	//! TADDRESS_MIRRORONCE is similar to TADDRESS_MIRROR and TADDRESS_CLAMP.
	//! Takes the absolute value of the texture coordinate (thus, mirroring
	//! around 0), and then clamps to the maximum value. The most common usage
	//! is for volume textures, where support for the full TADDRESS_MIRRORONCE
	//! texture-addressing mode is not necessary, but the data is symmetric
	//! around the one axis.
	e_d3d9_taddress_mirroronce = 5,
};

//! TEXTUREADDRESS defines constants that
//! describe supported texture-addressing modes
//! Enumerants of ilk 'e_d3d9_taddress_' define this.
typedef u32 d3d9_textureaddress_t;


//! TEXTUREFILTERTYPE defines texture filtering modes for a texture stage
enum d3d9_texturefiltertype_e
{
	//! TEXF_NONE when used with SAMP_MIPFILTER, disables mipmapping.
	e_d3d9_texf_none = 0,

	//! TEXF_POINT when used with SAMP_ MAGFILTER or SAMP_MINFILTER, specifies
	//! that point filtering is to be used as the texture magnification or
	//! minification filter respectively. When used with SAMP_MIPFILTER,
	//! enables mipmapping and specifies that the rasterizer chooses the
	//! color from the texel of the nearest mip level.
	e_d3d9_texf_point = 1,

	//! TEXF_LINEAR when used with SAMP_MAGFILTER or SAMP_MINFILTER, specifies
	//! that linear filtering is to be used as the texture magnification or
	//! minification filter respectively. When used with SAMP_MIPFILTER,
	//! enables mipmapping and trilinear filtering; it specifies that
	//! the rasterizer interpolates between the two nearest mip levels.
	e_d3d9_texf_linear = 2,

	//! TEXF_ANISOTROPIC when used with SAMP_ MAGFILTER or SAMP_MINFILTER,
	//! specifies that anisotropic texture filtering used as a texture
	//! magnification or minification filter respectively. Compensates for
	//! distortion caused by the difference in angle between a texture polygon
	//! and the plane of the screen. Use with SAMP_MIPFILTER is undefined.
	e_d3d9_texf_anisotropic = 3,

	//! TEXF_PYRAMIDALQUAD is a 4-sample tent filter used
	//! as a texture magnification or minification filter.
	//! Use with SAMP_MIPFILTER is undefined.
	e_d3d9_texf_pyramidalquad = 6,

	//! TEXF_GAUSSIANQUAD is a 4-sample Gaussian filter used
	//! as a texture magnification or minification filter.
	//! Use with SAMP_MIPFILTER is undefined.
	e_d3d9_texf_gaussianquad = 7,
};

//! TEXTUREFILTERTYPE defines texture filtering modes for a texture stage
//! Enumerants of ilk 'e_d3d9_texf_' define this.
typedef u32 d3d9_texturefiltertype_t;


//! TEXTUREOP defines per-stage texture-blending operations
enum d3d9_textureop_e
{
	//! TOP_DISABLE disables output from this texture stage and all stages
	//! with a higher index. To disable texture mapping, set this as the color
	//! operation for the first texture stage (stage 0). Alpha operations
	//! cannot be disabled when color operations are enabled. Setting the
	//! alpha operation to TOP_DISABLE when color blending is enabled causes
	//! undefined behavior.
	e_d3d9_top_disable = 1,

	//! TOP_SELECTARG1 uses this texture stage's first color or alpha
	//! argument, unmodified, as the output. This operation affects the
	//! color argument when used with the TSS_COLOROP texture-stage state,
	//! and the alpha argument when used with TSS_ALPHAOP.
	//! S(RGBA) = Arg1
	e_d3d9_top_selectarg1 = 2,

	//! TOP_SELECTARG2 Use this texture stage's second color or alpha
	//! argument, unmodified, as the output. This operation affects the
	//! color argument when used with the D3DTSS_COLOROP texture stage state,
	//! and the alpha argument when used with D3DTSS_ALPHAOP.
	//! S(RGBA) = Arg2
	e_d3d9_top_selectarg2 = 3,

	//! TOP_MODULATE multiplies the components of the arguments.
	//! S(RGBA) = Arg1*Arg2
	e_d3d9_top_modulate = 4,

	//! TOP_MODULATE2X multiplies the components of the arguments, and shift
	//! the products to the left 1 bit (effectively multiplying them by 2)
	//! for brightening.
	//! S(RGBA) = (Arg1*Arg2)<<1
	e_d3d9_top_modulate2x = 5,

	//! TOP_MODULATE4X multiplies the components of the arguments, and shift
	//! the products to the left 2 bits (effectively multiplying them by 4)
	//! for brightening.
	//! S(RGBA) = (Arg1*Arg2)<<2
	e_d3d9_top_modulate4x = 6,

	//! TOP_ADD adds the components of the arguments.
	//! S(RGBA) = Arg1+Arg2
	e_d3d9_top_add = 7,

	//! TOP_ADDSIGNED adds the components of the arguments with a - 0.5 bias,
	//! making the effective range of values from - 0.5 through 0.5.
	//! S(RGBA) = Arg1+Arg2-0.5
	e_d3d9_top_addsigned = 8,

	//! TOP_ADDSIGNED2X adds the components of the arguments with
	//! a - 0.5 bias, and shift the products to the left 1 bit.
	//! S(RGBA) = (Arg1+Arg2-0.5)<<1
	e_d3d9_top_addsigned2x = 9,

	//! TOP_SUBTRACT subtracts the components of the
	//! second argument from those of the first argument.
	//! S(RGBA) = Arg1-Arg2
	e_d3d9_top_subtract = 10,

	//! TOP_ADDSMOOTH adds the first and second arguments;
	//! then subtract their product from the sum.
	//! S(RGBA) = Arg1+Arg2 - Arg1*Arg2 = Arg1+Arg2*(1-Arg1)
	e_d3d9_top_addsmooth = 11,

	//! TOP_BLENDDIFFUSEALPHA linearly blends this texture stage,
	//! using the interpolated alpha from each vertex.
	//! S(RGBA) = Arg1*Alpha + Arg2*(1-Alpha)
	e_d3d9_top_blenddiffusealpha = 12,

	//! TOP_BLENDTEXTUREALPHA linearly blends this texture
	//! stage, using the alpha from this stage's texture.
	//! S(RGBA) = Arg1*Alpha + Arg2*(1-Alpha)
	e_d3d9_top_blendtexturealpha = 13,

	//! TOP_BLENDFACTORALPHA linearly blends this texture stage,
	//! using a scalar alpha set with the D3DRS_TEXTUREFACTOR render state.
	//! S(RGBA) = Arg1*Alpha + Arg2*(1-Alpha)
	e_d3d9_top_blendfactoralpha = 14,

	//! TOP_BLENDTEXTUREALPHAPM linearly blends a
	//! texture stage that uses a premultiplied alpha.
	//! S(RGBA) = Arg1 + Arg2*(1-Alpha)
	e_d3d9_top_blendtexturealphapm = 15,

	//! TOP_BLENDCURRENTALPHA linearly blends this texture stage, using the
	//! alpha taken from the previous texture stage.
	//! S(RGBA) = Arg1*Alpha + Arg2*(1-Alpha)
	e_d3d9_top_blendcurrentalpha = 16,

	//! TOP_PREMODULATE is set in stage n. The output of stage n is arg1.
	//! Additionally, if there is a texture in stage n + 1, any TA_CURRENT in
	//! stage n + 1 is premultiplied by texture in stage n + 1.
	e_d3d9_top_premodulate = 17,

	//! TOP_MODULATEALPHA_ADDCOLOR modulates the color of the second argument,
	//! using the alpha of the first argument; then add the result to argument
	//! one. This operation is supported only for color operations
	//! (D3DTSS_COLOROP).
	//! S(RGBA) = Arg1(RGB)+Arg1(A)*Arg2(RGB)
	e_d3d9_top_modulatealpha_addcolor = 18,

	//! TOP_MODULATECOLOR_ADDALPHA modulates the arguments; then add the alpha
	//! of the first argument. This operation is supported only for color
	//! operations (D3DTSS_COLOROP).
	//! S(RGBA) = Arg1(RGB)*Arg2(RGB)+Arg1(A)
	e_d3d9_top_modulatecolor_addalpha = 19,

	//! TOP_MODULATEINVALPHA_ADDCOLOR is similar to TOP_MODULATEALPHA_ADDCOLOR,
	//! but use the inverse of the alpha of the first argument. This operation
	//! is supported only for color operations (TSS_COLOROP).
	//! S(RGBA) = (1-Arg1(A))*Arg2(RGB)+Arg1(RGB)
	e_d3d9_top_modulateinvalpha_addcolor = 20,

	//! TOP_MODULATEINVCOLOR_ADDALPHA is similar to TOP_MODULATECOLOR_ADDALPHA,
	//! but use the inverse of the color of the first argument. This operation
	//! is supported only for color operations (TSS_COLOROP).
	//! S(RGBA) = (1-Arg1(RGB))*Arg2(RGB)+Arg1(A)
	e_d3d9_top_modulateinvcolor_addalpha = 21,

	//! TOP_BUMPENVMAP performs per-pixel bump mapping, using the environment
	//! map in the next texture stage, without luminance. This operation is
	//! supported only for color operations (TSS_COLOROP).
	e_d3d9_top_bumpenvmap = 22,

	//! TOP_BUMPENVMAPLUMINANCE performs per-pixel bump mapping, using the
	//! environment map in the next texture stage, with luminance. This
	//! operation is supported only for color operations (TSS_COLOROP).
	e_d3d9_top_bumpenvmapluminance = 23,

	//! TOP_DOTPRODUCT3 modulates the components of each argument as signed
	//! components, add their products; then replicate the sum to all color
	//! channels, including alpha. This operation is supported for color and
	//! alpha operations.
	//! S(RGBA) = Arg1(R)*Arg2(R) + Arg1(G)*Arg2(G) + Arg1(B)*Arg2(B)
	//! In DirectX 6 and DirectX 7, multitexture operations the above inputs are
	//! all shifted down by half (y = x - 0.5) before use to simulate signed
	//! data, and the scalar result is automatically clamped to positive values
	//! and replicated to all three output channels. Also, note that as a color
	//! operation this does not updated the alpha it just updates the RGB
	//! components.
	//! However, in DirectX 8.1 shaders you can specify that the output be
	//! routed to the .rgb or the .a components or both (the default). You can
	//! also specify a separate scalar operation on the alpha channel.
	e_d3d9_top_dotproduct3 = 24,

	//! TOP_MULTIPLYADD performs a multiply-accumulate operation. It takes the
	//! last two arguments, multiplies them together, and adds them to the
	//! remaining input/source argument, and places that into the result.
	//! S(RGBA) = Arg1 + Arg2*Arg3
	e_d3d9_top_multiplyadd = 25,

	//! TOP_LERP linearly interpolates between the second and third source
	//! arguments by a proportion specified in the first source argument.
	//! S(RGBA) = Arg1*Arg2 + (1-Arg1)*Arg3
	e_d3d9_top_lerp = 26,
};

//! TEXTUREOP defines per-stage texture-blending operations
//! Enumerants of ilk 'e_d3d9_top_' define this.
typedef u32 d3d9_textureop_t;


//! TEXTURESTAGESTATETYPE defines multi-blender texture operations. Some
//! sampler states set up vertex processing, and some set up pixel processing.
//! Texture stage states can be saved and restored using stateblocks.
enum d3d9_texturestagestatetype_e
{
	//! TSS_COLOROP texture-stage state is a texture color blending operation
	//! identified by one member of the TEXTUREOP enumerated type. The default
	//! value for the first texture stage (stage 0) is TOP_MODULATE; for all
	//! other stages the default is TOP_DISABLE.
	e_d3d9_tss_colorop = 1,

	//! TSS_COLORARG1 texture-stage state is the first color argument for the
	//! stage, identified by one of the TA. The default argument is TA_TEXTURE.
	//! Specify TA_TEMP to select a temporary register color for read or write.
	//! TA_TEMP is supported if the PMISCCAPS_TSSARGTEMP device capability is
	//! present. The default value for the register is (0.0, 0.0, 0.0, 0.0).
	e_d3d9_tss_colorarg1 = 2,

	//! TSS_COLORARG2 texture-stage state is the second color argument for the
	//! stage, identified by TA. The default argument is TA_CURRENT. Specify
	//! TA_TEMP to select a temporary register color for read or write. TA_TEMP
	//! is supported if the PMISCCAPS_TSSARGTEMP device capability is present.
	//! The default value for the register is (0.0, 0.0, 0.0, 0.0)
	e_d3d9_tss_colorarg2 = 3,

	//! TSS_ALPHAOP texture-stage state is a texture alpha blending operation
	//! identified by one member of the TEXTUREOP enumerated type. The default
	//! value for the first texture stage (stage 0) is TOP_SELECTARG1, and for
	//! all other stages the default is TOP_DISABLE.
	e_d3d9_tss_alphaop = 4,

	//! TSS_ALPHAARG1 texture-stage state is the first alpha argument for the
	//! stage, identified by by TA. The default argument is TA_TEXTURE. If no
	//! texture is set for this stage, the default argument is TA_DIFFUSE.
	//! Specify TA_TEMP to select a temporary register color for read or write.
	//! TA_TEMP is supported if the PMISCCAPS_TSSARGTEMP device capability is
	//! present. The default value for the register is (0.0, 0.0, 0.0, 0.0).
	e_d3d9_tss_alphaarg1 = 5,

	//! TSS_ALPHAARG2 texture-stage state is the second alpha argument for the
	//! stage, identified by by TA. The default argument is TA_CURRENT. Specify
	//! TA_TEMP to select a temporary register color for read or write. TA_TEMP
	//! is supported if the PMISCCAPS_TSSARGTEMP device capability is present.
	//! The default value for the register is (0.0, 0.0, 0.0, 0.0).
	e_d3d9_tss_alphaarg2 = 6,

	//! TSS_BUMPENVMAT00 texture-stage state is a floating-point value for the
	//! [0][0] coefficient in a bump-mapping matrix. The default value is 0.0.
	e_d3d9_tss_bumpenvmat00 = 7,

	//! TSS_BUMPENVMAT01 texture-stage state is a floating-point value for the
	//! [0][1] coefficient in a bump-mapping matrix. The default value is 0.0.
	e_d3d9_tss_bumpenvmat01 = 8,

	//! TSS_BUMPENVMAT10 texture-stage state is a floating-point value for the
	//! [1][0] coefficient in a bump-mapping matrix. The default value is 0.0.
	e_d3d9_tss_bumpenvmat10 = 9,

	//! TSS_BUMPENVMAT11 texture-stage state is a floating-point value for the
	//! [1][1] coefficient in a bump-mapping matrix. The default value is 0.0.
	e_d3d9_tss_bumpenvmat11 = 10,

	//! TSS_TEXCOORDINDEX is an index of the texture coordinate set to use with
	//! this texture stage. You can specify up to eight sets of texture
	//! coordinates per vertex. If a vertex does not include a set of texture
	//! coordinates at the specified index, the system defaults to the u and v
	//! coordinates (0,0).
	//! When rendering using vertex shaders, each stage's texture coordinate
	//! index must be set to its default value. The default index for each stage
	//! is equal to the stage index. Set this state to the zero-based index of
	//! the coordinate set for each vertex that this texture stage uses.
	//! Additionally, applications can include, as logical OR with the index
	//! being set, one of the constants to request that Direct3D automatically
	//! generate the input texture coordinates for a texture transformation.
	//! With the exception of TSS_TCI_PASSTHRU, which resolves to zero, if any
	//! of the following values is included with the index being set, the system
	//! uses the index strictly to determine texture wrapping mode. These flags
	//! are most useful when performing environment mapping.
	e_d3d9_tss_texcoordindex = 11,

	//! TSS_BUMPENVLSCALE is a floating-point scale value for bump-map
	//! luminance. The default value is 0.0.
	e_d3d9_tss_bumpenvlscale = 22,

	//! TSS_BUMPENVLOFFSET is a floating-point offset value for bump-map
	//! luminance. The default value is 0.0.
	e_d3d9_tss_bumpenvloffset = 23,

	//! TSS_TEXTURETRANSFORMFLAGS is a member of the TEXTURETRANSFORMFLAGS
	//! enumerated type that controls the transformation of texture coordinates
	//! for this texture stage. The default value is TTFF_DISABLE.
	e_d3d9_tss_texturetransformflags = 24,

	//! TSS_COLORARG0 specifies settings for the third color operand for triadic
	//! operations (multiply, add, and linearly interpolate), identified by TA.
	//! This setting is supported if the TEXOPCAPS_MULTIPLYADD or TEXOPCAPS_LERP
	//! device capabilities are present. The default argument is TA_CURRENT.
	//! Specify TA_TEMP to select a temporary register color for read or write.
	//! TA_TEMP is supported if the PMISCCAPS_TSSARGTEMP device capability is
	//! present. The default value for the register is (0.0, 0.0, 0.0, 0.0).
	e_d3d9_tss_colorarg0 = 26,

	//! TSS_ALPHAARG0 specifies settings for the alpha channel selector operand
	//! for triadic operations (multiply, add, and linearly interpolate),
	//! identified by TA. This setting is supported if the TEXOPCAPS_MULTIPLYADD
	//! or TEXOPCAPS_LERP device capabilities are present. The default argument
	//! is TA_CURRENT. Specify TA_TEMP to select a temporary register color for
	//! read or write. TA_TEMP is supported if the PMISCCAPS_TSSARGTEMP device
	//! capability is present. The default argument is (0.0, 0.0, 0.0, 0.0).
	e_d3d9_tss_alphaarg0 = 27,

	//! TSS_RESULTARG is a setting to select destination register for the result
	//! of this stage, identified by TA. This value can be set to TA_CURRENT
	//! (the default value) or to TA_TEMP, which is a single temporary register
	//! that can be read into subsequent stages as an input argument. The final
	//! color passed to the fog blender and frame buffer is taken from
	//! TA_CURRENT, so the last active texture stage state must be set to write
	//! to current. This setting is supported if the PMISCCAPS_TSSARGTEMP device
	//! capability is present.
	e_d3d9_tss_resultarg = 28,

	//! TSS_CONSTANT is a per-stage constant color. To see if a device supports
	//! a per-stage constant color, see the PMISCCAPS_PERSTAGECONSTANT constant
	//! in PMISCCAPS. TSS_CONSTANT is used by TA_CONSTANT.
	e_d3d9_tss_constant = 32,
};

//! TEXTURESTAGESTATETYPE defines multi-blender texture operations. Some
//! sampler states set up vertex processing, and some set up pixel processing.
//! Texture stage states can be saved and restored using stateblocks.
//! Enumerants of ilk 'e_d3d9_tss_' define this.
typedef u32 d3d9_texturestagestatetype_t;


//! TEXTURETRANSFORMFLAGS defines texture coordinate transformation values
enum d3d9_texturetransformflags_e
{
	//! TTFF_DISABLE means texture coordinates
	//! are passed directly to the rasterizer.
	e_d3d9_ttff_disable = 0,

	//! TTFF_COUNT1 means the rasterizer should expect 1D texture coordinates.
	//! This value is used by fixed function vertex processing;
	//! it should be set to 0 when using a programmable vertex shader.
	e_d3d9_ttff_count1 = 1,

	//! TTFF_COUNT2 means the rasterizer should expect 2D texture coordinates.
	//! This value is used by fixed function vertex processing;
	//! it should be set to 0 when using a programmable vertex shader.
	e_d3d9_ttff_count2 = 2,

	//! TTFF_COUNT3 means the rasterizer should expect 3D texture coordinates.
	//! This value is used by fixed function vertex processing;
	//! it should be set to 0 when using a programmable vertex shader.
	e_d3d9_ttff_count3 = 3,

	//! TTFF_COUNT4 means the rasterizer should expect 4D texture coordinates.
	//! This value is used by fixed function vertex processing;
	//! it should be set to 0 when using a programmable vertex shader.
	e_d3d9_ttff_count4 = 4,

	//! TTFF_PROJECTED is a flag honored by the fixed function pixel pipeline,
	//! as well as the programmable pixel pipeline in versions ps_1_1 to ps_1_3.
	//! When texture projection is enabled for a texture stage, all four
	//! floating point values must be written to the corresponding texture
	//! register. Each texture coordinate is divided by the last element before
	//! being passed to the rasterizer. For example, if this flag is specified
	//! with the TTFF_COUNT3 flag, the first and second texture coordinates are
	//! divided by the third coordinate before being passed to the rasterizer.
	e_d3d9_ttff_projected = 256,
};

//! TEXTURETRANSFORMFLAGS defines texture coordinate transformation values
//! Enumerants of ilk 'e_d3d9_ttff_' define this.
typedef u32 d3d9_texturetransformflags_t;


//! TRANSFORMSTATETYPE define consts that describe transformation state values
enum d3d9_transformstatetype_e
{
	//! TS_VIEW identifies the transformation matrix being set as the view
	//! transformation matrix. The default value is nil (the identity matrix).
	e_d3d9_ts_view = 2,

	//! TS_PROJECTION identifies the transformation matrix being set as the
	//! projection transformation matrix.
	//! The default value is nil (the identity matrix).
	e_d3d9_ts_projection = 3,

	//! TS_TEXTURE0 identifies the transformation
	//! matrix being set for texture stage 0.
	e_d3d9_ts_texture0 = 16,

	//! TS_TEXTURE1 identifies the transformation
	//! matrix being set for texture stage 1.
	e_d3d9_ts_texture1 = 17,

	//! TS_TEXTURE2 identifies the transformation
	//! matrix being set for texture stage 2.
	e_d3d9_ts_texture2 = 18,

	//! TS_TEXTURE3 identifies the transformation
	//! matrix being set for texture stage 3.
	e_d3d9_ts_texture3 = 19,

	//! TS_TEXTURE4 identifies the transformation
	//! matrix being set for texture stage 4.
	e_d3d9_ts_texture4 = 20,

	//! TS_TEXTURE5 identifies the transformation
	//! matrix being set for texture stage 5.
	e_d3d9_ts_texture5 = 21,

	//! TS_TEXTURE6 identifies the transformation
	//! matrix being set for texture stage 6.
	e_d3d9_ts_texture6 = 22,

	//! TS_TEXTURE7 identifies the transformation
	//! matrix being set for texture stage 7.
	e_d3d9_ts_texture7 = 23,
};

//! TRANSFORMSTATETYPE define consts that describe transformation state values
//! Enumerants of ilk 'e_d3d9_ts' define this.
typedef u32 d3d9_transformstatetype_t;


//! VERTEXBLENDFLAGS defines flags used to control the number or matrices
//! that the system applies when performing multimatrix vertex blending
enum d3d9_vertexblendflags_e
{
	//! VBF_DISABLE disables vertex blending;
	//! apply only the world matrix set by the TS_WORLDMATRIX macro,
	//! where the index value for the transformation state is 0.
	e_d3d9_vbf_disable = 0,

	//! VBF_1WEIGHTS enables vertex blending
	//! between the two matrices set by the TS_WORLDMATRIX macro,
	//! where the index value for the transformation states are 0 and 1.
	e_d3d9_vbf_1weights = 1,

	//! VBF_2WEIGHTS enables vertex blending between the three matrices set by
	//! the TS_WORLDMATRIX macro, where the index value for the transformation
	//! states are 0, 1, and 2.
	e_d3d9_vbf_2weights = 2,

	//! VBF_3WEIGHTS enables vertex blending between the four matrices set by
	//! the TS_WORLDMATRIX macro, where the index value for the transformation
	//! states are 0, 1, 2, and 3.
	e_d3d9_vbf_3weights = 3,

	//! VBF_TWEENING means vertex blending is done by
	//! using the value assigned to RS_TWEENFACTOR.
	e_d3d9_vbf_tweening = 255,

	//! VBF_0WEIGHTS uses a single matrix with a weight of 1.0.
	e_d3d9_vbf_0weights = 256,
};

//! VERTEXBLENDFLAGS defines flags used to control the number or matrices
//! that the system applies when performing multimatrix vertex blending
//! Enumerants of ilk 'e_d3d9_vbf' define this.
typedef u16 d3d9_vertexblendflags_t;


//! ZBUFFERTYPE defines constants that describe depth-buffer formats
enum d3d9_zbuffertype_e
{
	e_d3d9_zb_false = 0 ,//!< ZB_FALSE disables depth buffering.
	e_d3d9_zb_true  = 1 ,//!< ZB_TRUE enables z-buffering.
	e_d3d9_zb_usew  = 2 ,//!< ZB_USEW enables w-buffering.
};

//! ZBUFFERTYPE defines constants that describe depth-buffer formats
//! Enumerants of ilk 'e_d3d9_zb' define this.
typedef u32 d3d9_zbuffertype_t;


#endif /* HEADER_D3D9ENUM_H_ */


