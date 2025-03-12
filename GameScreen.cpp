#include "GameScreen.h"
#include "GraphicsUtils.h"
#include <iostream>

GameScreen::GameScreen(sf::Font& font, const std::vector<std::string>& sentences) :
    font(font),
    sentences(sentences),
    backButton({ 600, 50 }, { 100, 30 }, font, 20, sf::String(L"Назад"))
{
    sentenceText.setFont(font);
    sentenceText.setCharacterSize(24);
    sentenceText.setFillColor(sf::Color::Black);
    sentenceText.setPosition(100, 100);

    if (!sentences.empty()) {
        sentenceText.setString(sentences[0]); // Display the first sentence
    }
    else {
        sentenceText.setString("No sentences entered!");
    }
}

void GameScreen::draw(sf::RenderWindow& window) {
    window.draw(sentenceText);
    backButton.draw(window);
}

void GameScreen::update(float deltaTime) {

}

void GameScreen::handleInput(sf::Event& event, sf::RenderWindow& window) {

}

bool GameScreen::isBackButtonClicked(sf::Vector2f mousePos) const {
    return backButton.isClicked(mousePos);
}