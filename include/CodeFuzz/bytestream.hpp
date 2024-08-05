#pragma once

#include <cstddef>
#include <vector>

namespace CodeFuzz {
class ByteStream {

public:
    ByteStream() = default;
    ByteStream(const ByteStream &) = default;
    ByteStream(ByteStream &&) = default;
    ByteStream &operator=(const ByteStream &) = default;
    ByteStream &operator=(ByteStream &&) = default;
    ~ByteStream() = default;

public:
    float rand() const;

private:
    std::byte get() const;
    std::vector<std::byte> data;
    mutable size_t offset;
    size_t size;
};
}