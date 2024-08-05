#include "bytestream.hpp"

namespace CodeFuzz {

std::byte ByteStream::get() const {
    std::byte val = this->data[this->offset];
    this->offset = (this->offset + 1) % this->size;
    return val;
};

float ByteStream::rand() const {
    return std::to_integer<std::uint8_t>(this->get()) / 255.0f;
};
}