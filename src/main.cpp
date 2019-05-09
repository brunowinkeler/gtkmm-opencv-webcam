// STD includes
#include <iostream>
#include <mutex>

// gtkmm Includes
#include <gtkmm/builder.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>

// opencv Includes
#include <opencv2/opencv.hpp>


void on_button_clicked(Gtk::Window * wind);

int main(int argc, char **argv)
{
    cv::Mat frame;

    frame = cv::imread("../resources/imgs/lena.png", cv::IMREAD_COLOR);
    cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example", frame);
    cv::waitKey(0);
    cv::destroyWindow("Example");

    std::mutex mut;

    Gtk::Window *window = nullptr;
    Gtk::Button *buttonClose = nullptr;

    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    const char *glade_filepath = "../resources/glade/glade-example.glade";
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(glade_filepath);

    builder->get_widget("window1", window);
    builder->get_widget("button1", buttonClose);

    buttonClose->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_button_clicked), window));

    return app->run(*window);
}

void on_button_clicked(Gtk::Window * wind)
{
    wind->close();
}