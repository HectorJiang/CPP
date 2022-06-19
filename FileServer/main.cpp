#include "cfileserver.h"

#include <QApplication>
//#include <opencv2/opencv.hpp>
#include <omp.h>

extern "C"{
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libswscale/swscale.h"
    #include "libavdevice/avdevice.h"
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    unsigned version = avcodec_version();
//    qDebug()<<"version:"<<version;
//    using namespace cv;
//    Mat image = imread("C:\\Users\\dell\\Desktop\\images.jpg");
//    imshow("image", image);
//    waitKey(0);
    CFileServer w;
    w.show();
    return a.exec();
}
