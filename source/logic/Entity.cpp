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

#include "Entity.hpp"

namespace logic
{

	// Default constructor
	Entity::Entity() :
		sf::Drawable{}, // base class constructor
		sf::Transformable{}, // base class constructor
		m_sprite{}
	{
	}

	// Copy constructor
	Entity::Entity(const Entity& copy) :
		//sf::Drawable{ copy }, // noncopyable...
		sf::Transformable{ copy }, // base class copy constructor
		m_sprite{ copy.m_sprite }
	{
	}

	// Move constructor
	Entity::Entity(Entity&& other) :
		//sf::Drawable{ other }, // noncopyable...
		sf::Transformable{ other }, // base class move constructor
		m_sprite{ other.m_sprite }
	{
	}

	// Virtual destructor
	Entity::~Entity()
	{
	}

	// Overloaded copy assignment operator
	Entity& Entity::operator=(const Entity& copy)
	{
		if (this != &copy)
		{
			m_sprite = copy.m_sprite;
		}
		return *this;
	}

	// Overloaded move assignment operator
	Entity& Entity::operator=(Entity&& other)
	{
		if (this != &other)
		{
			m_sprite = other.m_sprite;
		}
		return *this;
	}

	// Get the sub-rectangle of the texture that the object will display
	const sf::IntRect& Entity::getTextureRect() const
	{
		return m_sprite.getTextureRect();
	}

	// Set the sub-rectangle of the texture that the object will display
	void Entity::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight)
	{
		setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
	}

	// Set the sub-rectangle of the texture that the object will display
	void Entity::setTextureRect(const sf::IntRect& rectangle)
	{
		m_sprite.setTextureRect(rectangle);
	}

	// Get the local bounding rectangle of the entity
	sf::FloatRect Entity::getLocalBounds() const
	{
		return m_sprite.getLocalBounds();
	}

	// Get the global bounding rectangle of the entity
	sf::FloatRect Entity::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	// Get the global color of the object
	const sf::Color&  Entity::getColor() const
	{
		return m_sprite.getColor();
	}

	// Set the global color of the object
	void Entity::setColor(const sf::Color& color)
	{
		m_sprite.setColor(color);
	}

	// Get the source texture of the sprite
	const sf::Texture* Entity::getTexture() const
	{
		return m_sprite.getTexture();
	}

	// Change the source texture of the object
	void Entity::setTexture(const sf::Texture & texture)
	{
		m_sprite.setTexture(texture);
	}

	// Virtual object rendering method
	void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// a position / rotation / scale transformation must
		// take place before the unit is displayed
		states.transform *= getTransform();
		target.draw(m_sprite, states);
	}

}//namespace logic
