/**
 * Copyright (c) 2020-2021, Bart Swinnen
 * All rights reserved.
 *
 * BSD 2-Clause License (see included LICENSE file)
 */

#pragma once

#include <stdint.h>
#include <stddef.h>

#include "GenCP_def.h"

uint16_t crc16(const uint16_t * buffer, size_t buffer_size_bytes, enum gcp_endianness endianness);
