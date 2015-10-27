/*
 * rotate2d.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: labuser
 */

/*
 *
 */

void rotate2d(vector<vector<int> > &arr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = arr.size();
	int s = 0;
	int e = (n-1)/2;

	for(;s<=e;s++)
	{
		for(int index = s;index<n-1-s;index++)
		{
			int temp = arr[index][n-1-s];
			arr[index][n-1-s] = arr[s][index];
			int temp2 = arr[n-1-s][n-1-index];
			arr[n-1-s][n-1-index] = temp;
			temp = temp2;
			temp2 = arr[n-1-index][s];
			arr[n-1-index][s] = temp;
			temp = temp2;
			arr[s][index] = temp;
		}
	}
}
