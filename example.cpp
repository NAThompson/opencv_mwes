#include <iostream> // for standard I/O
#include <string>   // for strings

#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>  // Video write
//#include <opencv2/videoio.hpp>
//#include <opencv2/core/mat.hpp>


void declare_matrix()
{
    int rows = 3;
    int cols = 5;
    cv::Mat m(rows, cols, CV_8UC1);
    std::cout << "We have " << m.channels() << " channel.\n";
    std::cout << "Depth = " << m.depth() << "\n";
    std::cout << "Type =" << m.type() << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.at<uchar>(i, j) = static_cast<uchar>(i+j);
        }
    }
    std::cout << m << "\n";

    {
    cv::Mat m(rows, cols, CV_8SC1);
    std::cout << "We have " << m.channels() << " channel.\n";
    std::cout << "Depth = " << m.depth() << "\n";
    std::cout << "Type =" << m.type() << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.at<char>(i, j) = static_cast<char>(i+j);
        }
    }
    std::cout << m << "\n";
    }

    {
    cv::Mat m(rows, cols, CV_16SC1);
    std::cout << "We have " << m.channels() << " channel.\n";
    std::cout << "Depth = " << m.depth() << "\n";
    std::cout << "Type =" << m.type() << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.at<int16_t>(i, j) = static_cast<int16_t>(i+j);
        }
    }
    std::cout << m << "\n";
    }


    {
    cv::Mat m(rows, cols, CV_64FC1);
    std::cout << "We have " << m.channels() << " channel.\n";
    std::cout << "Depth = " << m.depth() << "\n";
    std::cout << "Type =" << m.type() << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.at<double>(i, j) = static_cast<double>(i+j);
        }
    }
    std::cout << m << "\n";
    }

    {
    cv::Mat m(rows, cols, CV_32FC2);
    std::cout << "We have " << m.channels() << " channels.\n";
    std::cout << "Depth = " << m.depth() << "\n";
    std::cout << "Type =" << m.type() << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.at<cv::Point_<float>>(i, j) = cv::Point_<float>(i+j, i*i+j*j);
        }
    }
    std::cout << m << "\n";
    }


    {
    cv::Mat m(rows, cols, CV_8UC2);
    std::cout << "We have " << m.channels() << " channels.\n";
    std::cout << "Depth = " << m.depth() << "\n";
    std::cout << "Type =" << m.type() << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.at<cv::Point_<uchar>>(i, j) = cv::Point_<uchar>(i+j, i*i+j*j);
        }
    }
    std::cout << m << "\n";
    }

    {
    cv::Mat m(rows, cols, CV_8UC3);
    std::cout << "We have " << m.channels() << " channels.\n";
    std::cout << "Depth = " << m.depth() << "\n";
    std::cout << "Type =" << m.type() << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.at<cv::Point3_<uchar>>(i, j) = cv::Point3_<uchar>(i+j, i*i+j*j, i*i*i+j*j*j);
        }
    }
    std::cout << m << "\n";
    }


}

int main()
{
    declare_matrix();
    /*int width = 1100;
    int height = 900;
    cv::Size S = Size(width, height);
    const string filename = "output.mp4";
    int codec_code = cv::VideoWriter::fourcc('m', 'p', '4', 'v');
    std::cout << "Codec value = " << codec_code << std::hex << " = " << codec_code << "\n";
    double fps = 60;
    cv::VideoWriter outputVideo(filename, codec_code, fps, S);*/

    /*int i = 0;
    while (i++ < 2*fps) {
        outputVideo << m;
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                m.at(i,j) = i+j;
            }
        }
    }*/


    return 0;
}