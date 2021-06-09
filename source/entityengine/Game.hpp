////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek 2021
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


#ifndef HPP_GAME_ACODEMIA
#define HPP_GAME_ACODEMIA

#include <SFML/Graphics.hpp>
#include"../logic/Actor.hpp"
#include"../logic/Enemy.hpp"
#include"../logic/Player.hpp"
#include "../entityengine/EntityEngine.hpp"


///
/// The class represents the game window
///
class Game
{
public:

	///
	/// Default constructor
	///
	Game();

	///
	/// Virtual destructor
	///
	virtual ~Game();

	///
	/// Run game
	///
	void run();

	///
	/// The method registers pointers to Entity objects in the container
	///
	/// @param *entity - a pointer to an Entity object 
	///
	void registerEntity(Actor* entity);

	///
	/// Size of the rendering region of the window
	///
	const sf::Vector2u getSize() const;

private:

	sf::Vector2u m_size; // size of the rendering region of the window
	sf::RenderWindow m_render_window; // game window
	EntityEngine m_entity_engine; //container for storing and managing game objects
	Player* p_player; // pointer to Player

	void processEvents();
	void update(float dt);
	void render();
	void createEntities();

	// real-time loop with constant step
	void constantStepLoop();

	// real-time loop with variable step
	void variableStepLoop();

	sf::Texture m_actor_texture; // tests
	logic::Actor m_actor; // tests

};

#endif //HPP_GAME_ACODEMIA
