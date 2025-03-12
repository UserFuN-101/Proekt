#pragma once
#include <SFML/Graphics.hpp>
#include "ClickableButton.h"
#include <vector>
#include <string>

class GameScreen {
public:
    GameScreen(sf::Font& font, const std::vector<std::string>& sentences);
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    bool isBackButtonClicked(sf::Vector2f mousePos) const;

private:
    sf::Font& font;
    std::vector<std::string> sentences; // Add this line
    sf::Text sentenceText;
    ClickableButton backButton;
};