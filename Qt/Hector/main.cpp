#include "chectormainwindow.h"

#include <QApplication>
#include <opencv2/opencv.hpp>

void smooth_image(const cv::Mat &image){

}
int main(int argc, char *argv[])
{
      cv::Mat image = cv::imread("C:\\Users\\HectorJiang\\Desktop\\Image\\Wallpaper\\jing.png");
      smooth_image(image);
//    QApplication a(argc, argv);
//    CHectorMainWindow w;
//    w.show();
//    return a.exec();
}
