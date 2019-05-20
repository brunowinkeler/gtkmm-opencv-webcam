#include "acquisition/camera_handler.h"

namespace acquisition
{
    CameraHandler::CameraHandler(int camera_index)
    {
        try
        {
            std::lock_guard<std::mutex> lockCamera(cameraMutex);
            vCap.open(camera_index);
            cameraIndex = camera_index;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    cv::Mat CameraHandler::getSingleFrame()
    {
        std::lock_guard<std::mutex> lockPic(cameraMutex);
        vCap.read(lastFrame);
    }

    CameraHandler::~CameraHandler()
    {
    }
    
} // namespace acquisition
