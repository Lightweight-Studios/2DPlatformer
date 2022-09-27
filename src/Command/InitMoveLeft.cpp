#include "Command.hpp"
#include "Logger.hpp"

class InitMoveLeft : public Command {
	public:

		InitMoveLeft() = default;

		~InitMoveLeft() = default;

		void execute override() {
			LOG_MESSAGE("InitMoveLeft command ran");
		}

};