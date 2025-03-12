#include "DifficultySelectionScreen.h"
#include "GraphicsUtils.h"
#include <iostream>
#include "SentenceInputScreen.h" //Add this line

DifficultySelectionScreen::DifficultySelectionScreen(sf::Font& font, sf::Vector2f windowSize) :
    font(font),
    difficultySelected(false),
    windowSize(windowSize),
    easyButton({ windowSize.x * 0.125f, windowSize.y * 0.166f }, { windowSize.x * 0.125f, windowSize.y * 0.05f }, font, 20, sf::String(L"Легко")),
    mediumButton({ windowSize.x * 0.125f, windowSize.y * 0.25f }, { windowSize.x * 0.125f, windowSize.y * 0.05f }, font, 20, sf::String(L"Средне")),
    hardButton({ windowSize.x * 0.125f, windowSize.y * 0.333f }, { windowSize.x * 0.125f, windowSize.y * 0.05f }, font, 20, sf::String(L"Сложно")),
    backButton({ windowSize.x * 0.75f, windowSize.y * 0.083f }, { windowSize.x * 0.125f, windowSize.y * 0.05f }, font, 20, sf::String(L"Назад")),
    easyButtonOriginalPosition(windowSize.x * 0.125f, windowSize.y * 0.166f),
    mediumButtonOriginalPosition(windowSize.x * 0.125f, windowSize.y * 0.25f),
    hardButtonOriginalPosition(windowSize.x * 0.125f, windowSize.y * 0.333f),
    backButtonOriginalPosition(windowSize.x * 0.75f, windowSize.y * 0.083f),
    easyButtonOriginalSize(windowSize.x * 0.125f, windowSize.y * 0.05f),
    mediumButtonOriginalSize(windowSize.x * 0.125f, windowSize.y * 0.05f),
    hardButtonOriginalSize(windowSize.x * 0.125f, windowSize.y * 0.05f),
    backButtonOriginalSize(windowSize.x * 0.125f, windowSize.y * 0.05f)
{
}

void DifficultySelectionScreen::draw(sf::RenderWindow& window) {
    drawText(window, L"Выбор сложности:", font, { 100, 50 }, 24, sf::Color::Black);
    easyButton.draw(window);
    mediumButton.draw(window);
    hardButton.draw(window);

    if (difficultySelected) {
        backButton.draw(window);
    }
}

void DifficultySelectionScreen::handleInput(sf::Event& event, sf::RenderWindow& window) {
    sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (easyButton.isClicked(mousePos)) {
            selectedDifficulty = sf::String(L"Легко");
            difficultySelected = true;
            std::cout << "Выбрана лёгкая сложность:" << std::endl;
        }
        else if (mediumButton.isClicked(mousePos)) {
            selectedDifficulty = sf::String(L"Средне");
            difficultySelected = true;
            std::cout << "Выбрана средняя сложнсть:" << std::endl;
        }
        else if (hardButton.isClicked(mousePos)) {
            selectedDifficulty = sf::String(L"Сложно");
            difficultySelected = true;
            std::cout << "Выбрана высокая сложность:" << std::endl;
        }
    }
}

bool DifficultySelectionScreen::isBackButtonClicked(sf::Vector2f mousePos) const {
    return difficultySelected && backButton.isClicked(mousePos);
}

void DifficultySelectionScreen::resetSelection(SentenceInputScreen* sentenceInputScreen) {
    difficultySelected = false;
    selectedDifficulty = L"";
    if (sentenceInputScreen)
        sentenceInputScreen->clearSentences(); //Clear the sentences
}

void DifficultySelectionScreen::updatePositions(sf::Vector2f windowSize) {
    // Calculate scale factors based on the original window size
    float scaleX = windowSize.x / this->windowSize.x;
    float scaleY = windowSize.y / this->windowSize.y;

    // Calculate new positions and sizes
    sf::Vector2f newEasyPosition = { easyButtonOriginalPosition.x * scaleX, easyButtonOriginalPosition.y * scaleY };
    sf::Vector2f newMediumPosition = { mediumButtonOriginalPosition.x * scaleX, mediumButtonOriginalPosition.y * scaleY };
    sf::Vector2f newHardPosition = { hardButtonOriginalPosition.x * scaleX, hardButtonOriginalPosition.y * scaleY };
    sf::Vector2f newBackPosition = { backButtonOriginalPosition.x * scaleX, backButtonOriginalPosition.y * scaleY };

    sf::Vector2f newEasySize = { easyButtonOriginalSize.x * scaleX, easyButtonOriginalSize.y * scaleY };
    sf::Vector2f newMediumSize = { mediumButtonOriginalSize.x * scaleX, mediumButtonOriginalSize.y * scaleY };
    sf::Vector2f newHardSize = { hardButtonOriginalSize.x * scaleX, hardButtonOriginalSize.y * scaleY };
    sf::Vector2f newBackSize = { backButtonOriginalSize.x * scaleX, backButtonOriginalSize.y * scaleY };

    // Set new positions and sizes to the buttons
    easyButton.setPosition(newEasyPosition);
    easyButton.setSize(newEasySize);

    mediumButton.setPosition(newMediumPosition);
    mediumButton.setSize(newMediumSize);

    hardButton.setPosition(newHardPosition);
    hardButton.setSize(newHardSize);

    backButton.setPosition(newBackPosition);
    backButton.setSize(newBackSize);
}