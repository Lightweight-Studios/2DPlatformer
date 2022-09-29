#pragma once
#include "Command.hpp"

class InitJump : public Command {

public:

	InitJump() = default;
	~InitJump() = default;
	InitJump(const InitJump& ij) = default;

	void execute() override;

};