#include "acquisition/camera_widget.h"

namespace acquisition
{
    CameraWidget::CameraWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) : 
        Gtk::Image(cobject),
        m_builder(refGlade)
    {
        m_cameraHandler = std::make_shared<CameraHandler>();
    }
    
    CameraWidget::~CameraWidget()
    {

    }
    
    void CameraWidget::startCamera()
    {

    }

    void CameraWidget::stopCamera()
    {

    }

    void CameraWidget::pauseCamera()
    {

    }

    void CameraWidget::updateWidget()
    {
        cv::Mat frame = m_cameraHandler->getSingleFrame();

        if (!frame.empty())
        {
            this->set(Gdk::Pixbuf::create_from_data(frame.data, Gdk::COLORSPACE_RGB, false, 8, frame.cols, frame.rows, frame.step)); 
            this->queue_draw();
        }
    }

} // namespace acquisition