#include "file.h"
#include "header.h"

using namespace elf;

File::File(string filename) {
  auto istream = ifstream(filename, ios::in | ios::binary);

  header = unique_ptr<Header>(new Header(istream));

  auto sh_count = header->get_sh_count();
  if (sh_count > 0) {
    auto sh_pos = header->get_sh_offset();
    auto sh_size = header->get_sh_entry_size();
    for (int i = 0; i < sh_count; i++) {
      auto header =
          unique_ptr<SectionHeader>(new SectionHeader(istream, sh_pos));
      section_headers.push_back(move(header));

      sh_pos += sh_size;
    }

    // doing 2nd loop because it should be more efficient that making the
    // ifstream jump around if we were to do all this within the loop above
    for (size_t i = 0; i < section_headers.size(); i++) {
      auto sh = section_headers[i].get();

      unique_ptr<Section> section;
      if (sh->get_type() == 3) {
        section = unique_ptr<StringsSection>(new StringsSection(
            istream, sh->get_section_offset(), sh->get_size()));
        if (i == header->get_sh_strings_idx()) {
          auto str_sec = (StringsSection*)section.get();
          initialise_section_names(*str_sec);
        }
      } else
        section = unique_ptr<Section>(
            new Section(istream, sh->get_section_offset(), sh->get_size()));

      sections.push_back(move(section));
    }
  }

  istream.close();
}

Header* File::get_header() { return header.get(); }

uint16_t File::get_section_count() { return sections.size(); }

SectionHeader* File::get_section_header(uint16_t index) {
  if (index >= section_headers.size())
    throw runtime_error("Request out of bounds");

  return section_headers[index].get();
}

Section* File::get_section(uint16_t index) {
  if (index >= sections.size()) throw runtime_error("Request out of bounds");

  return sections[index].get();
}

string File::get_section_name(const SectionHeader& section_header) {
  auto name_offset = section_header.get_name();
  if (name_offset == 0) return "NULL";

  if (section_names.find(name_offset) == section_names.end())
    throw runtime_error("No section names with the given offset");

  return section_names[name_offset];
}

void File::initialise_section_names(const StringsSection& sh_strings_section) {
  for (auto& sh : section_headers) {
    auto name_offset = sh->get_name();
    if (name_offset > 0) {
      auto name = sh_strings_section.get_string(name_offset);
      section_names.insert(make_pair(name_offset, name));
    }
  }
}
