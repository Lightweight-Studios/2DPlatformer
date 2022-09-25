#include "Command.hpp"
#include "<string>"
#include "<iostream>"

class InitMoveLeft : public Command {
	public:

		InitMoveLeft() = default;

		~InitMoveLeft() = default;

		void execute override() {
			std::cout << "InitMoveLeft command ran";
		}

};