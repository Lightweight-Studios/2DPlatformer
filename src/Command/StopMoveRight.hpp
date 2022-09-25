#pragma once
#include "Command.hpp"

class StopMoveRight : public Command {

public:

	StopMoveRight() = default;
	~StopMoveRight() = default;

	void execute() override;

}