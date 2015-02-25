#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
bool CheckforInt(string input);

int main()
{
	vector<int> stack;
	string input = "n";
	int num, val1, val2, result;
	cout << "Welcome to RPN calculator! Enter a q to quit the program." << endl << endl;
	while (input != "q" && input != "Q")
	{
		cout << ">>";
		cin >> input;
		if(CheckforInt(input) == true)
		{
			istringstream conv(input);
			conv >> num;
			stack.push_back(num);
		}
		else if(input == "+" || input == "-" || input == "*" || input == "/")
		{
			if (input == "+" && stack.size()>=2)
			{
				val1 = stack.back();
				stack.erase(stack.begin()+stack.size()-1);
				val2 = stack.back();
				stack.erase(stack.begin()+stack.size()-1);
				result = val1 + val2;
				stack.push_back(result);
				cout << result << endl;
			}
			
			if (input == "-" && stack.size()>=2)
			{
				val1 = stack.back();
				stack.erase(stack.begin()+stack.size()-1);
				val2 = stack.back();
				stack.erase(stack.begin()+stack.size()-1);
				result = val2 - val1;
				stack.push_back(result);
				cout << result << endl;
			}
			
			if (input == "*" && stack.size()>=2)
			{
				val1 = stack.back();
				stack.erase(stack.begin()+stack.size()-1);
				val2 = stack.back();
				stack.erase(stack.begin()+stack.size()-1);
				result = val1 * val2;
				stack.push_back(result);
				cout << result << endl;
			}
			
			if (input == "/" && stack.size()>=2)
			{
				val1 = stack.back();
				stack.erase(stack.begin()+stack.size()-1);
				val2 = stack.back();
				stack.erase(stack.begin()+stack.size()-1);
				result = val2 / val1;
				stack.push_back(result);
				cout << result << endl;
			}
		}
		else if(input == "q" ||	input == "Q")
			break;
		else 
			cout << "Invalid Input!" << endl;
	}
	
	return 0;
}

bool CheckforInt(string input)
{
	istringstream ss(input);
	int x;
	if (ss >> x)
		return true;
	else 
		return false;
}