#pragma once

class Command {

   public:
      Command() = default;
      ~Command() = default;
      Command(const Command& ij) = default;
      Command(Command&&) = default;
      Command& operator=(Command&&) = default;

      virtual void execute() = 0;

};