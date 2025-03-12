#include "UIElement.h"

UIElement::UIElement() : position(0, 0), size(0, 0), scaleFactor(1, 1) {}

void UIElement::setPosition(const sf::Vector2f& position) {
    this->position = position;
    transform.translate(position - this->position);
}

void UIElement::setSize(const sf::Vector2f& size) {
    this->size = size;
}

void UIElement::setScale(const sf::Vector2f& scale) {
    this->scaleFactor = scale;
    transform.scale(scale); // Changed setScale to scale
}

sf::Vector2f UIElement::getScale() const {
    return scaleFactor;
}