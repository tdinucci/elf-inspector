#include "format.h"

using namespace elf;

static const unordered_map<uint8_t, string> FILE_TYPES{
        make_pair(0, "None"), make_pair(1, "Relocatable"),
        make_pair(2, "Executable"), make_pair(2, "Shared"), make_pair(4, "Core")};

static const unordered_map<uint8_t, string> MACHINE_CLASS{
        make_pair(1, "32 bit"), make_pair(2, "64 bit")};

static const unordered_map<uint8_t, string> ENCODING_TYPES{
        make_pair(1, "Little-endian"), make_pair(2, "Big-endian")};

static const unordered_map<uint8_t, string> SECTION_TYPES{
        make_pair(0, "NULL"), make_pair(1, "PROGBITS"),
        make_pair(2, "SYMTAB"), make_pair(3, "STRTAB"),
        make_pair(4, "RELA"), make_pair(5, "HASH"),
        make_pair(6, "DYNAMIC"), make_pair(7, "NOTE"),
        make_pair(8, "NOBITS"), make_pair(9, "REL"),
        make_pair(10, "SHLIB"), make_pair(11, "DYNSYM"),
        make_pair(14, "INIT_ARRAY"), make_pair(15, "FINI_ARRAY"),
        make_pair(16, "PREINIT_ARRAY"), make_pair(17, "GROUP"),
        make_pair(18, "SYMTAB_SHNDX")};

string Format::get_file_type(uint8_t elf_type_id) {
    if (FILE_TYPES.find(elf_type_id) == FILE_TYPES.end()) return "UNKNOWN";

    return FILE_TYPES.at(elf_type_id);
}

string Format::get_machine_class(uint8_t machine_class_id) {
    if (MACHINE_CLASS.find(machine_class_id) == MACHINE_CLASS.end())
        return "UNKNOWN";

    return MACHINE_CLASS.at(machine_class_id);
}

string Format::get_encoding_type(uint8_t encoding_type_id) {
    if (ENCODING_TYPES.find(encoding_type_id) == ENCODING_TYPES.end())
        return "UNKNOWN";

    return ENCODING_TYPES.at(encoding_type_id);
}

string Format::get_section_type(uint8_t section_type_id) {
    if (SECTION_TYPES.find(section_type_id) == SECTION_TYPES.end())
        return "UNKNOWN";

    return SECTION_TYPES.at(section_type_id);
}