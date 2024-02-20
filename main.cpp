#include "opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	mat[8] bgs;
	
	mat[4] icos;
	
	mat[8] rnums;
	
	mat[8] bnums;
	
	result[32] cards;
	
	for(int i = 0; i < 8; i++)
	{
		bgs[i] = imread($"{i}.png");
	}
	
	for(int i = 0; i < 4; i++)
	{
		icos[i] = imread($"{i}.png");
	}
	
	for (int i = 0; i < 8; i++)
	{
		nums[i] = imread($"{i}.png");
	}

	for(i = 0; i<4; i++)
	{
		for(elisus = 0; elisus < 8; elisus++)
		{
			if(i < 3)
			{
				addWeighted(bgs[elisus], 1.0, icos[i], 1.0, cards[i * elisus]);
				addWeighted(cards[i * elisus], 1.0, rnums[elisus],1.0,card[i * elisus]);
				
				imwrite("")
			}
			else if(i > 2)
			{
				addWeighted(bgs[elisus], 1.0, icos[i], 1.0, cards[i * elisus]);
				addWeighted(cards[i * elisus], 1.0, bnums[elisus],1.0,card[i * elisus]);
			}
		}
	}	
	
}