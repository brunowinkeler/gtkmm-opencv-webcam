#if !defined(CAMERA_HANDLER)
#define CAMERA_HANDLER

#include <mutex>
#include <thread>
#include <atomic>

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
        void saveFrame();
        void getData(cv::Mat & frame);

        bool isStopped() const;

    private:

        void initializeCamera(int camera_index);    
        cv::VideoCapture vCap;
        cv::Mat m_lastFrame;
        int cameraIndex = 0;

        std::mutex cameraMutex, imageMutex;

        std::atomic<bool> m_isStopped;
    };
    
} // namespace acquisition


#endif // CAMERA_HANDLER
