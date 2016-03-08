#pragma once

#include <cstdint>
#include <string>

class Shader
{
public:
    enum Type {
        Vertex,
        Fragment,
        Geometry
    };

    Shader(Type type);
    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void LoadFile(const char* filename);

    void SetText(const char* text);

    bool Compile();

    const std::string& GetCompileErrors() const;

    uint32_t GetGLObject();

private:
    uint32_t shader_;
    std::string text_;
    std::string errors_;
};
