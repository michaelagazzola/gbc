#ifndef GBC_TYPE_H
#define GBC_TYPE_H

#include <cstdint>

namespace gbc {

typedef unsigned char bit_t;
typedef unsigned int cycles_t;
typedef std::uint8_t byte_t;
typedef std::uint16_t word_t;

class Debuggable {
  friend class Debug;
};

} // namespace gbc

#endif
