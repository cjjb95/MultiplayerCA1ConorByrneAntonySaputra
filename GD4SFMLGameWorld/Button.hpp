//Antony Saputra D00197615
//Conor Byrne D00185566

#pragma once
#include "Component.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Utility.hpp"
#include "SoundPlayer.hpp"
#include "State.hpp"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"


#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace GUI
{
	class Button : public Component
	{
	public:
		typedef std::shared_ptr<Button> Ptr;
		typedef std::function <void()> Callback;

	public:
		Button(State::Context context);

		void setCallback(Callback callback);
		void setText(const std::string& text);
		void setToggle(bool flag);

		virtual bool isSelectable() const;
		virtual void select();
		virtual void deselect();

		virtual void activate();
		virtual void deactivate();

		virtual void handleEvent(const sf::Event& event);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		Callback mCallback;
		const sf::Texture& mNormalTexture;
		const sf::Texture& mSelectedTexture;
		const sf::Texture& mPressedTexture;
		sf::Sprite mSprite;
		sf::Text mText;
		bool mIsToggle;
		SoundPlayer& mSound;
	};
}