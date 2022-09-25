#pragma once
#include "Command.hpp"

class InitMoveLeft : public Command {

public:
	InitMoveLeft() = default;
	~InitMoveLeft() = default;

	void execute() override;

}