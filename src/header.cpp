#include <memory>
#include "header.h"
#include "identity.h"
#include "util.h"

using namespace elf;

Header::Header(ifstream& istream) {
    id = make_unique<Identity>(istream);

    if (!id->is_valid()) {
        throw runtime_error(
                "The provided file is not valid, expected a 64 bit ELF with "
                "little-endian encoding");
    }

    position_stream(istream, EI_NIDENT);
    istream.read((char*) &type, sizeof(Elf64_Half));
    istream.read((char*) &machine, sizeof(Elf64_Half));
    istream.read((char*) &version, sizeof(Elf64_Word));
    istream.read((char*) &entry_addr, sizeof(Elf64_Addr));
    istream.read((char*) &ph_offset, sizeof(Elf64_Off));
    istream.read((char*) &sh_offset, sizeof(Elf64_Off));
    istream.read((char*) &flags, sizeof(Elf64_Word));
    istream.read((char*) &elf_header_size, sizeof(Elf64_Half));
    istream.read((char*) &ph_entry_size, sizeof(Elf64_Half));
    istream.read((char*) &ph_count, sizeof(Elf64_Half));
    istream.read((char*) &sh_entry_size, sizeof(Elf64_Half));
    istream.read((char*) &sh_count, sizeof(Elf64_Half));
    istream.read((char*) &sh_strings_idx, sizeof(Elf64_Half));
}

bool Header::is_valid() {
    return id->is_valid() && machine == EXPECTED_MACHINE;
}

Identity* Header::get_id() { return id.get(); }

Elf64_Half Header::get_type() { return type; }

Elf64_Half Header::get_machine() { return machine; }

Elf64_Word Header::get_version() { return version; }

Elf64_Addr Header::get_entry_addr() { return entry_addr; }

Elf64_Off Header::get_ph_offset() { return ph_offset; }

Elf64_Off Header::get_sh_offset() { return sh_offset; }

Elf64_Word Header::get_flags() { return flags; }

Elf64_Half Header::get_elf_header_size() { return elf_header_size; }

Elf64_Half Header::get_ph_entry_size() { return ph_entry_size; }

Elf64_Half Header::get_ph_count() { return ph_count; }

Elf64_Half Header::get_sh_entry_size() { return sh_entry_size; }

Elf64_Half Header::get_sh_count() { return sh_count; }

Elf64_Half Header::get_sh_strings_idx() { return sh_strings_idx; }