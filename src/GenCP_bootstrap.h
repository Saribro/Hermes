#pragma once

#include <stdint.h>

#pragma pack(push, 1)

struct gcp_bootstrap {
    uint32_t gencp_version;                 // [M]  (R)     0x0000
    uint8_t manufacturer_name[64];          // [M]  (R)     0x0004
    uint8_t model_name[64];                 // [M]  (R)     0x0044
    //uint8_t family_name[64];                // [CM] (R)     0x0084
    uint8_t device_version[64];             // [M]  (R)     0x00C4
    uint8_t manufacturer_info[64];          // [M]  (R)     0x0104
    uint8_t serial_number[64];              // [M]  (R)     0x0144
    //uint8_t user_defined_name[64];          // [CM] (RW)    0x0184
    uint64_t device_capability;             // [M]  (R)     0x01C4
    uint32_t maximum_device_response_time;  // [M]  (R)     0x01CC
    uint64_t manifest_table_address;        // [M]  (R)     0x01D0
    //uint64_t sbrm_address;                  // [CM] (R)     0x01D8
    uint64_t device_configuration;          // [M]  (RW)    0x01E0
    //uint32_t heartbeat_timeout;             // [CM] (RW)    0x01E8
    //uint32_t message_channel_id;            // [CM] (RW)    0x01EC
    //uint64_t timestamp;                     // [CM] (R)     0x01F0
    //uint32_t timestamp_latch;               // [CM] (W)     0x01F8
    //uint64_t timestamp_increment;           // [CM] (R)     0x01FC
    //uint32_t access_privilege;              // [CM] (RW)    0x0204
  //uint32_t protocol_endianess             // deprecated   0x0208
    //uint32_t implementation_endianess;      // [CM] (R)     0x020C
    //uint8_t device_software_version[64];    // [CM] (R)     0x0210
  //uint8_t reserved[64944];                // [M]  (/)     0x0250
};

struct gcp_manifest_entry {
    uint32_t genicam_file_version_sub_minor : 16;
    uint32_t genicam_file_version_minor : 8;
    uint32_t genicam_file_version_major : 8;

    uint32_t file_type : 3;
    uint32_t RESERVED0 : 7;
    uint32_t file_format : 6;
    uint32_t schema_version_minor : 8;
    uint32_t schema_version_major : 8;

    uint64_t register_address;
    uint64_t file_size;
    uint8_t sha1_hash[20];
    uint8_t RESERVED1[20];
};

struct gcp_manifest_table {
    uint64_t mt_entry_count;
    gcp_manifest_entry manifest_entry[];
};

#pragma pack(pop)
