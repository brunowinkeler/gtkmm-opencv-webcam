// STD includes

// gtkmm Includes
#include <gtkmm.h>

// opencv Includes
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    cv::Mat frame;

    frame = cv::imread("../resources/lena.png", cv::IMREAD_COLOR);
    cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example", frame);
    cv::waitKey(0);
    cv::destroyWindow("Example");

    auto app =
        Gtk::Application::create(argc, argv,
                                 "org.gtkmm.examples.base");

    Gtk::Window window;
    window.set_default_size(200, 200);

    return app->run(window);
}