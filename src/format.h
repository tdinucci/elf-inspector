#ifndef ELF_INSPECTOR_FORMAT_H_
#define ELF_INSPECTOR_FORMAT_H_

#include <string>
#include <unordered_map>

using namespace std;

namespace elf {
class Format {
 public:
  static string get_file_type(uint8_t elf_type_id);
  static string get_machine_class(uint8_t machine_class_id);
  static string get_encoding_type(uint8_t encoding_type_id);
  static string get_section_type(uint8_t section_type_id);
};
}  // namespace elf

#endif
