// SortPVector.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include <iomanip>  

#define IN
#define OUT

using namespace std;
typedef pair<int, int> pairTypedef;
typedef vector< pairTypedef > vectorTypedef;

void DisplayVector(IN string SortingMethod, IN vectorTypedef IN_SortedVector)
{
	cout << "==================================" << SortingMethod.c_str() << endl;
	for (unsigned int i = 0; i < IN_SortedVector.size(); i++)
	{
		cout << "(" << setw(2) << IN_SortedVector[i].first  << "," 
			 <<        setw(2) << IN_SortedVector[i].second << " )" << endl;
	}
}

//============= Main Function
//============= 00. TEST Case : Ordered by firstValue  (��������)
//============= 01. TEST Case : Ordered by secondValue (��������)
//============= 02. TEST Case : Ordered by calValue    (��������)
int _tmain(int argc, _TCHAR* argv[])
{
	//============= Making Input data
	vectorTypedef vectInput;
	const int nPairCNT = 5;
	{
		vectInput.push_back( IN make_pair(1, 10) );
		vectInput.push_back( IN make_pair(2, 9)  );
		vectInput.push_back( IN make_pair(3, 8)  );
		vectInput.push_back( IN make_pair(4, 7)  );
		vectInput.push_back( IN make_pair(5, 6)  );
	}

	//============= 00. TEST Case : Ordered by firstValue  (��������)
	sort(IN vectInput.begin(), IN vectInput.end(), IN[](const pairTypedef &left, const pairTypedef &right)->bool{
															  bool bResult = false;
															  if (left.first > right.first)
																   bResult = true;
															  else if (left.first == right.first)
																   bResult = (left.second > right.second);
															  else
																   bResult = false;

															  return bResult;
														 });
	DisplayVector(IN "Ordered by firstValue (DES)",IN vectInput);

	//============= 01. TEST Case : Ordered by secondValue (��������)
	sort( IN vectInput.begin(), IN vectInput.end(), IN [](const pairTypedef &left, const pairTypedef &right)->bool{
																bool bResult = false;
																if (left.second > right.second)
																	bResult = true;
																else if (left.second == right.second)
																	bResult = (left.first > right.first);
																else
																	bResult = false;

																return bResult;
														 });

	DisplayVector(IN "Ordered by secondValue (DES)", IN vectInput);

	//============= 02. TEST Case : Ordered by calValue    (��������)
	//============= �����Լ��� ���� ���ڷ� �־ ��갪�� �������� �������� ����
	sort(IN vectInput.begin(), IN vectInput.end(), IN[](const pairTypedef &left, const pairTypedef &right)->bool{
															  double fleftCal  = (pow(left.first, 2) * 2) +  (pow(left.second, 2));
															  double fRightCal = (pow(right.first, 2) * 2) + (pow(right.second, 2));
															  return fleftCal < fRightCal;
														});
	DisplayVector(IN "Ordered by calValue (first^2 * 2 + second^2�� ���� ASC)", IN vectInput);

	return 0;
}

