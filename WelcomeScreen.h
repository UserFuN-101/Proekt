#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "ClickableButton.h"

class WelcomeScreen {
public:
    WelcomeScreen(sf::Font& font);
    void draw(sf::RenderWindow& window);
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    sf::String getSelectedDifficulty() const;
    bool isDifficultySelected() const;

private:
    ClickableButton easyButton;
    ClickableButton mediumButton;
    ClickableButton hardButton;
    sf::Font& font;
    sf::String selectedDifficulty;
    bool difficultySelected;
};