#include "section-header.h"
#include "util.h"

using namespace elf;

SectionHeader::SectionHeader(ifstream& istream, streampos start_pos) {
  position_stream(istream, start_pos);

  istream.read((char*)&name, sizeof(Elf64_Word));
  istream.read((char*)&type, sizeof(Elf64_Word));
  istream.read((char*)&flags, sizeof(Elf64_Xword));
  istream.read((char*)&runtime_addr, sizeof(Elf64_Addr));
  istream.read((char*)&section_offset, sizeof(Elf64_Off));
  istream.read((char*)&size, sizeof(Elf64_Xword));
  istream.read((char*)&link, sizeof(Elf64_Word));
  istream.read((char*)&info, sizeof(Elf64_Word));
  istream.read((char*)&addr_align, sizeof(Elf64_Xword));
  istream.read((char*)&entry_size, sizeof(Elf64_Xword));
}

Elf64_Word SectionHeader::get_name() const { return name; }

Elf64_Word SectionHeader::get_type() const { return type; }

Elf64_Xword SectionHeader::get_flags() const { return flags; }

Elf64_Addr SectionHeader::get_runtime_addr() const { return runtime_addr; }

Elf64_Off SectionHeader::get_section_offset() const { return section_offset; }

Elf64_Xword SectionHeader::get_size() const { return size; }

Elf64_Word SectionHeader::get_link() const { return link; }

Elf64_Word SectionHeader::get_info() const { return info; }

Elf64_Xword SectionHeader::get_addr_align() const { return addr_align; }

Elf64_Xword SectionHeader::get_entry_size() const { return entry_size; }