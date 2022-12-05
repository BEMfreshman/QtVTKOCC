#ifndef OCCVIEW_H
#define OCCVIEW_H

#include <QVTKOpenGLWidget.h>

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkNamedColors.h>

//#include <AIS_InteractiveContext.hxx>

using std::string;
class OCCDocument;

class OCCView : public QVTKOpenGLWidget
{
    Q_OBJECT
public:
    explicit OCCView(QVTKOpenGLWidget *parent = nullptr);
    ~OCCView() override;

    //[[nodiscard]] const Handle(AIS_InteractiveContext)& getContext() const;

    //virtual QSize minimumSizeHint() const override;

public slots:
    void load(const string& filePath, const string& fileName) ;

    //void fitall(void);

protected:
    //[[nodiscard]] QPaintEngine* paintEngine() const override;

    //void paintEvent(QPaintEvent* ev) override;
    //void resizeEvent(QResizeEvent* ev) override;

    // mouse event
    //virtual void mousePressEvent(QMouseEvent* ev) override;

protected:
    void init(void);
    void updateViewer();

private:
    // Handle(V3d_Viewer) m_v3dviewer;
    // Handle(V3d_View)   m_v3dview;
    // Handle(AIS_InteractiveContext) m_Context;

    OCCDocument* m_OCCDoc;

private:
    vtkNew<vtkNamedColors> m_colors;
    vtkNew<vtkRenderer> m_renderer;
    vtkNew<vtkRenderWindow> m_renderwin;
    vtkNew<vtkRenderWindowInteractor> m_iren;

    vtkNew<vtkActor> m_ugridActor;
private:
    vtkNew<vtkDataSetMapper> m_ugridMapper;

};

#endif // OCCVIEW_H
