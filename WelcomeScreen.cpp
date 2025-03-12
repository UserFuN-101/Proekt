#include "WelcomeScreen.h"
#include "GraphicsUtils.h"
#include <iostream>

WelcomeScreen::WelcomeScreen(sf::Font& font) :
    easyButton({ 100, 100 }, { 100, 30 }, font, 20, sf::String(L"Легко")), // L
    mediumButton({ 100, 150 }, { 100, 30 }, font, 20, sf::String(L"Средне")), // L
    hardButton({ 100, 200 }, { 100, 30 }, font, 20, sf::String(L"Сложно")), // L
    font(font), difficultySelected(false)
{
}

void WelcomeScreen::draw(sf::RenderWindow& window) {
    drawText(window, L"Выбор сложности:", font, { 100, 50 }, 24, sf::Color::Black);
    easyButton.draw(window);
    mediumButton.draw(window);
    hardButton.draw(window);
}

void WelcomeScreen::handleInput(sf::Event& event, sf::RenderWindow& window) {
    sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (easyButton.isClicked(mousePos)) {
            selectedDifficulty = sf::String(L"Легко"); // Добавили L
            difficultySelected = true;
            std::cout << "Выбрана лёгкая сложность:" << std::endl;
        }
        else if (mediumButton.isClicked(mousePos)) {
            selectedDifficulty = sf::String(L"Средняя"); // Добавили L
            difficultySelected = true;
            std::cout << "Выбрана средняя сложнсть:" << std::endl;
        }
        else if (hardButton.isClicked(mousePos)) {
            selectedDifficulty = sf::String(L"Сложно"); // Добавили L
            difficultySelected = true;
            std::cout << "Выбрана высокая сложность:" << std::endl;
        }
    }
}

sf::String WelcomeScreen::getSelectedDifficulty() const {
    return selectedDifficulty;
}

bool WelcomeScreen::isDifficultySelected() const {
    return difficultySelected;
}