#include "strings-section.h"
#include <string>
#include "util.h"

using namespace elf;

StringsSection::StringsSection(ifstream& istream, streampos file_offset,
                               Elf64_Xword size)
    : Section(istream, file_offset, size) {
  extract_strings();
}

void StringsSection::extract_strings() {
  if (strings.size() > 0 || content.size() == 0) return;

  if (content[0] != '\0') {
    throw runtime_error(
        "Expected first entry in string section to be a null character");
  }

  string working = "";
  auto string_offset = 1;
  for (size_t i = 1; i < content.size(); ++i) {
    char c = content[i];
    if (c == '\0') {
      strings.insert(make_pair(string_offset, working));

      working = "";
      string_offset = i + 1;  // +1 to cover the null char
    } else
      working.push_back(c);
  }
}

string StringsSection::get_string(uint16_t offset) const {
  if (strings.find(offset) == strings.end())
    throw runtime_error("No string at given offset");

  return strings.at(offset);
}