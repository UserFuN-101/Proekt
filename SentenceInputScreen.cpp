//SentenceInputScreen.cpp
#include "SentenceInputScreen.h"
#include "GraphicsUtils.h"
#include <iostream>

SentenceInputScreen::SentenceInputScreen(sf::Font& font, sf::String difficulty) :
    font(font),
    difficulty(difficulty),
    inputField(sf::Vector2f(600, 50)),
    inputText("", font, 20),
    saveButton({ 100, 170 }, { 100, 30 }, font, 20, sf::String(L"Сохранить")),
    startButton({ 250, 170 }, { 150, 30 }, font, 20, sf::String(L"Начать игру")),
    backButton({ 600, 170 }, { 100, 30 }, font, 20, sf::String(L"Назад"))
{
    inputField.setPosition(100, 100);
    inputField.setFillColor(sf::Color::White);
    inputField.setOutlineColor(sf::Color::Black);
    inputField.setOutlineThickness(2);

    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(110, 110);

    placeholderString = L"Введите текст";
    placeholderText.setFont(font);
    placeholderText.setString(placeholderString);
    placeholderText.setCharacterSize(20);
    placeholderText.setFillColor(sf::Color(128, 128, 128));
    placeholderText.setPosition(110, 110);

    // Caret initialization
    caret = sf::RectangleShape(sf::Vector2f(2, 20)); // Width 2, Height 20
    caret.setFillColor(sf::Color::Black);
    caret.setPosition(110, 110); // Initial position
    caretTimer = 0.0f;
    caretVisible = true;
    caretBlinkSpeed = 0.5f; // Blink every 0.5 seconds
}

void SentenceInputScreen::draw(sf::RenderWindow& window) {
    window.draw(inputField);
    if (currentInput.empty() && !isInputFieldSelected) {
        window.draw(placeholderText);
    }
    else {
        window.draw(inputText);
    }

    // Draw caret only when input field is selected
    if (isInputFieldSelected) {
        if (caretVisible) {
            window.draw(caret);
        }
    }

    saveButton.draw(window);
    startButton.draw(window);
    backButton.draw(window);
}

void SentenceInputScreen::handleInput(sf::Event& event, sf::RenderWindow& window) {
    sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (inputField.getGlobalBounds().contains(mousePos)) {
            isInputFieldSelected = true;
        }
        else {
            isInputFieldSelected = false;
        }

        if (saveButton.isClicked(mousePos)) {
            sentences.push_back(currentInput);
            std::cout << "Предложение сохранено: " << currentInput << std::endl;
            currentInput = "";
            inputText.setString("");
            isInputFieldSelected = true;

            // Update caret position after saving text
            float textWidth = inputText.getLocalBounds().width;
            caret.setPosition(inputField.getPosition().x + 12 + textWidth, inputField.getPosition().y + 10);
        }

        if (startButton.isClicked(mousePos)) {
            if (!sentences.empty()) {
                sentencesEntered = true;
                std::cout << "Начинаем игру с " << sentences.size() << " предложениями." << std::endl;
            }
            else {
                std::cout << "Необходимо ввести хотя бы одно предложение." << std::endl;
            }
        }
    }

    if (isInputFieldSelected && event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            if (event.text.unicode == 8) {
                if (!currentInput.empty()) {
                    currentInput.pop_back();
                }
            }
            else if (currentInput.size() < 40) { // Add this check
                currentInput += static_cast<char>(event.text.unicode);
            }
            inputText.setString(currentInput);

            // Update caret position after text is entered
            float textWidth = inputText.getLocalBounds().width;
            caret.setPosition(inputField.getPosition().x + 12 + textWidth, inputField.getPosition().y + 10);
        }
    }
}

bool SentenceInputScreen::isBackButtonClicked(sf::Vector2f mousePos) const {
    return backButton.isClicked(mousePos);
}

bool SentenceInputScreen::isSentencesEntered() const {
    return sentencesEntered;
}

std::vector<std::string> SentenceInputScreen::getSentences() const {
    return sentences;
}

void SentenceInputScreen::update(float deltaTime) {
    if (isInputFieldSelected) {
        caretTimer += deltaTime;
        if (caretTimer >= caretBlinkSpeed) {
            caretVisible = !caretVisible;
            caretTimer -= caretBlinkSpeed;
        }
    }
}

void SentenceInputScreen::clearSentences() {
    sentences.clear();
}