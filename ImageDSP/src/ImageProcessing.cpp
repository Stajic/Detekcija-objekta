
#include "ImageProcessing.h"
#include "ColorSpaces.h"
#include "Augmentations.h"

#include <QDebug>

void imageProcessingFun(
	const QString& prog_name,
	QImage& out_img,
	const QImage& in_img,
	const QVector<double>& params
) {
	int x_size = in_img.width();
	int y_size = in_img.height();

	if(prog_name == "Augmentation 0"){
		// Create empty output image.
		out_img = QImage(x_size, y_size, in_img.format());
		
		// Create buffers for YUV image.
		uchar* Y_buff = new uchar[x_size*in_img.height()];
		char* U_buff = new char[x_size*in_img.height()/4];
		char* V_buff = new char[x_size*in_img.height()/4];

		// Convert input image to YUV420 image.
		RGBtoYUV420(in_img.bits(), x_size, y_size, Y_buff, U_buff, V_buff);

//		myAugmentation0(Y_buff, x_size, y_size);
		
		// Zero out U and V component.
		procesing_YUV420(Y_buff, U_buff, V_buff, x_size, y_size, 1, 1, 1);

		// Convert YUV image back to RGB.
		YUV420toRGB(Y_buff, U_buff, V_buff, x_size, y_size, out_img.bits());

		// Delete used memory buffers.
		delete[] Y_buff;
		delete[] U_buff;
		delete[] V_buff;
	}else if(prog_name == "Augmentation 1"){
		uchar threshold = params[0];
		float compress = params[1];
		out_img = in_img;

        //myAugmentation1(out_img.bits(), x_size, y_size, threshold, compress);

        /*float dct_ratio = params[0]; // ratio of coefficients to keep in the DCT
                int block_size = params[1]; // size of the DCT blocks
                int block_overlap = params[2]; // overlap between the DCT blocks

                // Convert input image to grayscale.
                QImage gray_img = in_img.convertToFormat(QImage::Format_Grayscale8);

                // Create output image.
                out_img = QImage(x_size, y_size, in_img.format());

                // Apply DCT lowpass compression to the grayscale image.
                applyDCTLowpassCompression(gray_img.bits(), x_size, y_size, dct_ratio, block_size, block_overlap);

                // Convert grayscale image back to RGB.
                QImage temp_img = gray_img.convertToFormat(QImage::Format_RGB888);
                memcpy(out_img.bits(), temp_img.bits(), out_img.byteCount());
                */
	}

}
