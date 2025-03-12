#include "ClickableButton.h"

ClickableButton::ClickableButton(const sf::Vector2f& position, const sf::Vector2f& size, sf::Font& font, unsigned int characterSize, const sf::String& text) :
    UIElement(), font(font), characterSize(characterSize)
{
    this->position = position;
    this->size = size;
    this->scaleFactor = { 1, 1 };

    button.setPosition(position);
    button.setSize(size);
    button.setFillColor(sf::Color::Blue);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(characterSize);
    this->text.setFillColor(sf::Color::Black);

    // Center the text
    sf::FloatRect textRect = this->text.getLocalBounds();
    this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    this->text.setPosition(this->position.x + this->size.x / 2.0f, this->position.y + this->size.y / 2.0f);

    transform.translate(position - this->position);
}

void ClickableButton::draw(sf::RenderWindow& window) {
    window.draw(button, transform);
    window.draw(text, transform);
}

bool ClickableButton::isClicked(const sf::Vector2f& mousePosition) const {
    sf::FloatRect bounds = button.getGlobalBounds();
    return bounds.contains(mousePosition);
}

void ClickableButton::setCharacterSize(unsigned int size) {
    characterSize = size;
    text.setCharacterSize(characterSize);
    // Center the text
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    this->text.setPosition(this->position.x + this->size.x / 2.0f, this->position.y + this->size.y / 2.0f);
}

unsigned int ClickableButton::getCharacterSize() const {
    return characterSize;
}