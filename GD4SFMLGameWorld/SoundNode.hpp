//Antony Saputra D00197615
//Conor Byrne D00185566

#pragma once
#include "SceneNode.hpp"
#include "ResourceIdentifiers.hpp"
#include "SoundPlayer.hpp"


class SoundNode : public SceneNode
{
public:
	explicit SoundNode(SoundPlayer& player);
	void playSound(SoundEffectID sound, sf::Vector2f position);

	virtual unsigned int getCategory() const;

private:
	SoundPlayer& mSound;
};