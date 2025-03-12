#include "GraphicsUtils.h"

// ������� ��� �������� ������ �� �����
sf::Font loadFont(const std::string& filename) {
    sf::Font font; // ������� ������ ������
    if (!font.loadFromFile(filename)) { // ��������� ����� �� �����, ���������, ��� �������� ������ �������
        std::cerr << "������ �������� ������:" << filename << std::endl; // ������� ��������� �� ������ � �������
    }
    return font;
}

// ������� ��� ��������� ������
void drawText(sf::RenderWindow& window, const sf::String& text, sf::Font& font, sf::Vector2f position, unsigned int size, sf::Color color) {
    sf::Text textObj(text, font, size); // ������� ������ ������
    textObj.setPosition(position);      // ������������� ������� ������
    textObj.setFillColor(color);        // ������������� ���� ������
    window.draw(textObj);              // ������ ����� �� ����
}