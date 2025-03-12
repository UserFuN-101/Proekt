#include <SFML/Graphics.hpp>
#include "DifficultySelectionScreen.h"
#include "GraphicsUtils.h"
#include "ClickableButton.h"
#include "GameScreen.h"
#include "SentenceInputScreen.h"
#include <iostream>

enum class Screen {
    DifficultySelection,
    SentenceInput,
    Game
};

int main() {
    setlocale(LC_ALL, "RU");

    sf::RenderWindow window(sf::VideoMode(800, 600), L"Игра");

    // ШРИФТ
    std::string fontPath = "D:/Users/c01/source/repos/forma avtorizacii/resources/fonts/arial.ttf";
    std::cout << "Попытка загрузить шрифт из: " << fontPath << std::endl;
    sf::Font font;
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Ошибка: не удалось загрузить шрифт из: " << fontPath << std::endl;
        return 1;
    }
    else {
        std::cerr << "шрифт загружен: " << fontPath << std::endl;
    }

    // КАРТИНКА
    std::string imagePath = "D:/Users/c01/source/repos/forma avtorizacii/resources/images/non.jpg";
    std::cout << "Попытка загрузить картинку из: " << imagePath << std::endl;
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(imagePath)) {
        std::cerr << "Ошибка: не удалось загрузить картинку из: " << imagePath << std::endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(800.0f / backgroundTexture.getSize().x, 600.0f / backgroundTexture.getSize().y);

    sf::Vector2f windowSize(800, 600);
    DifficultySelectionScreen difficultySelectionScreen(font, windowSize);
    SentenceInputScreen* sentenceInputScreen = nullptr;
    GameScreen* gameScreen = nullptr;

    Screen currentScreen = Screen::DifficultySelection;
    sf::String selectedDifficulty;

    sf::Clock clock;  // Add a clock for measuring time

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart(); // Calculate time since last frame
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

            if (event.type == sf::Event::Resized) {
                // Update the view to the new size
                windowSize.x = event.size.width;
                windowSize.y = event.size.height;
                sf::View view(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
                window.setView(view);

                // Calculate the scale factor for the background
                float backgroundScaleX = static_cast<float>(windowSize.x) / static_cast<float>(backgroundTexture.getSize().x);
                float backgroundScaleY = static_cast<float>(windowSize.y) / static_cast<float>(backgroundTexture.getSize().y);

                backgroundSprite.setScale(backgroundScaleX, backgroundScaleY);
                difficultySelectionScreen.updatePositions(windowSize);
            }
            switch (currentScreen) {
            case Screen::DifficultySelection:
                difficultySelectionScreen.handleInput(event, window);
                if (difficultySelectionScreen.isDifficultySelected()) {
                    currentScreen = Screen::SentenceInput;
                    selectedDifficulty = difficultySelectionScreen.getSelectedDifficulty();
                    sentenceInputScreen = new SentenceInputScreen(font, selectedDifficulty);
                }
                break;

            case Screen::SentenceInput:
                if (sentenceInputScreen) {
                    sentenceInputScreen->handleInput(event, window);

                    if (sentenceInputScreen->isSentencesEntered()) {
                        std::vector<std::string> sentences = sentenceInputScreen->getSentences();
                        if (!sentences.empty()) {
                            currentScreen = Screen::Game;
                            gameScreen = new GameScreen(font, sentences);
                            sentenceInputScreen->caret.setPosition(0, 0); //Reset the caret position
                            delete sentenceInputScreen;
                            sentenceInputScreen = nullptr;
                        }
                        else {
                            std::cerr << "Error: No sentences entered. Cannot start game." << std::endl;
                        }
                    }

                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                        if (sentenceInputScreen->isBackButtonClicked(mousePos)) {
                            currentScreen = Screen::DifficultySelection;
                            sentenceInputScreen->caret.setPosition(0, 0); //Reset the caret position
                            difficultySelectionScreen.resetSelection(sentenceInputScreen);
                            delete sentenceInputScreen;
                            sentenceInputScreen = nullptr;
                        }
                    }
                }
                break;

            case Screen::Game:
                if (gameScreen) {
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                        if (gameScreen->isBackButtonClicked(mousePos)) {
                            currentScreen = Screen::DifficultySelection;
                            delete gameScreen;
                            gameScreen = nullptr;
                            difficultySelectionScreen.resetSelection(nullptr);
                        }
                    }
                }
                break;
            }
        }

        // Update game logic
        if (sentenceInputScreen) { // Check for nullptr
            if (currentScreen == Screen::SentenceInput) {
                sentenceInputScreen->update(deltaTime.asSeconds());
            }
        }

        window.clear(sf::Color::White);
        window.draw(backgroundSprite);

        switch (currentScreen) {
        case Screen::DifficultySelection:
            difficultySelectionScreen.draw(window);
            break;

        case Screen::SentenceInput:
            if (sentenceInputScreen) {
                sentenceInputScreen->draw(window);
            }
            break;

        case Screen::Game:
            if (gameScreen) {
                gameScreen->draw(window);
            }
            break;
        }

        window.display();
    }

    if (gameScreen) {
        delete gameScreen;
    }
    if (sentenceInputScreen) {
        delete sentenceInputScreen;
    }

    return 0;
}