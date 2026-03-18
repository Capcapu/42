/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:07:30 by csolari           #+#    #+#             */
/*   Updated: 2026/03/18 17:31:20 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &cpy)
{
	*this = cpy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		_dequeData = src._dequeData;
		_vectorData = src._vectorData;
	}
	return *this;
}

//------------------------------------------------------------------------------

bool	isValidNumber(std::string const &s)
{
	if (s.empty())
		return false;
	for (size_t i = 0 ; i < s.size() ; i++)
	{
		if (!isdigit(s[i]))
			return false;
	}
	char *endptr;
	long l = strtol(s.c_str(), &endptr, 10);
	if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
		return false;
	return true;
}

void	PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
		throw ErrorException("Error : No argument provided");
	for (int i = 1; i < argc; i++)
	{
		if (!isValidNumber(argv[i]))
			throw ErrorException("Error : Invalid number " + std::string(argv[i]));
		int num = atoi(argv[i]);
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
	
	std::vector<int> tempSorted(_vectorData);
	std::sort(tempSorted.begin(), tempSorted.end());
	for (size_t i = 1 ; i < tempSorted.size() ; i++)
	{
		if (tempSorted[i] == tempSorted[i - 1])
			throw ErrorException("Error : Doublons are not accepted");
	}
}


//------------------------------------------------------------------------------

bool	PmergeMe::isSortedVector(const std::vector<int> &vec)
{
	for (size_t i = 1 ; i < vec.size() ; i++)
	{
		if (vec[i] < vec[i - 1])
			return false;
	}
	return true;
}

void	binaryInsertionVector(std::vector<int> &vec, int number, size_t index)
{
	size_t upperBound = index;
	if (upperBound > vec.size())
		upperBound = vec.size();
	size_t left = 0;
	size_t right = upperBound;
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (vec[mid] < number)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, number);
}

std::vector<size_t> jacobsthalNumbersVector(size_t n)
{
	std::vector<size_t> jacobsthal;
	size_t a = 0;
	size_t b = 1;
	jacobsthal.push_back(a);
	if (n == 0)
		return jacobsthal;
	jacobsthal.push_back(b);
	if (n == 1)
		return jacobsthal;
	while (1)
	{
		size_t next = b + 2 * a;
		jacobsthal.push_back(next);
		if (next > n)
			break;
		a = b;
		b = next;
	}
	return jacobsthal;
}

std::vector<int>	fordJohnsonSortVector(std::vector<int> const &input)
{
	//Si le tableau est vide ou contient un seul élément, il est deja trie
	if (input.size() <= 1)
		return input;

	//cas de base explicite pour 2 éléments, evite pb sur la recursion
	if (input.size() == 2)
	{
		std::vector<int> result;
		if (input[0] <= input[1])
			return input;
		result.push_back(input[1]);
		result.push_back(input[0]);
		return result;
	}

	//PAIRWISE COMPARISON
		//cree tableau de pairs (a_i, b_i) avec a_i >= b_i, et un élément isolé si nombre impair d'éléments
	bool impair = ((input.size() % 2 == 1) ? 1 : 0);
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0 ; i + 1 < input.size() ; i += 2)
	{
		int first = input[i];
		int sec = input[i + 1];
		if (first > sec)
			pairs.push_back(std::make_pair(first, sec));
		else
			pairs.push_back(std::make_pair(sec, first));
	}

	int lonely = 0;
	if (impair)
		lonely = input.back();

	//RECURSIVE SORTING
		//on trie récursivement les max a_i de chaque paire
	std::vector<int> maxima;
	for (size_t i = 0 ; i < pairs.size() ; i++)
		maxima.push_back(pairs[i].first);

	std::vector<int> sortedMaxima = fordJohnsonSortVector(maxima);

		//on reconstruit les paires selon l'ordre des maxima triés
	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t i = 0 ; i < sortedMaxima.size() ; i++)
	{
		for (size_t j = 0 ; j < pairs.size() ; j++)
		{
			if (pairs[j].first == sortedMaxima[i])
			{
				sortedPairs.push_back(pairs[j]);
				break ;
			}
		}
	}

		//on push les plus grands de chaque paire dans le tableau final
	std::vector<int> finalSorted(sortedMaxima);

		//on insère le plus petit de la première paire dans le tableau final
	if (!sortedPairs.empty())
		finalSorted.insert(finalSorted.begin(), sortedPairs[0].second);

		//on insère les plus petits restants selon l'ordre Jacobsthal
	std::vector<size_t> jacobsthal = jacobsthalNumbersVector(sortedPairs.size());
	for (size_t i = 2 ; i < jacobsthal.size() ; i++)
	{
		for (size_t j = jacobsthal[i] ; j > jacobsthal[i - 1] ; j--)
		{
			if (j <= sortedPairs.size())
			{
				int ai = sortedPairs[j - 1].first;
				// lower_bound donne la position de a_i, borne superieure de b_i
				std::vector<int>::iterator itA = std::lower_bound(finalSorted.begin(), finalSorted.end(), ai);
				size_t indexA = static_cast<size_t>(itA - finalSorted.begin());
				binaryInsertionVector(finalSorted, sortedPairs[j - 1].second, indexA);
			}
		}
	}

	//si nombre impair d'éléments, on insère l'element isole
	if (impair)
		binaryInsertionVector(finalSorted, lonely, finalSorted.size());

	return finalSorted;
}

void	PmergeMe::execSortVector(void)
{
	//Si le tableau est vide ou contient un seul élément, il est déjà trié
	if (_vectorData.size() <= 1)
		return ;
	_vectorData = fordJohnsonSortVector(_vectorData);
}


//------------------------------------------------------------------------------

bool	PmergeMe::isSortedDeque(const std::deque<int> &deq)
{
	for (size_t i = 1 ; i < deq.size() ; i++)
	{
		if (deq[i] < deq[i - 1])
			return false;
	}
	return true;
}

void	binaryInsertionDeque(std::deque<int> &deq, int number, size_t index)
{
	size_t upperBound = index;
	if (upperBound > deq.size())
		upperBound = deq.size();
	size_t left = 0;
	size_t right = upperBound;
	while (left < right)
	{		
		size_t mid = left + (right - left) / 2;
		if (deq[mid] < number)
			left = mid + 1;
		else
			right = mid;
	}
	deq.insert(deq.begin() + left, number);
}

std::deque<size_t> jacobsthalNumbersDeque(size_t n)
{
	std::deque<size_t> jacobsthal;
	size_t a = 0;
	size_t b = 1;
	jacobsthal.push_back(a);
	if (n == 0)
		return jacobsthal;
	jacobsthal.push_back(b);
	if (n == 1)
		return jacobsthal;
	while (1)
	{
		size_t next = b + 2 * a;
		jacobsthal.push_back(next);
		if (next > n)
			break;
		a = b;
		b = next;
	}
	return jacobsthal;
}

std::deque<int>	fordJohnsonSortDeque(std::deque<int> const &input)
{
	if (input.size() <= 1)
		return input;

	//PAIRWISE COMPARISON
	if (input.size() == 2)
	{
		std::deque<int> result;
		if (input[0] <= input[1])
			return input;
		result.push_back(input[1]);
		result.push_back(input[0]);
		return result;
	}

	bool impair = ((input.size() % 2 == 1) ? 1 : 0);
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0 ; i + 1 < input.size() ; i += 2)
	{
		int first = input[i];
		int sec = input[i + 1];
		if (first > sec)
			pairs.push_back(std::make_pair(first, sec));
		else
			pairs.push_back(std::make_pair(sec, first));
	}

	int lonely = 0;
	if (impair)
		lonely = input.back();

	//RECURSIVE SORTING
	std::deque<int> maxima;
	for (size_t i = 0 ; i < pairs.size() ; i++)
		maxima.push_back(pairs[i].first);

	std::deque<int> sortedMaxima = fordJohnsonSortDeque(maxima);

	std::deque<std::pair<int, int> > sortedPairs;
	for (size_t i = 0 ; i < sortedMaxima.size() ; i++)
	{
		for (size_t j = 0 ; j < pairs.size() ; j++)
		{
			if (pairs[j].first == sortedMaxima[i])
			{
				sortedPairs.push_back(pairs[j]);
				break ;
			}
		}
	}

	std::deque<int> finalSorted(sortedMaxima);
	if (!sortedPairs.empty())
		finalSorted.insert(finalSorted.begin(), sortedPairs[0].second);

	std::deque<size_t> jacobsthal = jacobsthalNumbersDeque(sortedPairs.size());
	for (size_t i = 2 ; i < jacobsthal.size() ; i++)
	{
		for (size_t j = jacobsthal[i] ; j > jacobsthal[i - 1] ; j--)
		{
			if (j <= sortedPairs.size())
			{
				int ai = sortedPairs[j - 1].first;
				std::deque<int>::iterator itA = std::lower_bound(finalSorted.begin(), finalSorted.end(), ai);
				size_t indexA = static_cast<size_t>(itA - finalSorted.begin());
				binaryInsertionDeque(finalSorted, sortedPairs[j - 1].second, indexA);
			}
		}
	}

	if (impair)
		binaryInsertionDeque(finalSorted, lonely, finalSorted.size());

	return finalSorted;
}

void	PmergeMe::execSortDeque(void)
{
	if (_dequeData.size() <= 1)
		return ;
	_dequeData = fordJohnsonSortDeque(_dequeData);

}

//------------------------------------------------------------------------------

size_t	PmergeMe::getVectorSize(void) const
{
	return _vectorData.size();
}

size_t	PmergeMe::getDequeSize(void) const
{
	return _dequeData.size();
}

void	PmergeMe::printVector(void)
{
	for (size_t i = 0 ; i < _vectorData.size() ; i++)
		std::cout << _vectorData[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printDeque(void)
{
	for (size_t i = 0 ; i < _dequeData.size() ; i++)
		std::cout << _dequeData[i] << " ";
	std::cout << std::endl;
}

double	PmergeMe::getTime(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec);
}

//------------------------------------------------------------------------------

PmergeMe::ErrorException::ErrorException() : _message("Error") {}

PmergeMe::ErrorException::ErrorException(std::string const &detail)
    : _message("Error: " + detail) {}

PmergeMe::ErrorException::~ErrorException() throw() {}

const char* PmergeMe::ErrorException::what() const throw()
{
    return _message.c_str();
}
