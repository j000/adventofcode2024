#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char** argv)
{
	std::ifstream fin{};

	if (argc > 1) {
		fin.open(argv[1]);
	}

	std::istream &in = fin.is_open() ? fin : std::cin;

	std::vector<long> left{};
	std::vector<long> right{};

	long a{0};
	long b{0};
	while (in >> a >> std::ws >> b) {
		left.push_back(a);
		right.push_back(b);
	}

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	long long result{0};
	for (auto value : left) {
		long long count = std::count(right.begin(), right.end(), value);
		result += value * count;
	}
	std::cout << result << "\n";

	return 0;
}
