#ifndef ELF_INSPECTOR_UTIL_H_
#define ELF_INSPECTOR_UTIL_H_

#include <fstream>

using namespace std;

namespace elf {
void position_stream(istream& stream, streampos pos);
}

#endif
