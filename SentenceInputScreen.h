#pragma once
#include <SFML/Graphics.hpp>
#include "ClickableButton.h"
#include <vector>
#include <string>

class SentenceInputScreen {
public:
    SentenceInputScreen(sf::Font& font, sf::String difficulty);
    void draw(sf::RenderWindow& window);
    void handleInput(sf::Event& event, sf::RenderWindow& window);
    bool isSentencesEntered() const;
    std::vector<std::string> getSentences() const;
    bool isBackButtonClicked(sf::Vector2f mousePos) const;
    void update(float deltaTime);

    void clearSentences(); //Add this method
protected:
    // Caret (курсор)
    sf::RectangleShape caret; // Add this line
    float caretTimer;          // Add this line
    bool caretVisible;         // Add this line
    float caretBlinkSpeed;     // Add this line

private:
    sf::Font& font;
    sf::String difficulty;

    // Ввод текста
    sf::RectangleShape inputField;
    sf::Text inputText;
    bool isInputFieldSelected = false;
    std::string currentInput;
    sf::Text placeholderText;
    sf::String placeholderString;

    // Кнопки
    ClickableButton saveButton;
    ClickableButton startButton;
    ClickableButton backButton;

    // Предложения
    std::vector<std::string> sentences;
    bool sentencesEntered = false;
};