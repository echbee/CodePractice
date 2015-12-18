/*
 * ZigZag.cpp
 *
 *  Created on: Oct 27, 2015
 *      Author: labuser
 *      http://community.topcoder.com/tc?module=ProblemDetail&rd=4493&pm=1259
 */

#include "../headers/MainHeader.h"


	int ZigZag::longestZigZag(vector <int> sequence)
	{
		if(sequence.size()==0)
			return 0;

		if(sequence.size()==1)
			return 1;

		vector<int> buffer(sequence.size(),1);
		vector<int> posinega(sequence.size(),0);

		for(int i=1;i<sequence.size();i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(j==0 && sequence[i]!=sequence[j] && buffer[i]<buffer[j]+1) // 1st element
				{
					buffer[i] = buffer[j] + 1;
					posinega[i] = ((sequence[i]-sequence[j])>0) ? 1 : -1;
				}
				else
				{
					if(sequence[i]>sequence[j] && posinega[j]==-1 && buffer[i]<buffer[j]+1)
					{
						buffer[i] = buffer[j] + 1;
						posinega[i] = 1;
					}
					else if(sequence[i]<sequence[j] && posinega[j]==1 && buffer[i]<buffer[j]+1)
					{
						buffer[i] = buffer[j] + 1;
						posinega[i] = -1;
					}
				}
			}
		}

		int ans = 1;

		for(int i=0;i<buffer.size();i++)
		{
			if(buffer[i]>ans)
				ans = buffer[i];
		}
		return ans;
	}
