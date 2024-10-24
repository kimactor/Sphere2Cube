// Sphere2Cube.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <chrono>
#include "../../src/sphere2cube.h"

int main(int argc, char** argv) {
    Sphere2Cube s2c(1920);
    const std::string video_path = "./data/test_1.mp4";
    cv::VideoCapture cap(video_path);
    
    cv::Mat frame;
    while (cap.isOpened())
    {
        cap >> frame;
        //cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
        Faces cube;

        auto t1 = std::chrono::steady_clock::now();
        s2c.transform(frame, cube);
        auto t2 = std::chrono::steady_clock::now();

        printf("Cost %f s.\n", std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count());
       
        cv::imshow("front.jpg",cube.faces[1]);
        cv::waitKey(1);


    }


   


    //cv::imwrite("up.jpg", cube.faces[0]);
    //cv::imwrite("front.jpg", cube.faces[1]);
    //cv::imwrite("right.jpg", cube.faces[2]);
    //cv::imwrite("back.jpg", cube.faces[3]);
    //cv::imwrite("left.jpg", cube.faces[4]);
    //cv::imwrite("down.jpg", cube.faces[5]);

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
