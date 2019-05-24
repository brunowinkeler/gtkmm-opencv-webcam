#include "acquisition/camera_widget.h"

namespace acquisition
{
    CameraWidget::CameraWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) : 
        Gtk::Image(cobject),
        m_builder(refGlade)
    {
        std::string path_resources = PATH_RESOURCES;
        this->set(path_resources + "imgs/lena.png");

        // Connect the handler to the dispatcher.
        m_dispatcher.connect(sigc::mem_fun(*this, &CameraWidget::on_notificationFromWorkerThread));
    }
    
    CameraWidget::~CameraWidget()
    {

    }
    
    void CameraWidget::startCamera()
    {
        if (m_workerThread)
        {
            std::cout << "Can't start a worker thread while another one is running." << std::endl;
        }
        else
        {
            // Start a new worker thread.
            m_workerThread = new std::thread(
                [this] {
                    m_cameraHandler.startStream(this);
                });
        }
    }

    void CameraWidget::stopCamera()
    {

    }

    void CameraWidget::pauseCamera()
    {

    }

    void CameraWidget::updateWidget()
    {
        //cv::Mat frame = m_cameraHandler.getSingleFrame();

        // if (!frame.empty())
        // {
        //     this->set(Gdk::Pixbuf::create_from_data(frame.data, Gdk::COLORSPACE_RGB, false, 8, frame.cols, frame.rows, frame.step)); 
        //     this->queue_draw();
        // }
    }
    
    void CameraWidget::notify()
    {
        m_dispatcher.emit();
    }

    void CameraWidget::on_notificationFromWorkerThread()
    {

    }

} // namespace acquisition