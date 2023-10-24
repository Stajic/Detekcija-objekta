#include "ImageHistogram.h"


/**
 * Simple contrast improvement
 */
void simpleContrastImp(
    const uchar input[],
    int x_size,
    int y_size,
    uchar output[]
) {
    // TODO
    uchar minPixel = 255;
    uchar maxPixel = 0;

    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            maxPixel = std::max(maxPixel, input[i + j * x_size]);
            minPixel = std::min(minPixel, input[i + j * x_size]);
        }
    }

    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            output[i + j * x_size] = (input[i + j * x_size] - minPixel) * 255 / (maxPixel - minPixel);
        }
    }
}


/**
 * Calculate image histogram
 *
void calculateHistogram(
    const uchar input[],
    int x_size,
    int y_size,
    int histogram[]
) {
    // TODO
}


**
 * Equalize image histogram
 *
void equalizeHistogram(
    const uchar input[],
    int x_size,
    int y_size,
    uchar output[],
    uchar L
) {
    // TODO
}
*/
