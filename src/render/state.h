#pragma once

#include <cstdint>
#include <map>
#include <memory>

class Texture;
class Program;

class State
{
public:
    State();
    ~State() = default;
    State(const State&) = default;
    State& operator=(const State&) = default;

    bool operator==(const State& rhs) const;

    void SetTexture(uint32_t unit, std::shared_ptr<Texture> texture);
    void SetProgram(std::shared_ptr<Program> program);
    void EnableBlending();
    void DisableBlending();
    void EnableTexturing();
    void DisableTexturing();
    void EnableTextureUnit(uint32_t unit);
    void DisableTextureUnit(uint32_t unit);

private:
    bool texture_enabled_;
    bool blend_enabled_;
    std::map<uint32_t, bool> units_;
    std::map<uint32_t, std::shared_ptr<Texture> > textures_;
    std::shared_ptr<Program> program_;
};
