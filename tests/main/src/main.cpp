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

void on_button_clicked(Gtk::Window * wind);
void thread_camera();

int main(int argc, char **argv)
{
    std::thread t(thread_camera);

    cv::Mat frame;
    
    Gtk::Window *window = nullptr;
    Gtk::Button *buttonClose = nullptr;
    acquisition::CameraWidget * camera = nullptr;

    //cv::VideoCapture cap(0);
    //cap >> frame;
    std::string path_resources = PATH_RESOURCES;
    frame = cv::imread(path_resources + "imgs/lena.png", cv::IMREAD_COLOR);
    cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example", frame);
    cv::waitKey(0);
    cv::destroyWindow("Example");

    std::mutex mut;

    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(path_resources + "glade/glade-example.glade");

    builder->get_widget("mainWindow", window);
    builder->get_widget("btClose", buttonClose);
    builder->get_widget_derived("drwArea", camera); 

    window->set_size_request(640,480);
    //window->set_default_size(800,600);
    //window->resize(1280,720);
    buttonClose->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_button_clicked), window));

    t.join();
    return app->run(*window);
}

void on_button_clicked(Gtk::Window * wind)
{
    wind->close();
}

void thread_camera()
{
    acquisition::CameraHandler cam;
}