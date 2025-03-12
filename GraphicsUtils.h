#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

// ������� ��� �������� ������ �� �����
sf::Font loadFont(const std::string& filename);

// ������� ��� ��������� ������
void drawText(sf::RenderWindow& window, const sf::String& text, sf::Font& font,
	sf::Vector2f position, unsigned int size, sf::Color color);