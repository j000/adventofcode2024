#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

class Context;

class IState {
	public:
		virtual ~IState() = default;
		virtual void handle(Context& context, char input) = 0;
};

namespace State
{
	class Default
		: public IState
	{
		public:
			void handle(Context& context, char input) override;
	};

	class M
		: public IState
	{
		public:
			void handle(Context& context, char input) override;
	};

	class U
		: public IState
	{
		public:
			void handle(Context& context, char input) override;
	};

	class L
		: public IState
	{
		public:
			void handle(Context& context, char input) override;
	};

	class Digit1
		: public IState
	{
		public:
			void handle(Context& context, char input) override;
	};

	class Digit2
		: public IState
	{
		public:
			void handle(Context& context, char input) override;
	};
}

class Context {
	public:
		Context()
			: m_state(std::make_unique<State::Default>())
		{
		}

		void set_state(std::unique_ptr<IState> new_state)
		{
			m_state = std::move(new_state);
		}

		int get_result() const
		{
			return m_result;
		}

		void set_result()
		{
			m_result += m_num1 * m_num2;
		}

		void reset_num1()
		{
			m_num1 = 0;
		}

		void add_num1(int x)
		{
			m_num1 = m_num1*10 + x;
		}

		void reset_num2()
		{
			m_num2 = 0;
		}

		void add_num2(int x)
		{
			m_num2 = m_num2*10 + x;
		}

		void process(char input)
		{
			m_state->handle(*this, input);
		}

	private:
		std::unique_ptr<IState> m_state;
		int m_num1{0};
		int m_num2{0};
		long m_result{0};
		bool m_enabled{true};
};

void State::Default::handle(Context& context, char input)
{
	if ('m' == input) {
		context.set_state(std::make_unique<State::M>());
	}
}

void State::M::handle(Context& context, char input)
{
	if ('u' == input) {
		context.set_state(std::make_unique<State::U>());
	} else {
		context.set_state(std::make_unique<State::Default>());
	}
}

void State::U::handle(Context& context, char input)
{
	if ('l' == input) {
		context.set_state(std::make_unique<State::L>());
	} else {
		context.set_state(std::make_unique<State::Default>());
	}
}

void State::L::handle(Context& context, char input)
{
	if ('(' == input) {
		context.reset_num1();
		context.set_state(std::make_unique<State::Digit1>());
	} else {
		context.set_state(std::make_unique<State::Default>());
	}
}

void State::Digit1::handle(Context& context, char input)
{
	if (std::isdigit(input)) {
		context.add_num1(input - '0');
	} else if (',' == input) {
		context.reset_num2();
		context.set_state(std::make_unique<State::Digit2>());
	} else {
		context.set_state(std::make_unique<State::Default>());
	}
}

void State::Digit2::handle(Context& context, char input)
{
	if (std::isdigit(input)) {
		context.add_num2(input - '0');
	} else if (')' == input) {
		context.set_result();
		context.set_state(std::make_unique<State::Default>());
	} else {
		context.set_state(std::make_unique<State::Default>());
	}
}

int main(int argc, char** argv)
{
	std::ifstream fin{};
	if (argc > 1)
		fin.open(argv[1]);

	std::istream &in = fin.is_open() ? fin : std::cin;

	Context context{};

	char c;
	while (in >> c) {
		context.process(c);
	}

	std::cout << context.get_result() << "\n";

	return 0;
}
