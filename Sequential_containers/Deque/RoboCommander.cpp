#include <stdexcept>
#include <iostream>
#include <deque>

using namespace std;

enum CommandType
{
	MoveLeft,
	MoveRight,
	MoveForward,
	MoveBackward
};

class RoboCommander
{
private:
	deque <CommandType> cmds;
public:
	void AddCommand(CommandType cmd);
	void UndoCommand();
	void Execute();
};

void RoboCommander::AddCommand(CommandType cmd)
{
	cmds.push_back(cmd);
}


void RoboCommander::UndoCommand()
{
	if (!cmds.empty())
		cmds.pop_back();
}

void printDirection(CommandType type)
{
	switch (type) {
		case MoveLeft:
			cout << "Moving left";
			break;
		case MoveRight:
			cout << "Moving right";
			break;
		case MoveForward:
			cout << "Moving forward";
			break;
		case MoveBackward:
			cout << "Moving backward";
			break;
		default:
			throw runtime_error("Not supported movement!");
	}
}

void RoboCommander::Execute()
{
	for (unsigned i = 0; i < cmds.size(); ++i)
	{
		printDirection(cmds[i]);
		cout << "\n";
	}
	cout << "Ready" << endl;
}

int main()
{
	RoboCommander commander;
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveRight);
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveForward);
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveForward);
	commander.AddCommand(MoveRight);
	commander.AddCommand(MoveBackward);
	commander.Execute();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(MoveForward);
	commander.Execute();
	// Test not supported command:
	try
	{
		commander.AddCommand(static_cast<CommandType>(7));
		commander.Execute();
	}
	catch (runtime_error e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
