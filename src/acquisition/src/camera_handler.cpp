#include "acquisition/camera_handler.h"
#include "acquisition/camera_widget.h"

namespace acquisition
{
    CameraHandler::CameraHandler(int camera_index)
    {
        try
        {
            cameraMutex.lock();
            if(!vCap.isOpened())
            {
                vCap.open(camera_index);
                vCap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
                vCap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
            }
            cameraMutex.unlock();

            cameraIndex = camera_index;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    CameraHandler::~CameraHandler()
    {
        if(vCap.isOpened())
            vCap.release();
    }

    void CameraHandler::startStream(CameraWidget * caller)
    {
        for (size_t i = 0; ;i++)
        {
            cameraMutex.lock();
            if (vCap.isOpened())
                vCap >> m_lastFrame;
            cameraMutex.unlock();

            caller->notify();
        }
    }

    void CameraHandler::stopStream()
    {

    }

    void CameraHandler::getData(cv::Mat * frame)
    {
        *frame = m_lastFrame;
    }
    
    bool CameraHandler::isStopped() const
    {
        return m_isStopped;
    }

} // namespace acquisition
