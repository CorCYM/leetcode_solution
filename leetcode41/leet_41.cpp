#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

class Solution {
public:
	std::vector<int> test;
	int firstMissingPositive(std::vector<int>& nums) {
		const int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
				std::swap(nums[i], nums[nums[i] - 1]);
			}
		}

		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};

class InteractiveApp {
public:
	void run() {
		print_notice();

		std::string cmd;
		while (true) {
			std::cout << "> ";
			if (!(std::cin >> cmd)) {
				break;
			}

			if (!handle_command(cmd)) {
				break;
			}
		}

		std::cout << "Program exit.\n";
	}

private:
	std::vector<int> nums_;
	Solution sol_;

	void print_notice() const {
		static const std::vector<std::pair<std::string, std::string>> cmds = {
			{"add X", "push X into nums"},
			{"print", "print current nums"},
			{"run", "run firstMissingPositive on nums"},
			{"clear", "clear nums"},
			{"help", "show this help"},
			{"quit", "exit program"}
		};

		std::cout << "===== Commands =====\n";

		size_t width = 0;
		for (const auto& [cmd, _] :cmds) {
			width = std::max(width, cmd.size());
		}
		for (const auto& [cmd, desc] : cmds) {
			std::cout << " " << cmd;
			std::cout << std::string(width - cmd.size() + 2, ' ');
			std::cout << ": " << desc << "\n";
		}

		std::cout << "====================\n";
	}

	void print_nums(const std::vector<int>& nums){
		std::cout << "nums = [";
		for (size_t i = 0; i < nums.size(); ++i){
			std::cout << nums[i];
			if (i+1 <nums.size()){
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}

	bool handle_command(const std::string& cmd){
		if (cmd == "add") {
			int x;
			if (std::cin >> x) {
				nums_.push_back(x);
				std::cout << "Added " << x << " to nums.\n";
			} else {
				std::cout << "Invalid number. \n";
				return false;
			}
		} else if (cmd == "print") {
			print_nums(nums_);
		} else if (cmd == "run") {
			if (nums_.empty()) {
				std::cout << "nums is empty. Add some numbers first. \n";
				return true;
			}

			std::vector<int> tmp = nums_;
			int result = sol_.firstMissingPositive(tmp);
			
			std::cout << "First missing positive = " << result << "\n";
			std::cout << "after algorithm, tmp = ";
			print_nums(tmp);
		} else if (cmd == "clear"){
			nums_.clear();
			std::cout << "nums cleared. \n";
		} else if (cmd == "help") {
			print_notice();
		} else if (cmd == "quit" || cmd == "exit") {
			return false;
		} else {
			std::string rest;
			std::getline(std::cin, rest);
			std::cout << "Unknown command. Type 'help' for list. \n";
		}


		return true;
	}
};

int main() {
	InteractiveApp app;
	app.run();
	return 0;
}
