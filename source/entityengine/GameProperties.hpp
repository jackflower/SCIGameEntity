////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek 2022
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////


#ifndef HPP_GAME_PROPERTIES_ACODEMIA
#define HPP_GAME_PROPERTIES_ACODEMIA

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "SFML/System/Vector2.hpp"
#include <string>

////////////////////////////////////////////////////////////
/// \brief Class represents a set of basic properties
///
////////////////////////////////////////////////////////////
class GameProperties
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Get the size of the rendering region of the window
	///
	/// \return size of the window
	///
	////////////////////////////////////////////////////////////
	static const sf::Vector2u& getSceneSize();

	////////////////////////////////////////////////////////////
	/// \brief Set the size of the rendering region of the window
	///
	/// \param scene_size - reference to sf::Vector2u
	///
	////////////////////////////////////////////////////////////
	static void setSceneSize(const sf::Vector2u& scene_size);

	////////////////////////////////////////////////////////////
	/// \brief Get the title of the rendering window
	///
	/// \return title of the rendering window
	///
	////////////////////////////////////////////////////////////
	static const std::string& getTitle();

	////////////////////////////////////////////////////////////
	/// \brief Set the title of the rendering window
	///
	/// \param title - reference to std::string
	///
	////////////////////////////////////////////////////////////
	static void setTitle(const std::string& title);

private:
	// static
	static sf::Vector2u m_scene_size; // size of the rendering region of the window
	static std::string m_title; // title of the window
};
#endif //HPP_GAME_PROPERTIES_ACODEMIA
