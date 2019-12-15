#pragma once

//Entity/SceneNode category, used to dispatch commands
enum class CategoryID
{
	None = 0,
	Scene = 1 << 0,
	PlayerStickman1 = 1 << 1,
	PlayerStickman2 = 1 << 2,
	EnemyAircraft = 1 << 3
};