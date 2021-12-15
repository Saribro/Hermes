/**
 * Copyright (c) 2020-2021, Bart Swinnen
 * All rights reserved.
 *
 * BSD 2-Clause License (see included LICENSE file)
 */

#pragma once

#include <stdint.h>

/**
 * GenCP status code
 */
enum gcp_status {
    GCP_SUCCESS             = 0x0000,
    GCP_NOT_IMPLEMENTED     = 0x8001,
    GCP_INVALID_PARAMETER   = 0x8002,
    GCP_INVALID_ADDRESS     = 0x8003,
    GCP_WRITE_PROTECT       = 0x8004,
    GCP_BAD_ALIGNMENT       = 0x8005,
    GCP_ACCESS_DENIED       = 0x8006,
    GCP_BUSY                = 0x8007,
    GCP_MSG_TIMEOUT         = 0x800B,
    GCP_INVALID_HEADER      = 0x800E,
    GCP_WRONG_CONFIG        = 0x800F,
    GCP_ERROR               = 0x8FFF
};

struct gcp_status_type {
    uint16_t StatusCode : 12;
    uint16_t RESERVED : 1;      // set to 0
    uint16_t Namespace : 2;
    uint16_t Severity : 1;
};

/**
 * GenCP command id
 */
enum gcp_command {
    GCP_READMEM_CMD             = 0x0800,
    GCP_READMEM_ACK             = 0x0801,
    GCP_WRITEMEM_CMD            = 0x0802,
    GCP_WRITEMEM_ACK            = 0x0803,
    GCP_PENDING_ACK             = 0x0805,
    GCP_READMEM_STACKED_CMD     = 0x0806,
    GCP_READMEM_STACKED_ACK     = 0x0807,
    GCP_WRITEMEM_STACKED_CMD    = 0x0808,
    GCP_WRITEMEM_STACKED_ACK    = 0x0809,
    GCP_EVENT_CMD               = 0x0C00,
    GCP_EVENT_ACK               = 0x0C01
};

struct gcp_command_type {
    uint16_t AcknowledgeFlag : 1;
    uint16_t CommandValue : 14;
    uint16_t CustomCommandIdentifier : 1;
};

/**
 * GenCP command flag
 */
enum gcp_flags {
    GCP_REQUEST_ACK     = (1 << 14),
    GCP_COMMAND_RESEND  = (1 << 15)
};

struct gcp_flags_type {
    uint16_t RESERVED : 14;     // set to 0
    uint16_t RequestAck : 1;
    uint16_t CommandResend : 1;
};

/**
 * GenCP endianess
 */
enum gcp_endianness {
    GCP_BIG_ENDIAN = 0x00000000,
    GCP_LITTLE_ENDIAN = 0xFFFFFFFF
};
