#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>

class TextureManager {
public:
    TextureManager() = default;
    bool loadTexture(const std::string& name, const std::string& filename);
    const sf::Texture& getTexture(const std::string& name) const;
    bool hasTexture(const std::string& name) const;
private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
};