#if !defined(CAMERA_HANDLER)
#define CAMERA_HANDLER

#include <mutex>
#include <thread>
#include <opencv2/opencv.hpp>


namespace acquisition
{
    class CameraHandler
    {
    public:
        CameraHandler(int camera_index = 0);
        ~CameraHandler();

        cv::Mat getSingleFrame();

    private:
        cv::VideoCapture vCap;
        cv::Mat lastFrame;
        int cameraIndex = 0;

        std::mutex cameraMutex;
    };
    
} // namespace acquisition


#endif // CAMERA_HANDLER
