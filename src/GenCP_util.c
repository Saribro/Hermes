/**
 * Copyright (c) 2020, Bart Swinnen
 * All rights reserved.
 *
 * BSD 2-Clause License (see included LICENSE file)
 */

#include "GenCP_util.h"

uint16_t crc16(uint16_t * buffer, uint32_t buffer_size_bytes, gcp_endianness_e endianness)
{
    uint64_t crc = 0;
    for (uint32_t i = 0; i < (buffer_size_bytes / 2); ++i)
        crc += buffer[i];

    while (crc > 0xFFFF)
        crc = (crc & 0xFFFF) + (crc >> 16);

    if (GCP_BIG_ENDIAN == endianness)
        crc = ((crc & 0xFF) << 8) + (crc >> 8);

    if (crc == 0xFFFF)
        crc = 0;

    return (uint16_t) crc;
}
