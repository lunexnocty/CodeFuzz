#include <cstdint>

namespace CodeFuzz {

byte Bytes::get() const {
    auto val = this->data[this->offset];
    this->offset = (this->offset + 1) % this->size;
    return val;
}

float Bytes::rand() const {
    return std::to_integer<std::uint8_t>(this->get()) / 255.0f;
}
}