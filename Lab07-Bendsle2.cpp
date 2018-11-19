// Lab07-Bendsle2.cpp
// Brandon Endsley

#include "Lab07-Bendsle2.h"
#include "winTimer.h"
#include <iostream>

using std::cout;

int main()
{
	vector<double> calc;
	calc = getNums(62000, 1, 500);
	Timer time;


	time.start();
	calc = mergeSort(calc);
	time.stop();
	cout << "\n\n";
	

	cout << "\nMergesort: " << time() << " seconds\n";

	/*
	for (int i = 0; i < calc.size(); i++)
	{
		cout << calc.at(i) << "\n";
	}
	

	cout << "\n";
	
	time.start();
	calc = bubble(calc);
	time.stop();

	cout << "\nBubble sort: " << time() << " seconds\n";

	

	calc = getNums(2600000, 1, 500);

	time.start();
	sort(begin(calc),end(calc));
	time.stop();

	cout << "\nstd::sort: " << time() << " seconds\n";


	cout << "\n";

	time.start();
	calc = quickSort(calc);
	time.stop();
	cout << "\n\n";

	cout << "\nQuciksort: " << time() << " seconds\n";


	time.start();
	calc = insertion(calc);
	time.stop();
	cout << "\n\n";

	cout << "\nInsertion: " << time() << " seconds\n";
	*/

	system("pause");
	return 0;
}