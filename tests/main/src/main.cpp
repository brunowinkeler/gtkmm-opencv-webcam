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
    std::string path_resources = PATH_RESOURCES;
    CameraWindow *cameraWindow = nullptr;

    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(path_resources + "glade/glade-example.glade");

    builder->get_widget_derived("mainWindow", cameraWindow);

    return app->run(*cameraWindow);
}