#include <fstream>
#include <sstream>
#include "util.h"
#include "section.h"

using namespace elf;

Section::Section(ifstream& istream, streampos file_offset, Elf64_Xword size)
        : file_offset{file_offset}, size{size} {
    content.reserve(size);
    position_stream(istream, file_offset);
    initialise(istream);
}

Section::~Section() = default;

void Section::initialise(ifstream& istream) {
    for (Elf64_Xword i = 0; i < size; i++) {
        char c;
        istream.read(&c, sizeof(char));

        content.push_back(c);
    }
}

string Section::get_hex_dump() {
    auto sstream = stringstream();
    for (auto& b : content) sstream << "0x" << hex << (int) b << " ";

    return sstream.str();
}

string Section::get_ascii_dump() {
    auto sstream = stringstream();
    for (auto& b : content) {
        if (b == '\0')
            sstream << "|";
        else
            sstream << (char) b;
    }

    return sstream.str();
}