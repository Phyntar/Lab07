//Lab07-Bendsle2.h
// Brandon Endsley

#pragma once

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;


double randUniform()
{
	double r = double(rand()) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	return  r;
};


double randReal(double minReal, double maxReal)
{
	return minReal
		+ (maxReal - minReal) * randUniform();
}

vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}




// ~~~~~~~ Sorting Functions ~~~~~~~


vector<double> bubble(vector<double> in)
{
	double temp;
	
	for (int k = in.size(); k >= 0; k--)
	{
		for (int i = 0; i < k-1; i++)
		{

			if (in.at(i) > in.at(i + 1))
			{
				temp = in.at(i);
				in.at(i) = in.at(i + 1);
				in.at(i + 1) = temp;
			}
		}
	}


	return in;
}

vector<double> insertion(vector<double> in)
{
	int j;
	double temp;
	bool unsorted;
	for (int i = 1; i < in.size(); i++)
	{
		j = i - 1;
		temp = in.at(i);
		unsorted = true;
		while (unsorted)
		{

			if (temp <= in.at(j))
			{
				in.at(j+1) = in.at(j);
				if(j==0)
				{
					in.at(0) = temp;
					unsorted = false;
				}
				else
				{
					j--;
				}
			}
			else
			{
				in.at(j+1) = temp;								
				unsorted = false;
			}
		}
	}


	return in;
}

vector<double> selection(vector<double> in)
{
	double min, temp;
	int pos;
	for (int i = 0; i < in.size(); i++)
	{
		for (int j = i; j < in.size(); j++)
		{
			if (j == i)
			{
				min = in.at(j);
				pos = j;
			}
			if (min > in.at(j))
			{
				min = in.at(j);
				pos = j;
			}			
		}
		temp = in.at(i);
		in.at(i) = min;
		in.at(pos) = temp;
	}
	return in;
}

vector<double> merge(vector<double> in1, vector<double> in2)
{
	vector<double> merged;
	bool unsorted = true;
	int i=0, j=0;
	while (unsorted)
	{
		if (in1.at(i) < in2.at(j))
		{
			merged.push_back(in1.at(i));

			if (i == in1.size()-1)
			{
				for (int jj = j; jj < in2.size(); jj++)
				{
					merged.push_back(in2.at(jj));
				}
				unsorted = false;
			}
			else
			{
				i++;
			}
		}
		
		else if (in1.at(i) > in2.at(j))
		{
			merged.push_back(in2.at(j));
			
			if (j == in2.size()-1)
			{
				for (int ii = i; ii < in1.size(); ii++)
				{
					merged.push_back(in1.at(ii));
				}
				unsorted = false;
			}
			else
			{
				j++;
			}
		}
		
	}
	return merged;
}

vector<double> mergeSort(vector<double> in)
{
	if (in.size() == 1)
	{
		return in;
	}
	int middle = (in.size() + 1) / 2;
	vector<double> left, right;

	for (int i = 0; i < middle; i++) 
	{
		left.push_back(in.at(i));
	}

	for (int j = middle; j < in.size(); j++) 
	{
		right.push_back(in.at(j));
	}

	left = mergeSort(left);
	right = mergeSort(right);
	return merge(left, right);
}



vector<double> quickSort(vector<double> in)
{
	if (in.size() > 1)
	{
		vector<double> big;
		vector<double> small;
		vector<double> out;

		for (int i = 0; i < in.size()-1; i++)
		{
			if (in.at(i) > in.at(in.size() - 1))
			{
				big.push_back(in.at(i));
			}
			else
			{
				small.push_back(in.at(i));
			}
		}

		small = quickSort(small);
		big = quickSort(big);
		out.reserve(small.size() + big.size()+1);
		out.insert(out.end(), small.begin(), small.end());
		out.push_back(in.at(in.size() - 1));
		out.insert(out.end(), big.begin(), big.end());

		return out;

		
	}
	

	return in;
	
	
}