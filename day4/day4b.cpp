#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

constexpr int INPUT_SIZE = 140;
using Data = std::array<std::array<unsigned char, INPUT_SIZE>, INPUT_SIZE>;

struct Coords {
	int x{0};
	int y{0};
};

bool is_match(Data& data, Coords pos)
{
	if ('A' != data[pos.x][pos.y])
		return false;

	if (('M' != data[pos.x - 1][pos.y - 1] || 'S' != data[pos.x + 1][pos.y + 1])
		&& ('S' != data[pos.x - 1][pos.y - 1]
			|| 'M' != data[pos.x + 1][pos.y + 1]))
		return false;

	if (('M' != data[pos.x - 1][pos.y + 1] || 'S' != data[pos.x + 1][pos.y - 1])
		&& ('S' != data[pos.x - 1][pos.y + 1]
			|| 'M' != data[pos.x + 1][pos.y - 1]))
		return false;

	return true;
}

int search(Data& data)
{
	int result = 0;

	for (unsigned char x = 1; x < data.size() - 1; ++x) {
		for (unsigned char y = 1; y < data.size() - 1; ++y) {
			if (is_match(data, {x, y}))
				result++;
		}
	}

	return result;
}

int main(int argc, char** argv)
{
	std::ifstream fin{};
	if (argc > 1)
		fin.open(argv[1]);

	std::istream& in = fin.is_open() ? fin : std::cin;

	Data data{};

	in >> std::noskipws;

	char c;
	int x{0};
	int y{0};
	while (in >> c) {
		if (c == '\n') {
			++y;
			x = 0;
			continue;
		}

		data[x][y] = c;
		++x;
	}

	int count = search(data);

	std::cout << count << "\n";

	return 0;
}
