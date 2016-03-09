#pragma once

#include <cstdint>

class Event
{
public:
    typedef uint32_t Type;
    Event(const Type& type);
    virtual ~Event() = default;

    const Type& GetType() const;

private:
    const Type type_;
};
