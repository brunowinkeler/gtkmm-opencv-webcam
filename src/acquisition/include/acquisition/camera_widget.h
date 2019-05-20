#if !defined(CAMERA_WIDGET_H)
#define CAMERA_WIDGET_H

#include <gtkmm.h>

namespace acquisition
{
    class CameraWidget : public Gtk::DrawingArea
    {
    public:
        CameraWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
        ~CameraWidget();

        void startCamera();
        void pauseCamera();
        void stopCamera();

        void test_showImage();

    private:
        Glib::RefPtr<Gtk::Builder> m_builder;
    };

} // namespace acquisition

#endif // CAMERA_WIDGET_H