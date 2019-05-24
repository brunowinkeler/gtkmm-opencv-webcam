#if !defined(CAMERA_HANDLER)
#define CAMERA_HANDLER

#include <mutex>
#include <thread>
#include <opencv2/opencv.hpp>

namespace acquisition
{
    class CameraWidget;
    class CameraHandler
    {
    public:
        CameraHandler(int camera_index = 0);
        ~CameraHandler();

        void startStream(CameraWidget * caller);
        void stopStream();
        void getData(cv::Mat * frame);

        bool isStopped() const;

    private:    
        cv::VideoCapture vCap;
        cv::Mat m_lastFrame;
        int cameraIndex = 0;

        std::mutex cameraMutex;

        bool m_isStopped = true;
    };
    
} // namespace acquisition


#endif // CAMERA_HANDLER
