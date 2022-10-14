#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"
#include "input/InputState.h"

// Interface for scenes
class Scene {
public:
	virtual ~Scene() {}

	virtual void load() = 0;
	virtual void clean() = 0;
	
	virtual void handleEvent(const InputState&) = 0;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void setGame(Game *_game) = 0;
};

#endif