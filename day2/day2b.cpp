#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <vector>

enum class State : char {
	Decreasing = -1,
	Unknown = 0,
	Increasing = 1,
};

bool is_safe(std::vector<int>& data)
{
	if (data.size() < 2)
		return true;

	auto state{State::Unknown};
	auto prev{data.front()};
	for (auto current : data | std::views::drop(1)) {
		auto diff = current - prev;

		if (auto tmp = std::abs(diff); tmp < 1 || tmp > 3)
			return false;

		if (State::Unknown == state) {
			state = diff > 0 ? State::Increasing : State::Decreasing;
		} else if (State::Increasing == state && diff < 0) {
			return false;
		} else if (State::Decreasing == state && diff > 0) {
			return false;
		}

		prev = current;
	}

	return true;
}

bool is_almost_safe(std::vector<int>& data)
{
	if (is_safe(data))
		return true;

	for (unsigned i = 0; i < data.size(); ++i) {
		auto tmp = data[i];
		data.erase(std::next(data.begin(), i));
		if (is_safe(data))
			return true;
		data.insert(std::next(data.begin(), i), tmp);
	}

	return false;
}

int main(int argc, char** argv)
{
	std::ifstream fin{};
	if (argc > 1)
		fin.open(argv[1]);

	std::istream &in = fin.is_open() ? fin : std::cin;

	long result{0};

	std::string line;
	while (std::getline(in, line)) {
		std::stringstream ss{line};
		std::vector<int> line_data{};

		int value;
		while (ss >> value)
			line_data.push_back(value);

		if (is_almost_safe(line_data))
			result++;
	}

	std::cout << result << "\n";

	return 0;
}
