#include <fstream>
#include <iostream>
#include "file.h"
#include "format.h"

using namespace std;
using namespace elf;

int main() {
  const string path = "sample/hello";
  auto elf_file = unique_ptr<File>(new File(path));

  auto header = elf_file->get_header();
  auto id = header->get_id();
  cout << "File: " << path.c_str() << endl;
  cout << "File Type: " << Format::get_file_type(header->get_type()) << endl;

  cout << "Machine Class: "
       << Format::get_machine_class(id->get_machine_class()) << endl;

  cout << "Data Encoding: "
       << Format::get_encoding_type(id->get_data_encoding()) << endl;

  cout << endl << "=== Sections ===" << endl << endl;

  for (int i = 0; i < elf_file->get_section_count(); i++) {
    auto header = elf_file->get_section_header(i);
    auto section = elf_file->get_section(i);
    auto name = elf_file->get_section_name(*header);
    auto type = Format::get_section_type(header->get_type());

    cout << name.c_str() << " [" << type << "]" << endl;

    cout << "Hex:" << endl
         << "[" << section->get_hex_dump().c_str() << "]" << endl;

    cout << "ASCII:" << endl
         << "[" << section->get_ascii_dump().c_str() << "]" << endl
         << endl;
  }
}