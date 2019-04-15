#include "identity.h"
#include "util.h"

using namespace elf;

Identity::Identity(ifstream& istream) {
    position_stream(istream, 0);

    istream.read((char*) &magic0, 1);
    istream.read((char*) &magic1, 1);
    istream.read((char*) &magic2, 1);
    istream.read((char*) &magic3, 1);
    istream.read((char*) &machine_class, 1);
    istream.read((char*) &data_encoding, 1);
    istream.read((char*) &version, 1);
    istream.read((char*) &os_abi, 1);
}

bool Identity::is_valid() {
    return magic0 == VALID_MAG0 && magic1 == VALID_MAG1 && magic2 == VALID_MAG2 &&
           magic3 == VALID_MAG3;
}

byte Identity::get_machine_class() { return machine_class; }

byte Identity::get_data_encoding() { return data_encoding; }