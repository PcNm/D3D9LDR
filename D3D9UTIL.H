/*
 * D3D9UTIL.H : Utility Functions For Direct3D9, Version 9.0c.
 *
 *  Created on: 23 sep. 2019
 *      Author: Martin Andreasson
 */

#ifndef HEADER_D3D9UTIL_H_
#define HEADER_D3D9UTIL_H_

#include "ENGINE/SUPPORT/HARDFORM.H"

#include "ENGINE/DIRECT3D/D3D9ENUM.H" // enums
#include "ENGINE/DIRECT3D/D3D9TYPE.H" // types

#define SI static HF_INLINE


//! ColorARGB converts the given color channel values to a color.
//! Each channel ranges from 0 (no intensity) to 255 (full intensity).
SI d3d9_color_t d3d9_color_argb( u08 a, u08 r, u08 g, u08 b )
{
	return  (d3d9_color_t)
		 ( ((d3d9_color_t) a << (d3d9_color_t) 24u )
	     | ((d3d9_color_t) r << (d3d9_color_t) 16u )
	     | ((d3d9_color_t) g << (d3d9_color_t) 8u  )
	     | ((d3d9_color_t) b                       )
	     );
}

//! ColorRGBA converts the given color channel values to a color.
//! Each channel ranges from 0 (no intensity) to 255 (full intensity).
SI d3d9_color_t d3d9_color_rgba( u08 r, u08 g, u08 b, u08 a )
{
	return d3d9_color_argb( a, r, g, b );
}

//! ColorXRGB converts the given color channel values to a color.
//! Each channel ranges from 0 (no intensity) to 255 (full intensity).
SI d3d9_color_t d3d9_color_xrgb( u08 r, u08 g, u08 b )
{
	return d3d9_color_argb( 0xFF, r, g, b );
}

//! ColorRGB converts the given color channel values to a color.
//! Each channel ranges from 0 (no intensity) to 255 (full intensity).
SI d3d9_color_t d3d9_color_rgb( u08 r, u08 g, u08 b )
{
	return d3d9_color_argb( 0xFF, r, g, b );
}

//! ColorXYUV converts the given color channel values to a color.
//! Each channel ranges from 0 (no intensity) to 255 (full intensity).
SI d3d9_color_t d3d9_color_xyuv( u08 y, u08 u, u08 v )
{
	return d3d9_color_argb( 0xFF, y, u, v );
}

//! ColorYUV converts the given color channel values to a color.
//! Each channel ranges from 0 (no intensity) to 255 (full intensity).
SI d3d9_color_t d3d9_color_yuv( u08 y, u08 u, u08 v )
{
	return d3d9_color_argb( 0xFF, y, u, v );
}

//! ColorAYUV converts the given color channel values to a color.
//! Each channel ranges from 0 (no intensity) to 255 (full intensity).
SI d3d9_color_t d3d9_color_ayuv( u08 a, u08 y, u08 u, u08 v )
{
	return d3d9_color_argb( a, y, u, v );
}

//! ColorValue converts the given color channel values to a color.
//! Each channel ranges from 0.0 (no intensity) to 1.0 (full intensity).
SI d3d9_color_t d3d9_color_value( f32 r, f32 g, f32 b, f32 a )
{
	return d3d9_color_argb(
		(u08)( a * 255 ),
		(u08)( r * 255 ),
		(u08)( g * 255 ),
		(u08)( b * 255 )  );
}


