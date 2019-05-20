#include "acquisition/camera_widget.h"

namespace acquisition
{
    CameraWidget::CameraWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) : 
        Gtk::DrawingArea(cobject),
        m_builder(refGlade)
    {
    }
    
    CameraWidget::~CameraWidget()
    {
    }

    void CameraWidget::test_showImage()
    {
        
    }
} // namespace acquisition