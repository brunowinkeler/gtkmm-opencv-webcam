#include "camera_window.h"

CameraWindow::CameraWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
    Gtk::Window(cobject), 
    m_builder(refGlade)
{
    this->set_size_request(640,480);
    //this->set_default_size(800,600);
    //this->resize(1280,720);

    this->m_builder->get_widget("btStartPause", this->m_startPauseButton);
    this->m_builder->get_widget("btStop", this->m_stopButton);
    this->m_builder->get_widget("btClose", this->m_closeButton);
    this->m_builder->get_widget("btPic", this->m_takePicButton);
    this->m_builder->get_widget_derived("camImage", this->m_cameraImage);

    this->m_startPauseButton->signal_clicked().connect(sigc::mem_fun(*this, &CameraWindow::on_btStartPauseClicked));
    this->m_stopButton->signal_clicked().connect(sigc::mem_fun(*this, &CameraWindow::on_btStopClicked));
    this->m_closeButton->signal_clicked().connect(sigc::mem_fun(*this, &CameraWindow::on_btCloseClicked));
	this->m_takePicButton->signal_clicked().connect(sigc::mem_fun(*this, &CameraWindow::on_btPicClicked));
}

CameraWindow::~CameraWindow()
{
}

void CameraWindow::on_btStartPauseClicked()
{
    m_cameraImage->startCamera();
}

void CameraWindow::on_btStopClicked()
{
    m_cameraImage->stopCamera();
}

void CameraWindow::on_btCloseClicked()
{
    this->close();
}

void CameraWindow::on_btPicClicked()
{
    m_cameraImage->takePicture();
}