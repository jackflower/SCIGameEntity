//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(400, 300), "Acodemia SCI Game Entity 2021", sf::Style::Close);
//
//	sf::Texture my_texture;
//	my_texture.setSmooth(true);
//
//	if (!my_texture.loadFromFile("../SCIGameEntity/data/enemy.png"))
//		std::cout << "error loading texture..." << "\n";
//	
//	sf::Sprite my_sprite;
//	my_sprite.setTexture(my_texture);
//	my_sprite.setPosition(100, 100);
//
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		my_sprite.rotate(0.0125f);
//		window.clear(sf::Color::White);
//		window.draw(my_sprite);
//		window.display();
//	}
//
//	return 0;
//}