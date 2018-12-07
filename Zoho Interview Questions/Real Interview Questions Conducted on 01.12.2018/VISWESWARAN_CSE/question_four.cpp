// SWAMI KARUPPASWAMI THUNNAI

#include<iostream>
#include<string>
#include<set>
#include<map>

class sorter
{
private:
	std::multiset<int> sorted_elements;
	std::map<int, unsigned int> sorted_elements_with_count;
public:
	void add(int element);
	void add_counts();
	void display();
};

void sorter::add(int element)
{
	sorted_elements.insert(element);
}

void sorter::add_counts()
{
	std::multiset<int>::iterator itr1 = sorted_elements.begin();
	std::multiset<int>::iterator itr2 = sorted_elements.end();
	for (std::multiset<int>::iterator itr = itr1; itr != itr2; ++itr)
	{
		if (sorted_elements_with_count.find(*itr) == sorted_elements_with_count.end())
		{
			sorted_elements_with_count[*itr] = 1;
		}
		else
		{
			sorted_elements_with_count[*itr] += 1;
		}
	}
}

void sorter::display()
{
	std::multiset<unsigned int> arrangements;
	std::set<int> already_displayed;
	std::map<int, unsigned int>::iterator itr1 = sorted_elements_with_count.begin();
	std::map<int, unsigned int>::iterator itr2 = sorted_elements_with_count.end();
	for (std::map<int, unsigned int>::iterator itr = itr1; itr != itr2; ++itr)
	{
		arrangements.insert(itr->second);
	}
	for (std::multiset<unsigned int>::reverse_iterator itr = arrangements.rbegin(); itr != arrangements.rend(); ++itr)
	{
		for (std::map<int, unsigned int>::iterator map_itr = sorted_elements_with_count.begin(); map_itr != sorted_elements_with_count.end(); ++map_itr)
		{
			if ((map_itr->second == *itr) && (already_displayed.find(map_itr->first) == already_displayed.end()))
			{
				already_displayed.insert(map_itr->first);
				for (int i = 0; i < *itr; i++) {
					std::cout << map_itr->first << ", ";
				}
			}
		}
	}
}

int main()
{
	std::cout << "How many elements: ";
	int count;
	sorter sort;
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		std::cout << "element " << i + 1 << ": ";
		int element;
		std::cin >> element;
		sort.add(element);
	}
	sort.add_counts();
	sort.display();
	std::cin >> count;
}