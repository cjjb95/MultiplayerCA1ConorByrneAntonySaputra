#pragma once
#include <memory>

#include "SFML/System/NonCopyable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"

namespace sf {
	class Event;
}

namespace GUI
{
	class Component : public sf::Drawable, sf::Transformable, private sf::NonCopyable
	{
	public:
		typedef std::shared_ptr<Component> Ptr;
		Component();
		virtual ~Component();

	public:
		virtual bool isSelectable() const = 0;
		bool isSelected() const;
		virtual void select();
		virtual void deselect();

		virtual bool isActive() const;
		virtual void activate();
		virtual void deactivate();

		virtual void handlEvent(const sf::Event& event) = 0;

	private:
		bool mIsSelected;
		bool mIsActive;
	};
}