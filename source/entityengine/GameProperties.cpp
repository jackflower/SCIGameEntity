////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek 2022
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraŸnych ani domniemanych gwarancji.
//
// W ¿adnym wypadku Autor nie ponosi odpowiedzialnoœci
// za jakiekolwiek szkody powsta³e w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala siê na korzystanie z tego oprogramowania
// w dowolnym celu, tak¿e komercyjnym. Mo¿na je zmieniæ
// i swobodnie rozpowszechniaæ.
//
// Zastrzega siê nastêpuj¹ce ograniczenia:
//
// 1. Jeœli u¿ywasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    by³oby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "GameProperties.hpp"

// static

sf::Vector2u GameProperties::m_scene_size = sf::Vector2u(800,600);
std::string GameProperties::m_title = "Acodemia SCI Game Entity 2022";

// get the size of the rendering region of the window
const sf::Vector2u& GameProperties::getSceneSize()
{
	return GameProperties::m_scene_size;
}

// set the size of the rendering region of the window
void GameProperties::setSceneSize(const sf::Vector2u& scene_size)
{
	m_scene_size = scene_size;
}

// get the title of the rendering window
const std::string& GameProperties::getTitle()
{
	return m_title;
}

// set the title of the rendering window
void GameProperties::setTitle(const std::string& title)
{
	m_title = title;
}