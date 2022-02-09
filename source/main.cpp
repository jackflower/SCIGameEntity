#include <SFML/Graphics.hpp>
#include <iostream>


// na etapie tworzenie dokumentacji ten kod jest produkcyjnym

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 300), "Acodemia SCI Game Entity 2021", sf::Style::Close);

	sf::Texture my_texture;
	//my_texture.setSmooth(true);

	if (!my_texture.loadFromFile("../SCIGameEntity/data/enemy.png"))
		std::cout << "error loading texture..." << "\n";

	sf::Sprite my_sprite;
	my_sprite.setTexture(my_texture);
	my_sprite.setPosition(100, 100);
	my_sprite.setRotation(-45);
	my_sprite.setScale(4.f, 4.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//my_sprite.rotate(0.0125f);
		window.clear(sf::Color::White);
		window.draw(my_sprite);
		window.display();
	}

	return 0;
}











//////////////////////////////////////////////////////////////
////
//// Acodemia Copyright (C) Jacek Kwiatek 2021
//// e-mail: jackflower (at) poczta.onet.pl
//// acodemia.pl
////
//// To oprogramowanie dostarczane jest w postaci takiej,
//// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
////
//// W żadnym wypadku Autor nie ponosi odpowiedzialności
//// za jakiekolwiek szkody powstałe w wyniku korzystania
//// z tego oprogramowania.
////
//// Zezwala się na korzystanie z tego oprogramowania
//// w dowolnym celu, także komercyjnym. Można je zmienić
//// i swobodnie rozpowszechniać.
////
//// Zastrzega się następujące ograniczenia:
////
//// 1. Jeśli używasz tego oprogramowania w swoich
////    produktach, potwierdzenie pochodzenia tego
////    oprogramowania w dokumentacji produktu,
////    byłoby docenione, ale nie jest wymagane.
////
//////////////////////////////////////////////////////////////
//
//
//#include "entityengine/Game.hpp"
//
//int main()
//{
//	Game game;
//	game.run();
//	return 0;
//}
