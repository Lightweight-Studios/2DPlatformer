#include "StdKeyBoardCtrlScheme.hpp"
#include <map>
#include <vector>
#include <stdexcept>
#include "Command.hpp"
#include "InitMoveLeft.hpp"
#include "StopMoveLeft.hpp"
#include "InitMoveRight.hpp"
#include "StopMoveRight.hpp"
#include "InitJump.hpp"
#include "NullCommand.hpp"
#include "SDL.h"


StdKeyControlScheme::StdKeyControlScheme() {
	/*
	Create the mapping

	The convention we follow is that an action to be taken on keydown
	will be the first element in the vector, an an action to be take on 
	keyup will be the second element
	*/
	using std::vector;
	vector<Command> handleMoveLeft = { InitMoveLeft(), StopMoveLeft() };
	this->scheme.emplace(SDLK_a, handleMoveLeft);

	vector<Command> handleMoveRight = { InitMoveRight(), StopMoveRight() };
	this->scheme.emplace(SDLK_d, handleMoveRight);

	vector<Command> handleJump = { InitJump() };
	this->scheme.emplace(SDLK_w, handleJump);
}
		
Command * StdKeyControlScheme::translate(SDL_Event *evt) {
	using std::vector;
	try {
		//Why doesn't this work?
		//(*evt).key.keysym.sym
		SDL_Keycode key = evt->key.keysym.sym;
		vector<Command> translatedEvent = this->scheme.at(key);
		if ((translatedEvent.size() == 1) || (translatedEvent.size() > 1 && (*evt).type == SDL_EventType::SDL_KEYDOWN)) {
			return &translatedEvent[0];
		}

		else if(translatedEvent.size() > 1 && (*evt).type == SDL_EventType::SDL_KEYUP) {
			return &translatedEvent[1];
		}

		else {
			throw std::out_of_range("Command mis-specified!");
		}
	}
	catch (std::out_of_range) {
		return new NullCommand();
	}
			
}


	

