#if !defined(CAMERA_WINDOW_H)
#define CAMERA_WINDOW_H

//STD
#include <mutex>
#include <thread>

//3rdParty
#include <opencv2/opencv.hpp>
#include <gtkmm.h>

//Local
#include "acquisition/camera_widget.h"

class CameraWindow: public Gtk::Window
{
public:
    CameraWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
    ~CameraWindow();

private:

    //Private Slots
    void on_btStartPauseClicked();
    void on_btStopClicked();
    void on_btCloseClicked();
    void on_btPicClicked();

    //Private Attributes
    Glib::RefPtr<Gtk::Builder> m_builder;
	Gtk::Button * m_startPauseButton;
	Gtk::Button * m_stopButton;
	Gtk::Button * m_closeButton;
	Gtk::Button * m_takePicButton;
	acquisition::CameraWidget * m_cameraImage;
};

#endif // CAMERA_WINDOW_H
