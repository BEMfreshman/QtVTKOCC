//#include <OpenGl_GraphicDriver.hxx>
#include "occview.h"
#include <QStyleFactory>
//#include <V3d_View.hxx>

//#include <Aspect_Handle.hxx>
//#include <Aspect_DisplayConnection.hxx>

#include <vtkRenderWindowInteractor.h>

#include "occdocument.h"
#include "PrimitiveInfo.h"

#ifdef WNT
#include <WNT_Window.hxx>
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
#include <Cocoa_Window.hxx>
#else
#undef Bool
#undef CursorShape
#undef None
#undef KeyPress
#undef KeyRelease
#undef FocusIn
#undef FocusOut
#undef FontChange
#undef Expose
#include <Xw_Window.hxx>
#endif

// static Handle(Graphic3d_GraphicDriver)& GetGraphicDriver() {
//     static Handle(Graphic3d_GraphicDriver) aGraphicDriver;
//     return aGraphicDriver;
// }

OCCView::OCCView(QVTKOpenGLWidget *parent)
    : QVTKOpenGLWidget{parent},m_OCCDoc(nullptr)
{
    // setBackgroundRole(QPalette::NoRole);

    // setFocusPolicy(Qt::StrongFocus);
    // setAttribute(Qt::WA_PaintOnScreen);
    // setAttribute(Qt::WA_NoSystemBackground);

    // setMouseTracking(true);

    //init();

    m_OCCDoc = new OCCDocument();
}

OCCView::~OCCView() {
    delete m_OCCDoc;
}

// void OCCView::init() {

//     Handle(Aspect_DisplayConnection) aDisplayConnection =
//             new Aspect_DisplayConnection();

//     if (GetGraphicDriver().IsNull()) {
//         GetGraphicDriver() = new OpenGl_GraphicDriver(aDisplayConnection);
//     }

//     WId window_handle = (WId)winId();

// #ifdef WNT
//     Handle(WNT_Window) wind = new WNT_Window((Aspect_Handle) window_handle);
// #elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
//     Handle(Cocoa_Window) wind = new Cocoa_Window((NSView*) window_handle);
// #else
//     Handle(Xw_Window) wind = new Xw_Window(aDisplayConnection,window_handle);
// #endif

//     m_v3dviewer = new V3d_Viewer(GetGraphicDriver());
//     m_v3dview = m_v3dviewer->CreateView();

//     //Handle(OCCWin) wind = new OCCWin(this);
//     m_v3dview->SetWindow(wind);
//     if (!wind->IsMapped()) wind->Map();

//     m_Context = new AIS_InteractiveContext(m_v3dviewer);

//     m_v3dviewer->SetDefaultLights();
//     m_v3dviewer->SetLightOn();

//     m_v3dview->SetBackgroundColor(Quantity_NOC_BLACK);
//     m_v3dview->MustBeResized();
//     //m_v3dview->TriedronDisplay(Aspect_TOTP_LEFT_LOWER,Quantity_NOC_GOLD,0.08,V3d_ZBUFFER);

//     m_Context->SetDisplayMode(AIS_Shaded,Standard_True);

//     m_OCCDoc = make_shared<OCCDocument>();
// }

// const Handle(AIS_InteractiveContext)& OCCView::getContext() const {
//     return m_Context;
// }

// QPaintEngine* OCCView::paintEngine() const {
//     return 0;
// }

// void OCCView::paintEvent(QPaintEvent *ev) {
//     m_v3dview->Redraw();
// }

// void OCCView::resizeEvent(QResizeEvent* ev) {
//     if (!m_v3dview.IsNull()) {
//         m_v3dview->MustBeResized();
//     }
// }


void OCCView::init() {
    m_renderwin->AddRenderer(m_renderer);
    m_iren->SetRenderWindow(m_renderwin);
}

//void OCCView::fitall() {
//    m_v3dview->FitAll();
//    m_v3dview->ZFitAll();
//    m_v3dview->Redraw();
//}

void OCCView::load(const string &filePath, const string &fileName) {
    m_OCCDoc->load(filePath,fileName);

    const vtkSmartPointer<vtkUnstructuredGrid>& uGrid =
        m_OCCDoc->getpriinfo()->GetuGrid();
    m_ugridMapper->SetInputData(uGrid);

    m_ugridActor->SetMapper(m_ugridMapper);
    m_ugridActor->GetProperty()->SetColor(m_colors->GetColor3d("Peacock").GetData());
    m_ugridActor->GetProperty()->EdgeVisibilityOn();
}