//! Get string representation of d3d9 surface format
SI const char * d3d9_fmt_string( d3d9_format_t fmt )
{
	switch ( (enum d3d9_fmt_e) fmt )
	{
	default                       : return "UNKNOWN";
	case e_d3d9_fmt_r8g8b8        : return "R8G8B8";
	case e_d3d9_fmt_a8r8g8b8      : return "A8R8G8B8";
	case e_d3d9_fmt_x8r8g8b8      : return "X8R8G8B8";
	case e_d3d9_fmt_r5g6b5        : return "R5G6B5";
	case e_d3d9_fmt_x1r5g5b5      : return "X1R5G5B5";
	case e_d3d9_fmt_a1r5g5b5      : return "A1R5G5B5";
	case e_d3d9_fmt_a4r4g4b4      : return "A4R4G4B4";
	case e_d3d9_fmt_r3g3b2        : return "R3G3B2";
	case e_d3d9_fmt_a8            : return "A8";
	case e_d3d9_fmt_a8r3g3b2      : return "A8R3G3B2";
	case e_d3d9_fmt_x4r4g4b4      : return "X4R4G4B4";
	case e_d3d9_fmt_a2b10g10r10   : return "A2B10G10R10";
	case e_d3d9_fmt_a8b8g8r8      : return "A8B8G8R8";
	case e_d3d9_fmt_x8b8g8r8      : return "X8B8G8R8";
	case e_d3d9_fmt_g16r16        : return "G16R16";
	case e_d3d9_fmt_a2r10g10b10   : return "A2R10G10B10";
	case e_d3d9_fmt_a16b16g16r16  : return "A16B16G16R16";
	case e_d3d9_fmt_a8p8          : return "A8P8";
	case e_d3d9_fmt_p8            : return "P8";
	case e_d3d9_fmt_L8            : return "L8";
	case e_d3d9_fmt_A8L8          : return "A8L8";
	case e_d3d9_fmt_A4L4          : return "A4L4";
	case e_d3d9_fmt_v8u8          : return "V8U8";
	case e_d3d9_fmt_L6V5U5        : return "L6V5U5";
	case e_d3d9_fmt_x8l8v8u8      : return "X8L8V8U8";
	case e_d3d9_fmt_q8w8v8u8      : return "Q8W8V8U8";
	case e_d3d9_fmt_v16u16        : return "V16U16";
	case e_d3d9_fmt_a2w10v10u10   : return "A2W10V10U10";
	case e_d3d9_fmt_uyvy          : return "UYVY";
	case e_d3d9_fmt_r8g8_b8g8     : return "R8G8_B8G8";
	case e_d3d9_fmt_yuy2          : return "YUY2";
	case e_d3d9_fmt_g8r8_g8b8     : return "G8R8_G8B8";
	case e_d3d9_fmt_dxt1          : return "DXT1";
	case e_d3d9_fmt_dxt2          : return "DXT2";
	case e_d3d9_fmt_dxt3          : return "DXT3";
	case e_d3d9_fmt_dxt4          : return "DXT4";
	case e_d3d9_fmt_dxt5          : return "DXT5";
	case e_d3d9_fmt_d16_lockable  : return "D16_LOCKABLE";
	case e_d3d9_fmt_d32           : return "D32";
	case e_d3d9_fmt_d15s1         : return "D15S1";
	case e_d3d9_fmt_d24s8         : return "D24S8";
	case e_d3d9_fmt_d24x8         : return "D24X8";
	case e_d3d9_fmt_d24x4s4       : return "D24X4S4";
	case e_d3d9_fmt_d16           : return "D16";
	case e_d3d9_fmt_L16           : return "L16";
	case e_d3d9_fmt_d32f_lockable : return "D32F_LOCKABLE";
	case e_d3d9_fmt_d24fs8        : return "D24FS8";
	case e_d3d9_fmt_vertexdata    : return "VERTEXDATA";
	case e_d3d9_fmt_index16       : return "INDEX16";
	case e_d3d9_fmt_index32       : return "INDEX32";
	case e_d3d9_fmt_q16w16v16u16  : return "Q16W16V16U16";
	case e_d3d9_fmt_multi2_argb8  : return "MULTI2_ARGB8";
	case e_d3d9_fmt_r16f          : return "R16F";
	case e_d3d9_fmt_g16r16f       : return "G16R16F";
	case e_d3d9_fmt_a16b16g16r16f : return "A16B16G16R16F";
	case e_d3d9_fmt_r32f          : return "R32F";
	case e_d3d9_fmt_g32r32f       : return "G32R32F";
	case e_d3d9_fmt_a32b32g32r32f : return "A32B32G32R32F";
	case e_d3d9_fmt_cxv8u8        : return "CxV8U8";
	}
}

