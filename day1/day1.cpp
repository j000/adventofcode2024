#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
	std::vector<std::string> args{};
	for (int i = 0; i < argc; ++i)
	{
		args.push_back(argv[i]);
	}

	std::cout << "test\n";
	for (auto str : args) {
		std::cout << str << "\n";
	}
	return 0;
}
