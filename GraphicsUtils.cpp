#include "GraphicsUtils.h"

// Функция для загрузки шрифта из файла
sf::Font loadFont(const std::string& filename) {
    sf::Font font; // Создаем объект шрифта
    if (!font.loadFromFile(filename)) { // Загружаем шрифт из файла, проверяем, что загрузка прошла успешно
        std::cerr << "Ошибка загрузки шрифта:" << filename << std::endl; // Выводим сообщение об ошибке в консоль
    }
    return font;
}

// Функция для отрисовки текста
void drawText(sf::RenderWindow& window, const sf::String& text, sf::Font& font, sf::Vector2f position, unsigned int size, sf::Color color) {
    sf::Text textObj(text, font, size); // Создаем объект текста
    textObj.setPosition(position);      // Устанавливаем позицию текста
    textObj.setFillColor(color);        // Устанавливаем цвет текста
    window.draw(textObj);              // Рисуем текст на окне
}