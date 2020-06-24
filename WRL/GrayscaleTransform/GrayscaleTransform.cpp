#include "pch.h"
#include "GrayscaleTransform.h"
#include "BufferLock.h"

using namespace Microsoft::WRL;

//
// * IMPORTANT: If you implement your own MFT, create a new GUID for the CLSID. *
//

// Configuration attributes

// {7BBBB051-133B-41F5-B6AA-5AFF9B33A2CB}
GUID const MFT_GRAYSCALE_DESTINATION_RECT = { 0x7bbbb051, 0x133b, 0x41f5, 0xb6, 0xaa, 0x5a, 0xff, 0x9b, 0x33, 0xa2, 0xcb };

// {14782342-93E8-4565-872C-D9A2973D5CBF}
GUID const MFT_GRAYSCALE_SATURATION = { 0x14782342, 0x93e8, 0x4565, 0x87, 0x2c, 0xd9, 0xa2, 0x97, 0x3d, 0x5c, 0xbf };

// {E0BADE5D-E4B9-4689-9DBA-E2F00D9CED0E}
GUID const MFT_GRAYSCALE_CHROMA_ROTATION = { 0xe0bade5d, 0xe4b9, 0x4689, 0x9d, 0xba, 0xe2, 0xf0, 0xd, 0x9c, 0xed, 0xe };

template<class T>
void SafeRelease(T** ppT)
{
   if (*ppT)
   {
      (*ppT)->Release();
      *ppT = nullptr;
   }
}


