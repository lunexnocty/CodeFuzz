#include <vector>

namespace CodeFuzz {
class Bytes {

public:
    Bytes() = default;
    Bytes(const Bytes &) = default;
    Bytes(Bytes &&) = default;
    Bytes &operator=(const Bytes &) = default;
    Bytes &operator=(Bytes &&) = default;
    ~Bytes() = default;

public:
    float rand() const;

private:
    byte get() const;
    std::vector<byte> data;
    mutable size_t offset;
    size_t size;
}
}