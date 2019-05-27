#include "acquisition/camera_handler.h"
#include "acquisition/camera_widget.h"

#include "utilities/date_time_utils.h"

namespace acquisition
{
    CameraHandler::CameraHandler(int camera_index)
    {
        m_isStopped = true;
        initializeCamera(camera_index);
    }
    
    CameraHandler::~CameraHandler()
    {
        cameraMutex.lock();
        if(vCap.isOpened())
            vCap.release();
        cameraMutex.unlock();
    }

    void CameraHandler::initializeCamera(int camera_index)
    {
        try
        {
            cameraMutex.lock();
            if(!vCap.isOpened())
            {
                if (vCap.open(camera_index))
                {
                    vCap.set(cv::CAP_PROP_FRAME_WIDTH, 800);
                    vCap.set(cv::CAP_PROP_FRAME_HEIGHT, 600);
                    vCap.set(cv::CAP_PROP_FPS, 30);

                    cameraIndex = camera_index;
                }
                else
                {
                    std::cout << "It was not possible open camera." << std::endl;
                }
                
            }
            cameraMutex.unlock();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void CameraHandler::startStream(CameraWidget * caller)
    {
        if(!vCap.isOpened())
            initializeCamera(cameraIndex);
        
        std::cout << std::this_thread::get_id() << std::endl;

        m_isStopped = false;
        for (size_t i = 0; ;i++)
        {
            cameraMutex.lock();
            if (vCap.isOpened())
                vCap >> m_lastFrame;
            cv::cvtColor(m_lastFrame, m_lastFrame, CV_BGR2RGB);
            cameraMutex.unlock();

            if(m_isStopped)
                break;

            caller->notify();
        }
    }

    void CameraHandler::stopStream()
    {
        m_isStopped = true;

        cameraMutex.lock();
        if(vCap.isOpened())
            vCap.release();
        cameraMutex.unlock();
    }

    void CameraHandler::saveFrame()
    {
        imageMutex.lock();
        std::string date_time_now = utilities::DateTimeUtils::dateTimeToString();
        cv::cvtColor(m_lastFrame, m_lastFrame, CV_BGR2RGB);
        cv::imwrite(date_time_now + ".png", m_lastFrame);
        imageMutex.unlock();
    }

    void CameraHandler::getData(cv::Mat & frame)
    {
        frame = m_lastFrame;
    }
    
    bool CameraHandler::isStopped() const
    {
        return m_isStopped;
    }

} // namespace acquisition
