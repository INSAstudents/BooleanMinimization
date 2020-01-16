#pragma once

#include "print.h"

template <typename type>
using termsprobs_t = std::vector<std::pair<typename type::pair, float>>;

inline void swaphalves(with16bits::byte& word)
{
	with8bits::pair halves;
	halves.bytes = word;

	with8bits::byte temp = halves.first;
	halves.first = halves.second;
	halves.second = temp;

	word = halves.bytes;
}

template <typename type>
void import_CPLEX(std::istream& in, termsprobs_t<type>& table)
{
	typename type::pair tuple;

	char c;
	while (in.get(c)) // '\n'
	{
		unprint_bin_star<type>(in, tuple.first, tuple.second);
		//swaphalves(tuple.first); swaphalves(tuple.second);
		in.get(c); // ' '

		float prob;
		in >> prob;

		table.push_back(std::make_pair(tuple, prob));
	}
}
