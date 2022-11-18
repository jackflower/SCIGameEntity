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

#include "Game.hpp"
#include <iostream>

// Default constructor
Game::Game() :
	m_render_window{ sf::VideoMode(EntityEngine::getSceneSize().x, EntityEngine::getSceneSize().y), EntityEngine::getTitle(), sf::Style::Close },
	m_entity_engine{},
	p_player{ nullptr }
{
	m_render_window.setKeyRepeatEnabled(false);

	createEntities();

	if (!m_actor_texture.loadFromFile("../SCIGameEntity/data/physical.png"))
		std::cout << "error loading texture..." << "\n";
	m_actor_texture.setSmooth(true);

	m_actor.setTexture(m_actor_texture);
	m_actor.setOrigin(m_actor.getLocalBounds().width * 0.5f, m_actor.getLocalBounds().height * 0.5f);
	m_actor.setPosition(50.f, 50.f);
}

// Virtual destructor
Game::~Game()
{
	p_player = nullptr;
}

// Run game
void Game::run()
{
	// alternatively two versions of the real-time loop

	// - real-time loop with constant step
	constantStepLoop();

	// - real-time loop with variable step 
	// variableStepLoop();
}

// The method registers pointers to Entity objects in the container
void Game::registerEntity(logic::Actor* entity)
{
	m_entity_engine.registerEntity(entity);
}

void Game::processEvents()
{
	sf::Event event;
	while (m_render_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (p_player)
				p_player->updatePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			if (p_player)
				p_player->updatePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			m_render_window.close();
			break;
		}
	}
}

void Game::update(float dt)
{
	m_entity_engine.update(dt);
	m_actor.rotate(1.125f);
}

void Game::render()
{
	m_render_window.clear(sf::Color::White);
	m_entity_engine.draw(m_render_window, sf::RenderStates::Default);
	m_actor.draw(m_render_window, sf::RenderStates::Default);
	m_render_window.display();
}

void Game::createEntities()
{
	// P l a y e r
	// allocate memory to the pointer *)
	p_player = m_entity_engine.createPlayer();
	p_player->setTexture(m_entity_engine.getTexture());
	p_player->setTextureRect(sf::IntRect(0, 0, 64, 64));
	p_player->setPosition(400.f, 400.f);
	p_player->setVelocity(200);
	p_player->setScale(1, 1);
	p_player->setOrigin(p_player->getLocalBounds().width * 0.5f, p_player->getLocalBounds().height * 0.5f);
	p_player->setRateFire(0.25f);
	p_player->setHealth(100.0f);
	p_player->setCollisionDamage(25);
	// *) memory is released in the container
}

// real-time loop with constant step
void Game::constantStepLoop()
{
	sf::Clock clock;
	m_render_window.setVerticalSyncEnabled(true);

	float time_since_last_update = 0.0f;
	float frame_time = 1.f / 60.f;

	while (m_render_window.isOpen())
	{
		float elapsedTime = clock.restart().asSeconds();
		time_since_last_update += elapsedTime;
		while (time_since_last_update > frame_time)
		{
			time_since_last_update -= frame_time;
			processEvents();
			update(frame_time);
		}
		render();
	}
}

// real-time loop with variable step 
void Game::variableStepLoop()
{
	sf::Clock clock;
	float elapsed_time = 0.0f;
	m_render_window.setFramerateLimit(60);
	m_render_window.setVerticalSyncEnabled(true);

	while (m_render_window.isOpen())
	{
		elapsed_time = clock.restart().asSeconds();
		processEvents();
		update(elapsed_time);
		render();
	}
}
