/**
 * Copyright (c) 2020, Bart Swinnen
 * All rights reserved.
 *
 * BSD 2-Clause License (see included LICENSE file)
 */

#pragma once

#include <stdint.h>

#include "GenCP_def.h"

uint16_t crc16(uint16_t * buffer, uint32_t buffer_size_bytes, gcp_endianness_e endianness);
