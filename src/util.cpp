#include "util.h"

namespace elf {

    void position_stream(istream& stream, streampos pos) {
        if (stream.good()) {
            if (stream.tellg() != pos) {
                stream.seekg(pos);
            }
        }

        if (!stream.good() || stream.tellg() != pos)
            throw runtime_error("The stream is not in a usable state");
    }
} 