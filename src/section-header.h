#ifndef ELF_INSPECTOR_SECTION_HEADER_H_
#define ELF_INSPECTOR_SECTION_HEADER_H_

#include <fstream>
#include "types.h"

using namespace std;

namespace elf {
    class SectionHeader {
    private:
        Elf64_Word name{};
        Elf64_Word type{};
        Elf64_Xword flags{};
        Elf64_Addr runtime_addr{};
        Elf64_Off section_offset{};
        Elf64_Xword size{};
        Elf64_Word link{};
        Elf64_Word info{};
        Elf64_Xword addr_align{};
        Elf64_Xword entry_size{};

    public:
        SectionHeader(ifstream& istream, streampos start_pos);

        Elf64_Word get_name() const;
        Elf64_Word get_type() const;
        Elf64_Xword get_flags() const;
        Elf64_Addr get_runtime_addr() const;
        Elf64_Off get_section_offset() const;
        Elf64_Xword get_size() const;
        Elf64_Word get_link() const;
        Elf64_Word get_info() const;
        Elf64_Xword get_addr_align() const;
        Elf64_Xword get_entry_size() const;
    };
}  // namespace elf

#endif
