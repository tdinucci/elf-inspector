#ifndef ELF_INSPECTOR_TYPES_H_
#define ELF_INSPECTOR_TYPES_H_

#include <cstdint>

namespace elf {
    typedef unsigned char byte;

    typedef uint64_t Elf64_Addr;
    typedef uint16_t Elf64_Half;
    typedef int16_t Elf64_SHalf;
    typedef uint64_t Elf64_Off;
    typedef int32_t Elf64_Sword;
    typedef uint32_t Elf64_Word;
    typedef uint64_t Elf64_Xword;
    typedef int64_t Elf64_Sxword;
}  // namespace elf
#endif