//! Get string representation of a d3d9 hresult_t
SI const char * d3d9_hresult_string( hresult_t hr )
{
	switch ( (int) hr )
	{
	case D3D9_ERR_CONFLICTINGRENDERSTATE:
		return "conflicting render state";
	case D3D9_ERR_CONFLICTINGTEXTUREFILTER:
		return "conflicting texture filter";
	case D3D9_ERR_CONFLICTINGTEXTUREPALETTE:
		return "conflicting texture palette";
	case D3D9_ERR_DEVICEHUNG:
		return "device hung";
	case D3D9_ERR_DEVICELOST:
		return "device lost";
	case D3D9_ERR_DEVICENOTRESET:
		return "device not reset";
	case D3D9_ERR_DEVICEREMOVED:
		return "device removed";
	case D3D9_ERR_DRIVERINTERNALERROR:
		return "driver internal error";
	case D3D9_ERR_DRIVERINVALIDCALL:
		return "driver invalid call";
	case D3D9_ERR_INVALIDCALL:
		return "invalid call";
	case D3D9_ERR_INVALIDDEVICE:
		return "invalid device";
	case D3D9_ERR_MOREDATA:
		return "more data";
	case D3D9_ERR_NOTAVAILABLE:
		return "not available";
	case D3D9_ERR_NOTFOUND:
		return "not found";
	case D3D9_ERR_OUTOFVIDEOMEMORY:
		return "out of video memory";
	case D3D9_ERR_TOOMANYOPERATIONS:
		return "too many operations";
	case D3D9_ERR_UNSUPPORTEDALPHAARG:
		return "unsupported alpha argument";
	case D3D9_ERR_UNSUPPORTEDALPHAOPERATION:
		return "unsupported alpha operation";
	case D3D9_ERR_UNSUPPORTEDCOLORARG:
		return "unsupported color argument";
	case D3D9_ERR_UNSUPPORTEDCOLOROPERATION:
		return "unsupported color operation";
	case D3D9_ERR_UNSUPPORTEDFACTORVALUE:
		return "unsupported factor value";
	case D3D9_ERR_UNSUPPORTEDTEXTUREFILTER:
		return "unsupported texture filter";
	case D3D9_ERR_WASSTILLDRAWING:
		return "was still drawing";
	case D3D9_ERR_WRONGTEXTUREFORMAT:
		return "wrong texture format";
	case D3D9_ERR_UNSUPPORTEDOVERLAY:
		return "unsupported overlay";
	case D3D9_ERR_UNSUPPORTEDOVERLAYFORMAT:
		return "unsupported overlay format";
	case D3D9_ERR_CANNOTPROTECTCONTENT:
		return "cannot protect content";
	case D3D9_ERR_UNSUPPORTEDCRYPTO:
		return "unsupported crypto";
		
	case D3D9_E_FAIL:
		return "fail";
	case D3D9_E_INVALIDARG:
		return "invalid argument";
	case D3D9_E_NOINTERFACE:
		return "no interface";
	case D3D9_E_NOTIMPL:
		return "not implemented";
	case D3D9_E_OUTOFMEMORY:
		return "out of memory";
		
	case D3D9_S_NOT_RESIDENT:
		return "not resident";
	case D3D9_S_RESIDENT_IN_SHARED_MEMORY:
		return "resident in shared memory";
		
	default:
		return "unknown error code ";
	}
}

//! PSVersion creates a pixel shader version token.
#define D3D9_PSVersion( major, minor ) \
	(u32)( 0xFFFF0000 | ((major) << 8) | (minor) )

//! VSVersion creates a vertex shader version token.
#define D3D9_VSVersion( major, minor ) \
	(u32)( 0xFFFE0000 | ((major) << 8) | (minor) )

//! TSWorldMatrix maps indices in the range
//! 0-255 to the corresponding transform states.
#define D3D9_TSWorldMatrix( index ) \
	(d3d9_transformstatetype_t)( index + 256 )


//! FVFTexCoordSize1 constructs bit patterns that are used to identify texture
//! coordinate formats within a FVF description. The results of these macros
//! can be combined within a FVF description by using the OR operator.
#define D3D9_FVFTexCoordSize1( CoordIndex ) \
	(u32)( (int)(D3D9_FVF_TEXTUREFORMAT1) << (CoordIndex*2 + 16) )

//! FVFTexCoordSize2 constructs bit patterns that are used to identify texture
//! coordinate formats within a FVF description. The results of these macros
//! can be combined within a FVF description by using the OR operator.
#define D3D9_FVFTexCoordSize2( CoordIndex ) \
	(u32)( D3D9_FVF_TEXTUREFORMAT2 )

//! FVFTexCoordSize3 constructs bit patterns that are used to identify texture
//! coordinate formats within a FVF description. The results of these macros
//! can be combined within a FVF description by using the OR operator.
#define D3D9_FVFTexCoordSize3( CoordIndex ) \
	(u32)( D3D9_FVF_TEXTUREFORMAT3 << (CoordIndex*2 + 16) )

//! FVFTexCoordSize4 constructs bit patterns that are used to identify texture
//! coordinate formats within a FVF description. The results of these macros
//! can be combined within a FVF description by using the OR operator.
#define D3D9_FVFTexCoordSize4( CoordIndex ) \
	(u32)( D3D9_FVF_TEXTUREFORMAT4 << (CoordIndex*2 + 16) )

#undef SI
#endif /* HEADER_D3D9UTIL_H_ */


