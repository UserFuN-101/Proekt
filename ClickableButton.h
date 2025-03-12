#pragma once
#include <SFML/Graphics.hpp>
#include "UIElement.h"

class ClickableButton : public UIElement {
public:
    ClickableButton(const sf::Vector2f& position, const sf::Vector2f& size, sf::Font& font, unsigned int characterSize, const sf::String& text);
    void draw(sf::RenderWindow& window) override;
    bool isClicked(const sf::Vector2f& mousePosition) const;

    void setCharacterSize(unsigned int size);
    unsigned int getCharacterSize() const;

private:
    sf::RectangleShape button;
    sf::Text text;
    sf::Font& font;
    unsigned int characterSize;
};