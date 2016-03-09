#pragma once

#include <cstdint>

class VBO
{
public:
    enum BindMode {
        ArrayBuffer,
        ElementArrayBuffer
    };

    enum UsageType {
        StaticDraw,
        StaticRead,
        DynamicDraw,
        DynamicRead,
        StreamDraw,
        StreamRead,
    };


    VBO(BindMode mode);
    ~VBO();

    VBO(const VBO&) = delete;
    const VBO& operator=(const VBO&) = delete;

    void SetData(void* data, uint32_t dataSize, UsageType usage = DynamicDraw);
    void SetDataOffset(int offset, void* data, uint32_t dataSize);

    enum MappingType {
        ReadOnly,
        WriteOnly,
        ReadWrite
    };

    void* MapBuffer(MappingType type);
    void  UnmapBuffer();


    void Bind();
    void Unbind();


private:
    BindMode mode_;
    uint32_t vbo_;

    int32_t _bindToGL(BindMode mode);
    int32_t _usageToGL(UsageType type);
    int32_t _mappingToGL(MappingType type);
};
