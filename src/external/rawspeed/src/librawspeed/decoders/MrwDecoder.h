/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2014 Pedro Côrte-Real

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once

#include "common/Common.h"       // for uint32
#include "common/RawImage.h"     // for RawImage
#include "decoders/RawDecoder.h" // for RawDecoder
#include "tiff/TiffIFD.h"        // for TiffRootIFDOwner

namespace rawspeed {

class CameraMetaData;
class Buffer;

class MrwDecoder final : public RawDecoder {
  TiffRootIFDOwner rootIFD;

  uint32 raw_width;
  uint32 raw_height;
  uint32 data_offset;
  uint32 packed;
  float wb_coeffs[4];

public:
  explicit MrwDecoder(Buffer* file);
  RawImage decodeRawInternal() override;
  void checkSupportInternal(const CameraMetaData* meta) override;
  void decodeMetaDataInternal(const CameraMetaData* meta) override;
  static int isMRW(const Buffer* input);

protected:
  int getDecoderVersion() const override { return 0; }
  void parseHeader();
};

} // namespace rawspeed
