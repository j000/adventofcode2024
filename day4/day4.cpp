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

constexpr std::array<char, 4> XMAS = {'X', 'M', 'A', 'S'};

using Search = std::array<Coords, 3>;

bool is_match(Data& data, Coords pos, Coords direction)
{
	for (unsigned char i = 0; i < XMAS.size(); ++i) {
		if (XMAS[i] != data[pos.x + i * direction.x][pos.y + i * direction.y])
			return false;
	}

	return true;
}

int search(Data& data, Coords direction)
{
	int result = 0;

	Coords start{direction.x < 0 ? 3 : 0, direction.y < 0 ? 3 : 0};
	Coords end{direction.x > 0 ? 3 : 0, direction.y > 0 ? 3 : 0};

	for (unsigned char x = start.x; x < data.size() - end.x; ++x) {
		for (unsigned char y = start.y; y < data.size() - end.y; ++y) {
			if (is_match(data, {x, y}, direction))
				result++;
		}
	}

	return result;
}

int search_N(Data& data)
{
	return search(data, {0, -1});
}

int search_NE(Data& data)
{
	return search(data, {1, -1});
}

int search_E(Data& data)
{
	return search(data, {1, 0});
}

int search_SE(Data& data)
{
	return search(data, {1, 1});
}

int search_S(Data& data)
{
	return search(data, {0, 1});
}

int search_SW(Data& data)
{
	return search(data, {-1, 1});
}

int search_W(Data& data)
{
	return search(data, {-1, 0});
}

int search_NW(Data& data)
{
	return search(data, {-1, -1});
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

	int count = 0;

	count += search_N(data);
	count += search_NE(data);
	count += search_E(data);
	count += search_SE(data);
	count += search_S(data);
	count += search_SW(data);
	count += search_W(data);
	count += search_NW(data);

	std::cout << count << "\n";

	return 0;
}
