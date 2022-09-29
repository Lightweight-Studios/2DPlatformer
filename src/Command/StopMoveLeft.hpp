#pragma once
#include "Command.hpp"

class StopMoveLeft : public Command {

public:

	StopMoveLeft() = default;
	~StopMoveLeft() = default;
	StopMoveLeft(const StopMoveLeft& sml) = default;

	void execute() override;

};