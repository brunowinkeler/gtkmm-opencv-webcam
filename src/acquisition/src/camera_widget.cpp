#include "acquisition/camera_widget.h"

namespace acquisition
{
    CameraWidget::CameraWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) : 
        Gtk::Image(cobject),
        m_builder(refGlade)
    {
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

    void CameraWidget::takePicture()
    {
        m_cameraHandler.saveFrame();
    }

    void CameraWidget::stopCamera()
    {
        if (!m_workerThread)
        {
            std::cout << "Can't stop a worker thread. None is running." << std::endl;
        }
        else
        {
            // Order the worker thread to stop.
            m_cameraHandler.stopStream();

            // Work is done.
            if (m_workerThread->joinable())
                m_workerThread->join();
            delete m_workerThread;
            m_workerThread = nullptr;
        }
    }

    void CameraWidget::pauseCamera()
    {

    }

    void CameraWidget::updateCameraImageWidget()
    {
        cv::Mat frame;
        m_cameraHandler.getData(frame);

        if (!frame.empty())
        {
            this->set(Gdk::Pixbuf::create_from_data(frame.data, Gdk::COLORSPACE_RGB, false, 8, frame.cols, frame.rows, frame.step)); 
            this->queue_draw();
        }
    }
    
    void CameraWidget::notify()
    {
        m_dispatcher.emit();
    }

    void CameraWidget::on_notificationFromWorkerThread()
    {
        if (m_workerThread && m_cameraHandler.isStopped())
        {
            // Work is done.
            if (m_workerThread->joinable())
                m_workerThread->join();
            delete m_workerThread;
            m_workerThread = nullptr;
        }
        updateCameraImageWidget();
    }

} // namespace acquisition