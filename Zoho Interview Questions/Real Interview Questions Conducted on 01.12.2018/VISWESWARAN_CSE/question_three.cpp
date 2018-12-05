// SWAMI KARUPPASWAMI THUNNAI


#include<iostream>
#include<string>
#include<map>

class replacer
{
private:
	std::string sentence_one;
	std::string sentence_two;
	std::map<unsigned int, std::string> sentence_one_tokens;
	std::map<unsigned int, std::string> sentence_two_tokens;
	std::map<unsigned int, std::string> replaced_tokens;
	unsigned int sentence_one_tokens_count;
	unsigned int sentence_two_tokens_count;
public:
	replacer(std::string sentence_one, std::string sentence_two);
	void tokenize();
	void replace_tokens();
	void display();
	void display_replaced_sentence();
};

replacer::replacer(std::string sentence_one, std::string sentence_two)
{
	this->sentence_one = sentence_one;
	this->sentence_two = sentence_two;
}

void replacer::tokenize()
{
	unsigned int token_index = 0;
	std::string place_holder = "";
	for (char ch : this->sentence_one)
	{
		if (ch == ' ' && place_holder.size() > 0)
		{
			sentence_one_tokens[token_index] = place_holder;
			token_index++;
			place_holder = "";
		}
		else
		{
			place_holder += ch;
		}
	}
	if (place_holder.size() > 0)
	{
		sentence_one_tokens[token_index] = place_holder;
		token_index++;
		place_holder = "";
	}
	// Reset the token index and place holder
	token_index = 0;
	place_holder = "";
	for (char ch : this->sentence_two)
	{
		if (ch == ' ' && place_holder.size() > 0)
		{
			sentence_two_tokens[token_index] = place_holder;
			token_index++;
			place_holder = "";
		}
		else
		{
			place_holder += ch;
		}
	}
	if (place_holder.size() > 0)
	{
		sentence_two_tokens[token_index] = place_holder;
		token_index++;
		place_holder = "";
	}
	this->sentence_one_tokens_count = sentence_one_tokens.size();
	this->sentence_two_tokens_count = sentence_two_tokens.size();
	std::cout << "word has been tokenized successfully...\n";
	std::cout << "Tokens present in sentence one: " << this->sentence_one_tokens_count << "\n";
	std::cout << "Tokens present in sentence two: " << this->sentence_two_tokens_count << "\n";
}

void replacer::replace_tokens()
{
	std::map<unsigned int, std::string>::iterator itr1 = sentence_one_tokens.begin();
	std::map<unsigned int, std::string>::iterator itr2 = sentence_one_tokens.end();
	for (std::map<unsigned int, std::string>::iterator itr = itr1; itr != itr2; ++itr)
	{
		unsigned int key = itr->first;
		if (sentence_two_tokens.find(key) != sentence_two_tokens.end())
		{
			if (sentence_one_tokens[key] == sentence_two_tokens[key]) {
				replaced_tokens[key] = itr->second;
			}
		}
	}
}

void replacer::display()
{
	// Display the first sentence
	std::map<unsigned int, std::string>::iterator itr1 = sentence_one_tokens.begin();
	std::map<unsigned int, std::string>::iterator itr2 = sentence_one_tokens.end();
	for (std::map<unsigned int, std::string>::iterator itr = itr1; itr != itr2; ++itr)
	{
		unsigned int key = itr->first;
		if ((this->replaced_tokens.find(key) == this->replaced_tokens.end()) && (sentence_one_tokens.find(key) != sentence_one_tokens.end())) std::cout << itr->second << " ";
	}
	std::cout << "\n";
	// Display the second sentence
	std::map<unsigned int, std::string>::iterator itr3 = sentence_two_tokens.begin();
	std::map<unsigned int, std::string>::iterator itr4 = sentence_two_tokens.end();
	for (std::map<unsigned int, std::string>::iterator itr = itr3; itr != itr4; ++itr)
	{
		unsigned int key = itr->first;
		if ((this->replaced_tokens.find(key) == this->replaced_tokens.end()) && (sentence_two_tokens.find(key) != sentence_two_tokens.end())) std::cout << itr->second << " ";
	}
	std::cout << "\n";
	this->display_replaced_sentence();
}

void replacer::display_replaced_sentence()
{
	std::cout << "Replaced Sentence: ";
	std::map<unsigned int, std::string>::iterator itr1 = replaced_tokens.begin();
	std::map<unsigned int, std::string>::iterator itr2 = replaced_tokens.end();
	for (std::map<unsigned int, std::string>::iterator itr = itr1; itr != itr2; ++itr)
	{
		std::cout << itr->second << " ";
	}
}

int main()
{
	std::string sentence_one;
	std::string sentence_two;
	std::cout << "Sentence one: ";
	std::getline(std::cin, sentence_one);
	std::cout << "Sentence two: ";
	std::getline(std::cin, sentence_two);
	replacer replace(sentence_one, sentence_two);
	replace.tokenize(); // Generate the tokens
	replace.replace_tokens();
	replace.display();
	int a;
	std::cin >> a;
}
