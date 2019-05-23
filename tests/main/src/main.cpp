// STD includes
#include <iostream>
#include <mutex>
#include <thread>

// gtkmm Includes
#include <gtkmm.h>

// opencv Includes
#include <opencv2/opencv.hpp>

#include "acquisition/camera_widget.h"
#include "acquisition/camera_handler.h"
#include "camera_window.h"

int main(int argc, char **argv)
{
    CameraWindow *cameraWindow = nullptr;

    cv::Mat frame;
    //cv::VideoCapture cap(0);
    //cap >> frame;
    std::string path_resources = PATH_RESOURCES;
    frame = cv::imread(path_resources + "imgs/lena.png", cv::IMREAD_COLOR);
    cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example", frame);
    cv::waitKey(0);
    cv::destroyWindow("Example");

    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(path_resources + "glade/glade-example.glade");

    builder->get_widget_derived("mainWindow", cameraWindow);

    cameraWindow->set_size_request(640,480);
    //cameraWindow->set_default_size(800,600);
    //cameraWindow->resize(1280,720);

    return app->run(*cameraWindow);
}