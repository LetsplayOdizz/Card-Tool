/*#include "opencv.hpp"
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
		bgs[i] = imread("images/bgs/"+to_string(i)+".png");
	}
	
	for(int i = 0; i < 4; i++)
	{
		icos[i] = imread("images/icos/"+to_string(i)+".png");
	}
	
	for (int i = 0; i < 8; i++)
	{
		rnums[i] = imread("images/rnums/"+to_string(i)+".png");
	}
	for (int i = 0; i < 8; i++)
	{
		bnums[i] = imread("images/bnums/"+to_string(i)+".png");
	}

	for(i = 0; i<4; i++)
	{
		for(elisus = 0; elisus < 8; elisus++)
		{
			if(i < 3)
			{
				addWeighted(bgs[elisus], 1.0, icos[i], 1.0, cards[i * elisus]);
				addWeighted(cards[i * elisus], 1.0, rnums[elisus],1.0,card[i * elisus]);
				
				imwrite("Output/"+"Card_"+to_String(i)+"-"+to_string(elisus)+"_red");
			}
			else if(i > 2)
			{
				addWeighted(bgs[elisus], 1.0, icos[i], 1.0, cards[i * elisus]);
				addWeighted(cards[i * elisus], 1.0, bnums[elisus],1.0,card[i * elisus]);
				imwrite("Output/"+"Card_"+to_String(i)+"-"+to_string(elisus)+"_black");
			}
		}
	}	
	
}
*/
#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main() {
    Mat bgs[8];
    Mat icos[4];
    Mat rnums[8];
    Mat bnums[8];
    Mat cards[32];

    for (int i = 0; i < 8; i++) {
        bgs[i] = imread("images/bgs/" + to_string(i) + ".png");
    }

    for (int i = 0; i < 4; i++) {
        icos[i] = imread("images/icos/" + to_string(i) + ".png");
    }

    for (int i = 0; i < 8; i++) {
        rnums[i] = imread("images/rnums/" + to_string(i) + ".png");
        bnums[i] = imread("images/bnums/" + to_string(i) + ".png");
    }

    for (int i = 0; i < 4; i++) {
        for (int elisus = 0; elisus < 8; elisus++) {
            if (i < 3) {
                addWeighted(bgs[elisus], 1.0, icos[i], 1.0, 0.0, cards[i * 8 + elisus]);
                addWeighted(cards[i * 8 + elisus], 1.0, rnums[elisus], 1.0, 0.0, cards[i * 8 + elisus]);
                imwrite("Output/Card_" + to_string(i) + "-" + to_string(elisus) + "_red.png", cards[i * 8 + elisus]);
            } else {
                addWeighted(bgs[elisus], 1.0, icos[i], 1.0, 0.0, cards[i * 8 + elisus]);
                addWeighted(cards[i * 8 + elisus], 1.0, bnums[elisus], 1.0, 0.0, cards[i * 8 + elisus]);
                imwrite("Output/Card_" + to_string(i) + "-" + to_string(elisus) + "_black.png", cards[i * 8 + elisus]);
            }
        }
    }

    return 0;
}