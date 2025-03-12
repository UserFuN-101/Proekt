#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

// Функция для загрузки шрифта из файла
sf::Font loadFont(const std::string& filename);

// Функция для отрисовки текста
void drawText(sf::RenderWindow& window, const sf::String& text, sf::Font& font,
	sf::Vector2f position, unsigned int size, sf::Color color);