#include "camera_window.h"

CameraWindow::CameraWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
    Gtk::Window(cobject), 
    m_builder(refGlade)
{
    this->m_builder->get_widget("btStartPause", this->m_startPauseButton);
    this->m_builder->get_widget("btClose", this->m_closeButton);
    this->m_builder->get_widget("btPic", this->m_takePicButton);
    this->m_builder->get_widget_derived("camImage", this->drawingImage);

    this->m_startPauseButton->signal_clicked().connect(sigc::mem_fun(*this, &CameraWindow::on_btStartPauseClicked));
    this->m_closeButton->signal_clicked().connect(sigc::mem_fun(*this, &CameraWindow::on_btCloseClicked));
	this->m_takePicButton->signal_clicked().connect(sigc::mem_fun(*this, &CameraWindow::on_btPicClicked));
}

CameraWindow::~CameraWindow()
{
}

void CameraWindow::on_btStartPauseClicked()
{
    
}

void CameraWindow::on_btCloseClicked()
{
    this->close();
}

void CameraWindow::on_btPicClicked()
{
}