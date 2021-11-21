/** @file
  UEFI ACPI Data Table Definition.

Copyright (c) 2011 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __UEFI_ACPI_DATA_TABLE_H__
#define __UEFI_ACPI_DATA_TABLE_H__

#pragma pack(1)
///
/// The common ACPI description table header.  This structure prefaces most ACPI tables.
///
typedef struct {
  UINT32  Signature;
  UINT32  Length;
  UINT8   Revision;
  UINT8   Checksum;
  UINT8   OemId[6];
  UINT64  OemTableId;
  UINT32  OemRevision;
  UINT32  CreatorId;
  UINT32  CreatorRevision;
} EFI_ACPI_DESCRIPTION_HEADER;
#pragma pack()

#pragma pack(1)
typedef struct {
  EFI_ACPI_DESCRIPTION_HEADER   Header;
  GUID                          Identifier;
  UINT16                        DataOffset;
} EFI_ACPI_DATA_TABLE;
#pragma pack()

#endif

