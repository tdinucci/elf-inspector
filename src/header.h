#ifndef ELF_INSPECTOR_HEADER_H_
#define ELF_INSPECTOR_HEADER_H_

#include <fstream>
#include <memory>
#include "identity.h"
#include "types.h"

using namespace std;

namespace elf {
class Header {
 private:
  static const uint8_t EXPECTED_MACHINE = 62;
  static const uint8_t EI_NIDENT = 16;

  byte e_ident[EI_NIDENT];

  unique_ptr<Identity> id;
  Elf64_Half type;
  Elf64_Half machine;
  Elf64_Word version;
  Elf64_Addr entry_addr;
  Elf64_Off ph_offset;
  Elf64_Off sh_offset;
  Elf64_Word flags;
  Elf64_Half elf_header_size;
  Elf64_Half ph_entry_size;
  Elf64_Half ph_count;
  Elf64_Half sh_entry_size;
  Elf64_Half sh_count;
  Elf64_Half sh_strings_idx;

 public:
  Header(ifstream& istream);

  bool is_valid();

  Identity* get_id();
  Elf64_Half get_type();
  Elf64_Half get_machine();
  Elf64_Word get_version();
  Elf64_Addr get_entry_addr();
  Elf64_Off get_ph_offset();
  Elf64_Off get_sh_offset();
  Elf64_Word get_flags();
  Elf64_Half get_elf_header_size();
  Elf64_Half get_ph_entry_size();
  Elf64_Half get_ph_count();
  Elf64_Half get_sh_entry_size();
  Elf64_Half get_sh_count();
  Elf64_Half get_sh_strings_idx();
};
}  // namespace elf

#endif
