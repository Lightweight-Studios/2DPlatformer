#include "StdKeyBoardCtrlScheme.hpp"
#include <map>
#include <vector>
#include<memory>
#include <stdexcept>
#include "Command.hpp"
#include "InitMoveLeft.hpp"
#include "StopMoveLeft.hpp"
#include "InitMoveRight.hpp"
#include "StopMoveRight.hpp"
#include "InitJump.hpp"
#include "NullCommand.hpp"
#include "SDL.h"

using std::vector; using std::shared_ptr;

StdKeyControlScheme::StdKeyControlScheme() {
	/*
	Create the mapping

	The convention we follow is that an action to be taken on keydown
	will be the first element in the vector, an an action to be take on 
	keyup will be the second element
	*/
	

	vector<shared_ptr<Command>> handleMoveLeft = { std::make_shared<InitMoveLeft>(), std::make_shared<StopMoveLeft>() };
	this->scheme.emplace(SDLK_a, handleMoveLeft);

	vector<shared_ptr<Command>> handleMoveRight = { shared_ptr<Command>(new InitMoveRight()), shared_ptr<Command>(new StopMoveRight()) };
	this->scheme.emplace(SDLK_d, handleMoveRight);

	vector<shared_ptr<Command>> handleJump = { shared_ptr<Command>(new InitJump()) };
	this->scheme.emplace(SDLK_w, handleJump);
}
		
shared_ptr<Command> StdKeyControlScheme::translate(SDL_Event *evt) {
	using std::vector;
	try {
		//Why doesn't this work?
		//(*evt).key.keysym.sym
		SDL_Keycode key = evt->key.keysym.sym;
		vector<shared_ptr<Command>> translatedEvent = this->scheme.at(key);
		if ((translatedEvent.size() == 1) || (translatedEvent.size() > 1 && (*evt).type == SDL_EventType::SDL_KEYDOWN)) {
			return translatedEvent[0];
		}

		else if(translatedEvent.size() > 1 && (*evt).type == SDL_EventType::SDL_KEYUP) {
			return translatedEvent[1];
		}

		else {
			throw std::out_of_range("Command mis-specified!");
		}
	}
	catch (std::out_of_range) {
		return shared_ptr<Command>(new NullCommand());
	}
			
}


	

