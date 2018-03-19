#include <iostream>
#include "ConsoleUI.h"
#include "Processor.h"

int main(int argc, char* const* argv)
{
	std::vector<std::string> args(argv + 1, argv + argc);
	Processor processor;

	ConsoleUI ui;
	if (!ui.Init(processor.GetRegisters(), processor.GetMemory(), args)) {
		std::cerr << "Error: Failed to initialize console UI!" << std::endl;
		return 1;
	}

	for (;;) {
		auto cmd = ui.GetCommand();
		ui.Process(cmd, processor);
	}
	return 0;
}
