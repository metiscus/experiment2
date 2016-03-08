#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

class Shader;
class Uniform;

class Program
{
public:
    Program();
    ~Program();

    void AddShader( std::shared_ptr<Shader> ptr );
    void AddUniform( std::shared_ptr<Uniform> ptr );

    bool Link();
    void Use();

    const std::string GetLinkErrors() const;

    uint32_t GetProgram();

protected:
    Program(const Program&) = delete;
    Program& operator=(const Program&) = delete;
    
private:
    uint32_t program_;
    std::string errors_;
    std::vector< std::shared_ptr<Shader> > shaders_;
    std::vector< std::shared_ptr<Uniform> > uniforms_;
};
