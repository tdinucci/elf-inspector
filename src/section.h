#ifndef ELF_INSPECTOR_SECTION_H_
#define ELF_INSPECTOR_SECTION_H_

#include <fstream>
#include <vector>
#include "types.h"

using namespace std;

namespace elf {
class Section {
 protected:
  streampos file_offset;
  Elf64_Xword size;
  vector<byte> content;

  void initialise(ifstream& istream);

 public:
  Section() = delete;
  Section(ifstream& istream, streampos file_offset, Elf64_Xword size);
  virtual ~Section();

  string get_hex_dump();
  string get_ascii_dump();
};
}  // namespace elf

#endif
