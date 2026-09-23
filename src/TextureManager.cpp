#include <TextureManager.hpp>
#include <iostream>
#include <stdexcept>

bool TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    if (hasTexture(name)) {
        return true; 
    }

    auto texture = std::make_unique<sf::Texture>();
    if (!texture->loadFromFile(filename)) {
        std::cerr << "Failed to load texture file: " << filename << std::endl;
        return false;
    }

    textures[name] = std::move(texture);
    return true;
}

const sf::Texture& TextureManager::getTexture(const std::string& name) const {
    auto finder = textures.find(name);
    if (finder == textures.end()) {
        throw std::runtime_error("TextureManager: Texture not found - " + name);
    }
    return *finder->second;
}

bool TextureManager::hasTexture(const std::string& name) const {
    return textures.find(name) != textures.end();
}