#include <map>
#include <vector>
#include "Command.hpp"
#include "InitMoveLeft.hpp"
#include "StopMoveLeft.hpp"
#include "InitMoveRight.hpp"
#include "StopMoveRight.hpp"
#include "InitJump.hpp"
#include "NullCommand.hpp"
#include "ControlScheme.hpp"
#include "SDL.h"


class StdKeyControlScheme : public ControlScheme {

	public:
		StdKeyControlScheme() {
			/*
			Create the mapping

			The convention we follow is that an action to be taken on keydown
			will be the first element in the vector, an an action to be take on 
			keyup will be the second element
			*/
			
			InitMoveLeft initMoveLeft = new InitMoveLeft();
			StopMoveLeft stopMoveLeft = new StopMoveLeft();
			vector<Command> handleMoveLeft = { initMoveLeft, stopMoveLeft };
			scheme.insert(std::make_pair(SDLK_a, handleMoveLeft));

			InitMoveRight initMoveRight = new InitMoveRight();
			StopMoveRight stopMoveRight = new StopMoveRight();
			vector<Command> handleMoveRight = { initMoveRight, initMoveRight };
			sceme.insert(std::make_pair(SDLK_d, handleMoveRight));

			InitJump initJump = new InitJump();
			vector<Command> handleJump = { initJump };
			scheme.insert(std::make_pair(SDLK_w, handleJump)
		}
		
		void translate override(*SDL_Event evt) {
			try {
				vector<Command> translatedEvent = scheme.at(*evt);
				if ((translatedEvent.length == 1) || (translatedEvent.length > 1 && *evt.type == SDL_KEYDOWN))){
					return translatedEvent[0];
				}

				else if(translatedEvent.length > 1 && *evt.type == SDL_KEYUP) {
					return translatedEvent[1];
				}

				else {
					thow std::out_of_range("Command mis-specified!");
				}
			}
			catch (std::out_of_range) {
				return new NullCommand();
			}
			
		}


	private:
		std::map<SDL_Event, Command> scheme;

};