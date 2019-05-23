#include "acquisition/camera_handler.h"

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

    cv::Mat CameraHandler::getSingleFrame()
    {
        cameraMutex.lock();
        if(vCap.isOpened())
            vCap >> lastFrame;
        cameraMutex.unlock();

        return lastFrame;
    }

} // namespace acquisition
