#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main() {
    Mat bgs[9];
    Mat icos[5];
    Mat rnums[9];
    Mat bnums[9];
    Mat cards[32];
	Mat overlay;
	Mat alpha_icos;

    // Load background images
    for (int i = 1; i < 9; i++) {
        bgs[i] = imread("images/bgs/" + to_string(i) + ".png", IMREAD_UNCHANGED);
    }

    // Load overlay images
    for (int i = 1; i < 5; i++) {
        icos[i] = imread("images/icos/" + to_string(i) + ".png", IMREAD_UNCHANGED);
    }

    for (int i = 1; i < 9; i++) {
        rnums[i] = imread("images/rnums/" + to_string(i) + ".png", IMREAD_UNCHANGED);
        bnums[i] = imread("images/bnums/" + to_string(i) + ".png", IMREAD_UNCHANGED);
    }

    // Overlay each background with corresponding overlay images
    for (int elisus = 1; elisus < 9; elisus++) {
        for (int i = 1; i < 5; i++) {
            if (i < 3) {
                overlay = icos[i].clone();
                alpha_icos = overlay.clone();
                vector<Mat> channels_icos;
                split(alpha_icos, channels_icos);
                alpha_icos = channels_icos[3];

                // Copy only non-transparent pixels from overlay to background
                overlay.copyTo(bgs[elisus](Rect(0, 0, overlay.cols, overlay.rows)), alpha_icos);

                Mat overlay_rnums = rnums[elisus].clone();
                Mat alpha_rnums = overlay_rnums.clone();
                vector<Mat> channels_rnums;
                split(alpha_rnums, channels_rnums);
                alpha_rnums = channels_rnums[3];

                // Copy only non-transparent pixels from overlay to background
                overlay_rnums.copyTo(bgs[elisus](Rect(0, 0, overlay_rnums.cols, overlay_rnums.rows)), alpha_rnums);

                imwrite("Output/Card_" + to_string(i) + "-" + to_string(elisus) + ".png", bgs[elisus]);
				for (int i = 1; i < 9; i++) {
       				bgs[i] = imread("images/bgs/" + to_string(i) + ".png", IMREAD_UNCHANGED);
    			}
            } else {
                overlay = icos[i].clone();
                alpha_icos = overlay.clone();
                vector<Mat> channels_icos;
                split(alpha_icos, channels_icos);
                alpha_icos = channels_icos[3];

                // Copy only non-transparent pixels from overlay to background
                overlay.copyTo(bgs[elisus](Rect(0, 0, overlay.cols, overlay.rows)), alpha_icos);

                Mat overlay_bnums = bnums[elisus].clone();
                Mat alpha_bnums = overlay_bnums.clone();
                vector<Mat> channels_bnums;
                split(alpha_bnums, channels_bnums);
                alpha_bnums = channels_bnums[3];

                // Copy only non-transparent pixels from overlay to background
                overlay_bnums.copyTo(bgs[elisus](Rect(0, 0, overlay_bnums.cols, overlay_bnums.rows)), alpha_bnums);

                imwrite("Output/Card_" + to_string(i) + "-" + to_string(elisus) + ".png", bgs[elisus]);
				for (int i = 1; i < 9; i++) {
       				bgs[i] = imread("images/bgs/" + to_string(i) + ".png", IMREAD_UNCHANGED);
   				}
            }
        }
    }

    return 0;
}
