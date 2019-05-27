#if !defined(CAMERA_WIDGET_H)
#define CAMERA_WIDGET_H

#include <memory>

#include <gtkmm.h>

#include "acquisition/camera_handler.h"

namespace acquisition
{
    class CameraWidget : public Gtk::Image
    {
    public:
        CameraWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
        ~CameraWidget();

        void startCamera();
        void takePicture();
        void pauseCamera();
        void stopCamera();

        bool isPaused();

        void notify();

    private:
        void updateCameraImageWidget();
        void on_notificationFromWorkerThread();

        Glib::RefPtr<Gtk::Builder> m_builder;
        Glib::Dispatcher m_dispatcher;
        std::thread * m_workerThread = nullptr;
        CameraHandler m_cameraHandler;
    };

} // namespace acquisition

#endif // CAMERA_WIDGET_H