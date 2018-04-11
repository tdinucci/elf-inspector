#ifndef ELF_INSPECTOR_STRINGS_SECTION_H_
#define ELF_INSPECTOR_STRINGS_SECTION_H_

#include <fstream>
#include <unordered_map>
#include "section.h"

using namespace std;

namespace elf {
class StringsSection : public Section {
 private:
  unordered_map<uint16_t, string> strings;
  void extract_strings();

 public:
  StringsSection(ifstream& istream, streampos file_offset, Elf64_Xword size);

  string get_string(uint16_t offset) const;
};
}  // namespace elf

#endif
