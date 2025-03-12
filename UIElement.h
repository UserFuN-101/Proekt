#pragma once
#include <SFML/Graphics.hpp>

class UIElement {
public:
    UIElement();
    virtual ~UIElement() = default;

    virtual void setPosition(const sf::Vector2f& position);
    virtual void setSize(const sf::Vector2f& size);
    virtual void draw(sf::RenderWindow& window) = 0;

    virtual void setScale(const sf::Vector2f& scale);
    virtual sf::Vector2f getScale() const;

protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f scaleFactor; // Добавлено
    sf::Transform transform;
};