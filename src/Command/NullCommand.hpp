#pragma once
#include "Command.hpp"
class NullCommand : public Command {

public:

	NullCommand() = default;
	~NullCommand() = default;
	NullCommand(const NullCommand& n) = default;

	void execute() override;

};