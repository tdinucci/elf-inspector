#ifndef ELF_INSPECTOR_FILE_H_
#define ELF_INSPECTOR_FILE_H_

#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>
#include "header.h"
#include "section-header.h"
#include "section.h"
#include "strings-section.h"

using namespace std;

namespace elf {
class File {
 private:
  unique_ptr<Header> header;
  vector<unique_ptr<SectionHeader>> section_headers;
  vector<unique_ptr<Section>> sections;
  unordered_map<uint16_t, string> section_names;

  void initialise_section_names(const StringsSection& sh_strings_section);

 public:
  explicit File(string filename);

  Header* get_header();
  uint16_t get_section_count();
  SectionHeader* get_section_header(uint16_t index);
  Section* get_section(uint16_t index);
  string get_section_name(const SectionHeader& section_header);
};
}  // namespace elf
#endif