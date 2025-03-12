#pragma once
#include <SFML/Graphics.hpp>
#include "ClickableButton.h"

class SentenceInputScreen; 

class DifficultySelectionScreen {
public:
    DifficultySelectionScreen(sf::Font& font, sf::Vector2f windowSize);
    void draw(sf::RenderWindow& window);
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    sf::String getSelectedDifficulty() const;
    bool isDifficultySelected() const;
    void resetSelection(SentenceInputScreen* sentenceInputScreen);
    bool isBackButtonClicked(sf::Vector2f mousePos) const;
    void updatePositions(sf::Vector2f windowSize);

private:
    ClickableButton easyButton;
    ClickableButton mediumButton;
    ClickableButton hardButton;
    ClickableButton backButton;
    sf::Font& font;
    sf::String selectedDifficulty;
    bool difficultySelected;
    sf::Vector2f windowSize;

    // Store original button positions and sizes
    sf::Vector2f easyButtonOriginalPosition;
    sf::Vector2f mediumButtonOriginalPosition;
    sf::Vector2f hardButtonOriginalPosition;
    sf::Vector2f backButtonOriginalPosition;
    sf::Vector2f easyButtonOriginalSize;
    sf::Vector2f mediumButtonOriginalSize;
    sf::Vector2f hardButtonOriginalSize;
    sf::Vector2f backButtonOriginalSize;
};