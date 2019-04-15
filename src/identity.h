#ifndef ELF_INSPECTOR_ID_H_
#define ELF_INSPECTOR_ID_H_

#include <fstream>
#include "types.h"

using namespace std;

namespace elf {
    class Identity {
    private:
        static const byte VALID_MAG0 = 0x7f;
        static const byte VALID_MAG1 = 'E';
        static const byte VALID_MAG2 = 'L';
        static const byte VALID_MAG3 = 'F';

        byte magic0{};
        byte magic1{};
        byte magic2{};
        byte magic3{};
        byte machine_class{};
        byte data_encoding{};
        byte version{};
        byte os_abi{};

    public:
        explicit Identity(ifstream& istream);

        bool is_valid();
        byte get_machine_class();
        byte get_data_encoding();
    };
}  // namespace elf

#endif
